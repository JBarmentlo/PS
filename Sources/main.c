#include "ps.h"
#include <stdio.h>

int	is_sorted(t_system *sys)
{
	int	i;

	if (sys->size != sys->a->size)
		return (0);
	i = 0;
	while (i + 1 < sys->size) //SEGFAULT !!??
	{
		if (sys->a->array[i] > sys->a->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_system *sys;

	sys = init(ac, av);
	//print_sys(sys);
	clean_input(sys);
	//print_sys(sys);
	m_ab_first(sys, sys->size);
	//print_sys(sys);
	printf("sorted :%d\n", is_sorted(sys));
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
