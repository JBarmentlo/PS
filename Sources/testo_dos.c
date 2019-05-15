/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testo_dos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:13:35 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/15 15:13:03 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		sorted_till(t_s *sys)
{
	int	i;

	if (sys->a->size == 0)
		return (0);
	i = sys->a->size - 1;
	while (i > -1 && sys->a->array[i] == sys->size + i - sys->a->size)
		i--;
	return (sys->a->size - i - 1);
}
