/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:07 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/08 16:58:28 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <stdlib.h>

void	pf_list(t_op_list **start, void (*ff)(t_system*, char**))
{
	t_op_list	*node;

	node = (t_op_list*)malloco(sizeof(t_op_list));
	node->f = (*ff);
	node->next = *start;
	*start = node;
}

void	apply_list(t_op_list **start, t_system *sys, char **str)
{
	t_op_list	*it;
	t_op_list	*tmp;

	it = *start;
	while (it)
	{
		it->f(sys, str);
		tmp = it->next;
		free(it);
		it = tmp;
	}
}
