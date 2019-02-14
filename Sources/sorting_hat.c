#include "ps.h"

int	get_min(int *arr, int size)
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

int	count_bigger(int *arr, int size, int value)
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

int	count_smaller(int *arr, int size, int value)
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

#include <stdio.h>
int	get_median(int *arr, int size)
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

int	get_median_s(int *arr, int size)
{
	int	med;
	int	i;

	i = 0;
	med = arr[0];
	while (count_smaller(arr, size, med)!= (size / 2 + size % 2))
	{
		i++;
		med = arr[i];
	}
	return (med);
}
/*
void	push_half(t_system *sys)
{
	int	median;
	int	i;
	int	size;

	i = 0;
	size = sys->a->size;
	median = get_median(sys->a->array, size);
	while (i <= size)
	{
		if (sys->a->array[0] >= median)
			pa(sys);
		else
			ra(sys);
		i++;
	}
}
*/
void	a_b(t_system *sys, int size, char **str)
{
	int	median;
	int	rev_count;
	int	i;
	int	bottom;


	i = 0;
	rev_count = 0;
	bottom = (size == sys->a->size);
	median = get_median_s(sys->a->array, size);
	while (i < size)
	{
		if (sys->a->array[0] <= median)
			pa(sys, str);
		else
		{
			ra(sys, str);
			rev_count++;
		}
		i++;
	}
	while (!bottom && rev_count--)
		rra(sys, str);
//	print_sys(sys);
//	printf("\n\n");
}

void	b_a(t_system *sys, int size, char **str)
{
	int	median;
	int	rev_count;
	int	i;
	int bottom;

	i = 0;
	rev_count = 0;
	bottom = (size == sys->b->size);
	median = get_median(sys->b->array, size);
	while (i < size)
	{
		if (sys->b->array[0] >= median)
			pb(sys, str);
		else
		{
			rb(sys, str);
			rev_count++;
		}
		i++;
	}
	while (!bottom && rev_count--)
		rrb(sys, str);

//	print_sys(sys);
//	printf("\n\n");

}

void	a_b_first(t_system *sys, int size, char **str)
{
	int	median;
	int	i;

	i = 0;
	median = get_median_s(sys->a->array, size);
	while (i < size)
	{
		if (sys->a->array[0] <= median)
			pa(sys, str);
		else
			ra(sys, str);
		i++;
	}
//	printf("a_b(%d)\n\n", size);
//	print_sys(sys);
//	printf("sorted_till :%d\n", sorted_till(sys));
}
