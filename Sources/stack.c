/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:08 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/15 14:52:12 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

t_s	*init_splice(t_s *out, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (out);
}

t_s		*init(char **av)
{
	t_s			*out;
	char		**tab;
	int			i;

	out = (t_s*)malloco(sizeof(t_s));
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
	return (init_splice(out, tab));
}


t_s		*sys_clone(t_s *sys)
{
	t_s			*out;
	int			i;

	out = (t_s*)malloco(sizeof(t_s));
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

void	sys_free(t_s *sys)
{
	sys->a->array = sys->a->array - sys->size + sys->a->size;
	sys->b->array = sys->b->array - sys->size + sys->b->size;
	free(sys->a->array);
	free(sys->b->array);
	free(sys->a);
	free(sys->b);
	free(sys);
}

void	print_sys(t_s *sys)
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
