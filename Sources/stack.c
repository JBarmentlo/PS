
#include "ps.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void		*malloco(size_t size)
{
	void	*out;

	if (!(out = malloc(size)))
		exit(-1);
	return (out);
}

t_system	*init(int ac, char **av)
{
	t_system	*out;
	int 		i;

	out = (t_system*)malloco(sizeof(t_system));
	out->a = (t_stack*)malloco(sizeof(t_stack));
	out->b = (t_stack*)malloco(sizeof(t_stack));
	out->a->array = (int*)malloco(out->size);
	out->b->array = (int*)malloco(out->size);
	out->size = ac - 1;
	out->a->size = out->size;
	out->b->size = 0;
	i = 0;
	while (i < out->size)
	{
		out->a->array[i] = atoi(av[ac - i - 1]);
		i++;
	}
	return (out);
}

void 	print_sys(t_system *sys)
{
	int	i;

	i = sys->size;
	printf(" ________________\n");
	while (i)
	{
		if (sys->a->size >= i)
			printf("| %5d |", sys->a->array[i - 1]);
		else
			printf("|       |");
		if (sys->b->size >= i)
			printf("| %5d |\n", sys->b->array[i - 1]);
		else
			printf("|       |\n");
		i--;
	}
}
