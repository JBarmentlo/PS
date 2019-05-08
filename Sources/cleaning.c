#include "ps.h"

void	set_next(t_system *sys, int value, int iter)
{
	int	i;
	int	crushed;
	int	nxt_index;

	i = -1;
	nxt_index = 0;
	if (iter == sys->size)
		return ;
	while (nxt_index == 0 && i++ + 1 < sys->a->size)
		if (sys->a->array[i] > value)
			nxt_index = i;
	i = -1;
	while (i++ + 1 < sys->a->size)
		if (sys->a->array[i] < sys->a->array[nxt_index]
			&& sys->a->array[i] > value)
			nxt_index = i;
	crushed = sys->a->array[nxt_index];
	sys->a->array[nxt_index] = iter - 2147483648;
	if (iter < sys->size - 1)
		set_next(sys, crushed, iter + 1);
}

void	set_first(t_system *sys)
{
	int	i;
	int	min;
	int	crushed;

	i = 0;
	min = 0;
	while (i++ + 1 < sys->a->size)
	{
		if (sys->a->array[i] < sys->a->array[min])
			min = i;
	}
	crushed = sys->a->array[min];
	sys->a->array[min] = -2147483648;
	set_next(sys, crushed, 1);
}

void	clean_input(t_system *sys)
{
	int	i;

	set_first(sys);
	i = 0;
	while (i < sys->size)
	{
		sys->a->array[i] = sys->a->array[i] + 2147483648;
		i++;
	}
}

int		sorted_till(t_system *sys)
{
	int	i;

	if (sys->a->size == 0)
		return (0);
	i = sys->a->size - 1;
	while (i > -1 && sys->a->array[i] == sys->size + i - sys->a->size)
		i--;
	return (sys->a->size - i - 1);
}
