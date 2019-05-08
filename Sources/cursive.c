/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:07 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/08 16:58:21 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

#include <stdio.h>

void	m_ab(t_system *sys, int size, char **str)
{
	if (sys->a->size - sorted_till(sys) <= 3)
		rec_start(sys, str);
	else
	{
		a_b(sys, size, str);
		if (size > 2)
			m_ab(sys, size / 2, str);
		m_ba(sys, size / 2 + size % 2, str);
	}
}

void	m_ba(t_system *sys, int size, char **str)
{
	b_a(sys, size, str);
	if (size / 2 + size % 2 > 1)
		m_ab(sys, size / 2 + size % 2, str);
	if (size / 2 > 0)
		m_ba(sys, size / 2, str);
}
