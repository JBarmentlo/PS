/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:08 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/15 13:19:15 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <stdlib.h>

void	ss(t_s *sys, t_end_list **start)
{
	sa(sys, start);
	sb(sys, start);
}

void	rr(t_s *sys, t_end_list **start)
{
	ra(sys, start);
	rb(sys, start);
}

void	rrr(t_s *sys, t_end_list **start)
{
	rra(sys, start);
	rrb(sys, start);
}

t_s		*sys_fake(int size, int a_size, int b_size)
{
	t_s	*out;

	out = (t_s*)malloco(sizeof(*out));
	out->a = (t_stack*)malloco(sizeof(t_stack));
	out->b = (t_stack*)malloco(sizeof(t_stack));
	out->size = size;
	out->a->size = a_size;
	out->b->size = b_size;
	return (out);
}

void	free_sys_fake(t_s *sys)
{
	free(sys->a);
	free(sys->b);
	free(sys);
}
