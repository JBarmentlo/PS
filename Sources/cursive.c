#include "ps.h"

#include <stdio.h>

void	m_ab(t_system *sys, int size, int iter)
{
//	int i = iter;
//	while (i--)
//		printf("    ");
	a_b(sys, size);
	if (size > 2)
	{
		m_ab(sys, size / 2, iter + 1);
	}
	m_ba(sys, size / 2 + size % 2, iter + 1);
}

void	m_ba(t_system *sys, int size, int iter)
{
//	int i = iter - 1;
//	while (i-- > 0)
//		printf("    ");
	b_a(sys, size);
	if (size / 2 + size % 1 > 1)
		m_ab(sys, size / 2 + size % 2, iter + 1);
	if (size / 2 > 0)
		m_ba(sys, size / 2, iter + 1);

}
