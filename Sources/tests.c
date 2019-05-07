#include "ps.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	only_digits(char **av)
{
	int	fuck;
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		fuck = 0;
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' && fuck == 0)
			{
				j++;
				fuck = 1;
			}
			if (!(av[i][j] <= 57 && av[i][j] >= 48))
				error();
			j++;
		}
		i++;
	}
}

int		int_maxou_two(char *str)
{
	if (str[5] < '8')
		return (0);
	if (str[6] > '3')
		return (1);
	if (str[6] < '3')
		return (0);
	if (str[7] > '6')
		return (1);
	if (str[7] < '6')
		return (0);
	if (str[8] > '4')
		return (1);
	if (str[8] < '4')
		return (0);
	if (str[9] > '7')
		return (1);
	if (str[9] < '7')
		return (0);
	return (0);
}

int		minus_maxou(char *str)
{
	int	out;

	str++;
	if (str[9] == '8')
	{
		str[9] = '7';
		out = int_maxou(str);
		str[9] = '8';
	}
	else
	{
		out = int_maxou(str);
	}
	return (out);
}
#include <stdio.h>
int		int_maxou(char *str)
{
	if (str[0] == '-')
		return (minus_maxou(str));
	if (str[0] < '2')
		return (0);
	if (str[0] > '2')
		return (1);
	if (str[1] < '1')
		return (0);
	if (str[1] > '1')
		return (1);
	if (str[2] > '4')
		return (1);
	if (str[2] < '4')
		return (0);
	if (str[3] < '7')
		return (0);
	if (str[3] > '7')
		return (1);
	if (str[4] < '4')
		return (0);
	if (str[4] > '4')
		return (1);
	if (str[5] > '8')
		return (1);
	return (int_maxou_two(str));
}

void	is_super_walid(char **tab)
{
	int	i;

	i = 0;
	only_digits(tab);
	while (tab[i])
	{
		if (i == 2147483647)
			error();
		if (ft_strlen(tab[i]) - tab[i][0] == '-' > 10)
			error();
		if ((ft_strlen(tab[i]) - (tab[i][0] == '-')) == 10)
			if (int_maxou(tab[i]))
				error();
		i++;
	}

}

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
