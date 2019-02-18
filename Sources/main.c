#include "ps.h"
#include <stdio.h>
#include <string.h>

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
	char *str;


	str = NULL;
	str = malloco(1);
	str[0] = '\0';
	sys = init(ac, av);
	clean_input(sys);
//	pa(sys, NULL);
//	pa(sys, NULL);
//	pa(sys, NULL);
//	/pa(sys, NULL);
//	print_sys(sys);
	//rec_start(sys, &str);
	//print_sys(sys);
//	printf("yop\n");

//	m_ab(sys, sys->size, &str);
	//print_sys(sys);
	//printf("final\n");
	//print_sys(sys);;
/*
	printf("str :\n%s\n", str);
	printf("sorted :%d\n", is_sorted(sys));
*/
daman();

}
