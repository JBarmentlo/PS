#include "ps.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_system *sys;

	sys = init(ac, av);
	//get_median(sys->a->array, sys->a->size);
	int i = 0;
	while (sys->a->size != 0)
	{
		printf("i  :%d\n", i);
			push_half(sys);
			printf("oy\n");
			print_sys(sys);
			i++;
	}

}
