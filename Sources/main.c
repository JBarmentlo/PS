#include "ps.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_system *sys;

	sys = init(ac, av);
	//print_sys(sys);
	m_ab(sys, sys->size, 0);
	//print_sys(sys);
/*
		print_sys(sys);
		printf("a_b 8\n");
	a_b(sys, 8);
		print_sys(sys);
		printf("a_b 4\n");
	a_b(sys, 4);
		print_sys(sys);
		printf("a_b 2\n");
	a_b(sys, 2);
		print_sys(sys);
		printf("b_a 2\n");
	b_a(sys, 1);
		print_sys(sys);
		printf("b_a 4\n");
	b_a(sys, 2);
		print_sys(sys);
		printf("b_a 1\n");
	b_a(sys, 1);
		print_sys(sys);
		printf("b_a 4\n");
	b_a(sys, 4);
		print_sys(sys);
		printf("a_b 2\n");
	a_b(sys, 2);
		print_sys(sys);
		printf("b_a 1\n");
	b_a(sys, 1);
		print_sys(sys);
		printf("b_a 2\n");
	b_a(sys, 2);
		print_sys(sys);
		printf("b_a 1\n");
	b_a(sys, 1);
		print_sys(sys);
		printf("\n");
*/
}
