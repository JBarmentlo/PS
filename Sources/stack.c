
#include "ps.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void		*malloco(size_t size)
{
	void	*out;

	if (!(out = malloc(size)))
	{
		printf("ABORT ABORT\n");
		exit(-1);
	}
	return (out);
}

t_system	*init(char **av)
{
	t_system	*out;
	char		**tab;
	int			i;

	out = (t_system*)malloco(sizeof(t_system));
	tab = ft_strsplit(av[1],' ');
	i = 0;
	while (tab[i] != NULL)
		i++;
	out->size = i;
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
		out->a->array[i] = atoi(tab[i]);
		i++;
	}
	return (out);
}

t_system	*init_old(int ac, char **av)
{
	t_system	*out;
	int			i;

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

t_system	*sys_clone(t_system *sys)
{
	t_system	*out;
	int			i;

	out = (t_system*)malloco(sizeof(t_system));
	out->size = sys->size;
	out->a = (t_stack*)malloco(sizeof(t_stack));
	out->b = (t_stack*)malloco(sizeof(t_stack));
	out->a->array = (int*)malloco(out->size * 4);
	out->b->array = (int*)malloco(out->size * 4);
	out->a->array = out->a->array + sys->size - sys->a->size;
	out->b->array = out->b->array + sys->size - sys->b->size;
	out->a->size = sys->a->size;
	out->b->size = sys->b->size;
	i = 0;
	while (i < sys->size)
	{
		if (i < sys->a->size)
			out->a->array[i] = sys->a->array[i];
		if (i < sys->b->size)
			out->b->array[i] = sys->b->array[i];
		i++;
	}
	return (out);
}

void		sys_free(t_system *sys)
{
	sys->a->array = sys->a->array - sys->size + sys->a->size;
	sys->b->array = sys->b->array - sys->size + sys->b->size;
	free(sys->a->array);
	free(sys->b->array);
	free(sys->a);
	free(sys->b);
	free(sys);
}

void	print_sys(t_system *sys)
{
	int	i;

	i = 0;
	printf(" ________________\n");
	while (i < sys->size)
	{
		if (i >= sys->size - sys->a->size || i >= sys->size - sys->b->size)
		{
			if (i >= sys->size - sys->a->size)
				printf("| %5d |", sys->a->array[sys->a->size - sys->size + i]);
			else
				printf("|       |");
			if (i >= sys->size - sys->b->size)
				printf("| %5d |\n",
					sys->b->array[sys->b->size - sys->size + i]);
			else
				printf("|       |\n");
		}
		i++;
	}
}

t_system	*sys_fake(int size, int a_size, int b_size)
{
	t_system	*out;

	out = (t_system*)malloco(sizeof(*out));
	out->a = (t_stack*)malloco(sizeof(t_stack));
	out->b = (t_stack*)malloco(sizeof(t_stack));
	out->size = size;
	out->a->size = a_size;
	out->b->size = b_size;
	return (out);
}

void	free_sys_fake(t_system *sys)
{
	free(sys->a);
	free(sys->b);
	free(sys);
}
