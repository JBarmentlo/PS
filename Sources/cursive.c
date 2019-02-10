#include "ps.h"

#include <stdio.h>

void	m_ab(t_system *sys, int size, int iter)
{

	a_b(sys, size);
	if (size > 2)
	{
		m_ab(sys, size / 2, iter + 1);
	}
	m_ba(sys, size / 2 + size % 2, iter + 1);
}

void	m_ba(t_system *sys, int size, int iter)
{
	b_a(sys, size);
	if (size / 2 + size % 1 > 1)
		m_ab(sys, size / 2 + size % 2, iter + 1);
	if (size / 2 > 0)
		m_ba(sys, size / 2, iter + 1);

}

/*
ecrire une dichotomie pour trouver a quel point cest range pour
pour identifier le cas n = 3

keep nearly sorted chunks;
*/
