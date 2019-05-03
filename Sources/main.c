#include "ps.h"
#include <stdio.h>
#include <string.h>

int	is_sorted(t_system *sys)
{
	int	i;

	if (sys->size != sys->a->size)
		return (0);
	i = 0;
	while (i + 1 < sys->size)
	{
		if (sys->a->array[i] > sys->a->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_walid(t_system *sys)
{
	int	i;
	int	j;

	i = 0;
	while (i < sys->size)
	{
		j = i + 1;
		while (j < sys->size)
		{
			if (sys->a->array[i] == sys->a->array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_system	*sys;
	char		*str;
	t_end_list	*start;

	start = NULL;
	str = NULL;
	str = malloco(1);
	str[0] = '\0';
	sys = init(ac, av);
	if (!is_walid(sys))
		return (-1);
	clean_input(sys);
	m_ab(sys, sys->size, &str);
	str_to_list(&start, str);
	simplify(&start);
	print_list(&start);
}
