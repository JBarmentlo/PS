#include "ps.h"

#include <stdio.h>

void	m_ab(t_system *sys, int size, int iter)
{
//	printf("size%d\n", sys->a->size);
//	print_sys(sys);
//	printf("sorted_till :%d\n", sorted_till(sys));
	if (sys->a->size - sorted_till(sys) <= 3)
		sort_three(sys);
	else
	{
		a_b(sys, size);
		if (size > 2)
			m_ab(sys, size / 2, iter + 1);
		m_ba(sys, size / 2 + size % 2, iter + 1);
	}
}

void	m_ba(t_system *sys, int size, int iter)
{
	b_a(sys, size);
	if (size / 2 + size % 2 > 1)
		m_ab(sys, size / 2 + size % 2, iter + 1);
	if (size / 2 > 0)
		m_ba(sys, size / 2, iter + 1);
}

void	m_ab_first(t_system *sys, int size)
{
	if (sys->a->size - sorted_till(sys) <= 3)
		sort_three(sys);
	else
	{
		a_b_first(sys, size);
		if (size > 2)
			m_ab_first(sys, size / 2);
		m_ba(sys, size / 2 + size % 2, 0);
	}
}
/*
ecrire une dichotomie pour trouver a quel point cest range pour
pour identifier le cas n = 3

keep nearly sorted chunks;
*/
