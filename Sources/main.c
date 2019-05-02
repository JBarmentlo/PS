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
 
	t_system	*sys;
	char		*str;
	t_end_list	*start;

	start = NULL;
	str = NULL;
	str = malloco(1);
	str[0] = '\0';
	sys = init(ac, av);
	clean_input(sys);

	m_ab(sys, sys->size, &str);
	printf("ptt:%p\n", &start);
	//str_to_list(&start, str);
	//print_list(&start);
	//printf("lst_size %d\n", count_end_list(&start));
	printf("str :\n%s\n", str);
	printf("sorted :%d\n", is_sorted(sys));

}
