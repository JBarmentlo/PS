/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:08 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/08 17:07:57 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

t_system	*init(char **av)
{
	t_system	*out;
	char		**tab;
	int			i;

	out = (t_system*)malloco(sizeof(t_system));
	tab = ft_strsplit(av[1], ' ');
	is_super_walid(tab);
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

void		print_sys(t_system *sys)
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
