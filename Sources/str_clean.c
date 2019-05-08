/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:09 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/08 17:07:06 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ps.h"
#include "libft.h"
#include <stdlib.h>

int			neutralise(t_op one, t_op two, int repeat)
{
	if (one == &pa && two == &pb)
		return (1);
	if (one == &ra && two == &rra)
		return (1);
	if (one == &rb && two == &rrb)
		return (1);
	if (repeat)
		return (neutralise(two, one, 0));
	return (0);
}

t_end_list	*triple(t_end_list **start, t_end_list *a,
	t_end_list *b, t_end_list *c)
{
	if (!c)
		return (a);
	if (a->op == &ra && b->op == &pa && c->op == &rra)
	{
		a->op = &sa;
		b->op = &pa;
		rm_elem(start, c);
		if (a->prev)
			return (a->prev);
		else
			return (a);
	}
	if (a->op == &rb && b->op == &pb && c->op == &rrb)
	{
		a->op = &sb;
		b->op = &pb;
		rm_elem(start, c);
		if (a->prev)
			return (a->prev);
		else
			return (a);
	}
	return (a);
}

t_end_list	*doble_dos(t_end_list **start, t_end_list *a, t_end_list *b)
{
	if (a->op == &rra && b->op == &rrb)
	{
		a->op = &rrr;
		rm_elem(start, b);
		if (a->prev)
			return (a->prev);
		else
			return (a);
	}
	if (a->op == &rrb && b->op == &rra)
	{
		a->op = &rrr;
		rm_elem(start, b);
		if (a->prev)
			return (a->prev);
		else
			return (a);
	}
	return (a);
}

t_end_list	*doble_zer(t_end_list **start, t_end_list *a, t_end_list *b)
{
	t_end_list	*tmp;

	tmp = a->prev;
	if ((a->op == &pa && b->op == &pb)
		|| (a->op == &pb && b->op == &pa)
			|| (a->op == &ra && b->op == &rra)
				|| (a->op == &rb && b->op == &rrb))
	{
		rm_elem(start, a);
		rm_elem(start, b);
		if (tmp)
			return (tmp);
		return (*start);
	}
	return (a);
}

void		simplify(t_end_list **start)
{
	t_end_list	*it;
	t_end_list	*tmp;

	if (*start == NULL)
		return ;
	it = *start;
	while (it && it->next)
	{
		it = triple(start, it, it->next, it->next->next);
		it = doble_dos(start, it, it->next);
		it = doble_zer(start, it, it->next);
		if (neutralise(it->op, it->next->op, 1))
		{
			tmp = it->prev;
			rm_elem(start, it->next);
			rm_elem(start, it);
			if (tmp)
				it = tmp;
			else
				it = *start;
		}
		else
			it = it->next;
	}
}
