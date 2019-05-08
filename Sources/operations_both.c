/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:08 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/08 17:06:47 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <stdlib.h>

void		ss(t_system *sys, char **str)
{
	sa(sys, str);
	sb(sys, str);
}

void		rr(t_system *sys, char **str)
{
	ra(sys, str);
	rb(sys, str);
}

void		rrr(t_system *sys, char **str)
{
	rra(sys, str);
	rrb(sys, str);
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

void		free_sys_fake(t_system *sys)
{
	free(sys->a);
	free(sys->b);
	free(sys);
}
