
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
	out->size = ac - 1;
	out->a = (t_stack*)malloco(sizeof(t_stack));
	out->b = (t_stack*)malloco(sizeof(t_stack));
	out->a->array = (int*)malloco(out->size * 4);
	out->b->array = (int*)malloco(out->size * 4);
	out->b->array = out->b->array + out->size;
	out->a->size = out->size;
	out->b->size = 0;
	i = 0;
	while (i < out->size)
	{
		out->a->array[i] = atoi(av[i + 1]);
		i++;
	}
	return (out);
}

void 	print_sys(t_system *sys)
{
	int	i;

	i = 0;
	printf(" ________________\n");
	while (i < sys->size)
	{
		if (i >= sys->size - sys->a->size)
			printf("| %5d |", sys->a->array[sys->a->size - sys->size + i]);
		else
			printf("|       |");
		if (i >= sys->size - sys->b->size)
			printf("| %5d |\n", sys->b->array[sys->b->size - sys->size + i]);
		else
			printf("|       |\n");
		i++;
	}
}
