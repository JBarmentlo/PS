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
	//print_sys(sys);
	clean_input(sys);
	rec_start(sys, &str, 5);
	//m_ab(sys, sys->size, &str);
	print_sys(sys);

	//new_sort(sys, &str);
	//print_sys(sys);

/*
	int	clean;
	clean = 0;
	while (!clean)
	{
		clean = clean_str(str);
	}
*/
	printf("%s", str);
//	printf("sorted :%d\n", is_sorted(sys));
//	print_sys(sys);

	/*

	    str = strdup("01\n34\n67\n89\n");
		printf("%s", str);
		str_rm_part(str, 3, 6);
	*/
}
