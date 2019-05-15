/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:08 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/15 13:25:39 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sb(t_s *sys, t_end_list **start)
{
	int	*arr;
	int	tmp;

	arr = sys->b->array;
	if (sys->b->size < 2)
		return ;
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
	if (start)
		add_new_to_list(start, &sb);
}

void	pb(t_s *sys, t_end_list **start)
{
	t_stack	*a;
	t_stack	*b;

	a = sys->a;
	b = sys->b;
	if (b->size == 0)
		return ;
	a->array--;
	a->array[0] = b->array[0];
	b->array++;
	a->size++;
	b->size--;
	if (start)
		add_new_to_list(start, &pb);
}

void	rrb(t_s *sys, t_end_list **start)
{
	t_stack *b;
	int		i;
	int		tmp;

	b = sys->b;
	i = b->size - 1;
	if (b->size <= 1)
		return ;
	tmp = b->array[i];
	while (i)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = tmp;
	if (start)
		add_new_to_list(start, &rrb);
}

void	rb(t_s *sys, t_end_list **start)
{
	t_stack *b;
	int		i;
	int		tmp;

	b = sys->b;
	i = 0;
	if (b->size <= 1)
		return ;
	tmp = b->array[i];
	while (i + 1 < b->size)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->array[i] = tmp;
	if (start)
		add_new_to_list(start, &rb);
}
