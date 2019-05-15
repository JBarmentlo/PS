/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_hat_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:08 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/15 13:31:19 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	pa_plus(t_s *sys, t_end_list **start, int *sent)
{
	*sent = *sent + 1;
	pa(sys, start);
}

void	a_b(t_s *sys, int size, t_end_list **start)
{
	int	median;
	int	rev_count;
	int	i;
	int	bottom;
	int	sent;

	i = 0;
	sent = 0;
	rev_count = 0;
	bottom = (size == sys->a->size);
	median = get_median_s(sys->a->array, size);
	while (i < size && sent < size / 2 + size % 2)
	{
		if (sys->a->array[0] <= median)
			pa_plus(sys, start, &sent);
		else
		{
			ra(sys, start);
			rev_count++;
		}
		i++;
	}
	while (!bottom && rev_count--)
		rra(sys, start);
}

void	pb_plus(t_s *sys, t_end_list **start, int *sent)
{
	*sent = *sent + 1;
	pb(sys, start);
}

void	b_a(t_s *sys, int size, t_end_list **start)
{
	int	median;
	int	rev_count;
	int	i;
	int bottom;
	int	sent;

	i = 0;
	sent = 0;
	rev_count = 0;
	bottom = (size == sys->b->size);
	median = get_median(sys->b->array, size);
	while (i < size && sent < size / 2 + size % 2)
	{
		if (sys->b->array[0] >= median)
			pb_plus(sys, start, &sent);
		else
		{
			rb(sys, start);
			rev_count++;
		}
		i++;
	}
	while (!bottom && rev_count--)
		rrb(sys, start);
}
