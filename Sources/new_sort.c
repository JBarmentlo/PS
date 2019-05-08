/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:07 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/08 17:25:29 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <stdio.h>

int		recrra(t_s *sys, t_s *og, t_op_list **start, int it)
{
	if (sys->a->size < 2)
		return (0);
	rra(sys, NULL);
	if (sorted_till(sys) == og->a->size)
	{
		pf_list(start, &rra);
		return (1);
	}
	if (it == og->size)
	{
		ra(sys, NULL);
		return (0);
	}
	if (recsb(sys, og, start, it + 1) || recpb(sys, og, start, it + 1) ||
		recpa(sys, og, start, it + 1) || recrra(sys, og, start, it + 1) ||
		recrrb(sys, og, start, it + 1) || recrb(sys, og, start, it + 1) ||
		recsa(sys, og, start, it + 1))
	{
		pf_list(start, &rra);
		return (1);
	}
	ra(sys, NULL);
	return (0);
}

int		recrb(t_s *sys, t_s *og, t_op_list **start, int it)
{
	if (sys->b->size < 2)
		return (0);
	rb(sys, NULL);
	if (sorted_till(sys) == og->a->size)
	{
		pf_list(start, &rb);
		return (1);
	}
	if (it == og->size)
	{
		rrb(sys, NULL);
		return (0);
	}
	if (recsb(sys, og, start, it + 1) || recpb(sys, og, start, it + 1) ||
		recpa(sys, og, start, it + 1) || recra(sys, og, start, it + 1) ||
		recrb(sys, og, start, it + 1) || recrra(sys, og, start, it + 1) ||
		recrrb(sys, og, start, it + 1))
	{
		pf_list(start, &rb);
		return (1);
	}
	rrb(sys, NULL);
	return (0);
}

int		recrrb(t_s *sys, t_s *og, t_op_list **start, int it)
{
	if (sys->b->size < 2)
		return (0);
	rrb(sys, NULL);
	if (sorted_till(sys) == og->a->size)
	{
		pf_list(start, &rrb);
		return (1);
	}
	if (it == og->size)
	{
		rb(sys, NULL);
		return (0);
	}
	if (recsb(sys, og, start, it + 1) || recpb(sys, og, start, it + 1) ||
		recpa(sys, og, start, it + 1) || recrra(sys, og, start, it + 1) ||
		recra(sys, og, start, it + 1) || recrrb(sys, og, start, it + 1) ||
		recsa(sys, og, start, it + 1))
	{
		pf_list(start, &rrb);
		return (1);
	}
	rb(sys, NULL);
	return (0);
}

void	rev_print(char *str)
{
	int i;

	i = strlen(str);
	while (i--)
		printf("%c", str[i]);
}

void	rec_start(t_s *syst, char **str)
{
	t_s			*sys;
	t_s			*fake;
	t_op_list	*start;
	int			bool;

	bool = 0;
	start = NULL;
	sys = sys_clone(syst);
	fake = sys_fake(0, sys->a->size, sys->b->size);
	if (sorted_till(sys) == sys->a->size)
		return ;
	while (bool == 0)
	{
		bool = recsa(sys, fake, &start, 0);
		if (bool == 0)
			bool = recpa(sys, fake, &start, 0);
		if (bool == 0)
			bool = recra(sys, fake, &start, 0);
		fake->size++;
	}
	apply_list(&start, syst, str);
	sys_free(sys);
	free_sys_fake(fake);
}
