/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_hat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:08 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/08 16:58:42 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		get_min(int *arr, int size)
{
	int	out;
	int	i;

	out = arr[0];
	i = 0;
	while (i++ < size)
		if (arr[i] < out)
			out = arr[i];
	return (out);
}

int		count_bigger(int *arr, int size, int value)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	while (i < size)
	{
		if (arr[i] >= value)
			out++;
		i++;
	}
	return (out);
}

int		count_smaller(int *arr, int size, int value)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	while (i < size)
	{
		if (arr[i] <= value)
			out++;
		i++;
	}
	return (out);
}

int		get_median(int *arr, int size)
{
	int	med;
	int	i;

	i = 0;
	med = arr[0];
	while (count_bigger(arr, size, med) != (size / 2 + size % 2))
	{
		i++;
		med = arr[i];
	}
	return (med);
}

int		get_median_s(int *arr, int size)
{
	int	med;
	int	i;

	i = 0;
	med = arr[0];
	while (count_smaller(arr, size, med) != (size / 2 + size % 2))
	{
		i++;
		med = arr[i];
	}
	return (med);
}
