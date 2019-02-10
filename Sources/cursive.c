#include "ps.h"

#include <stdio.h>

void	m_ab(t_system *sys, int size)
{
	a_b(sys, size);
	if (size > 2)
	{
		m_ab(sys, size / 2);
	}
	m_ba(sys, size / 2 + size % 2);
}

void	m_ba(t_system *sys, int size)
{
	b_a(sys, size);
	if (size / 2 + size % 1 > 1)
		m_ab(sys, size / 2 + size % 2);
	if (size / 2 > 0)
		m_ba(sys, size / 2 + size % 2);

}
