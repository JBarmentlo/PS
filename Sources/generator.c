#include "ps.h"
#include <sdtio.h>
#include <stdlib.h>

static int	tab_check(char **tab)
{
	int	i;
	int	j;

	i = 6;
	while (i < 11)
	{
		j = i + 1;
		while (j < 12)
		{
			if (atoi(av[j]) == atoi(av[i])
				return (0);
			j++;
		}
		i++
	}
	return (1);
}

void		daman(void)
{
	char	**tab;

	tab[0] = 3;
	tab[1] = 0;
	tab[2] = 6;
	tab[3] = 2;
	tab[4] = 1;
	tab[5] = 5;
}

t_system	*next_sys(t_system *sys)
{

}

fopen("trees/0123", "ab+");

t_system *sys;
char *str;


str = NULL;
str = malloco(1);
str[0] = '\0';
sys = init(ac, av);
clean_input(sys);
pa(sys, NULL);
pa(sys, NULL);
pa(sys, NULL);
pa(sys, NULL);
print_sys(sys);
rec_start(sys, &str);
printf("yop\n");
//m_ab(sys, sys->size, &str);
//print_sys(sys);
//printf("final\n");
print_sys(sys);
