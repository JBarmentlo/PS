#include "ps.h"

void	pa_plus(t_system *sys, char **str, int *sent)
{
	*sent = *sent + 1;
	pa(sys, str);
}

void	a_b(t_system *sys, int size, char **str)
{
	int	median;
	int	rev_count;
	int	i;
	int	bottom;
	int	sent;

	i = 0;
	sent = 0;
	rev_count = 0;
	bottom = (size == sys->a->size);
	median = get_median_s(sys->a->array, size);
	while (i < size && sent < size / 2 + size % 2)
	{
		if (sys->a->array[0] <= median)
			pa_plus(sys, str, &sent);
		else
		{
			ra(sys, str);
			rev_count++;
		}
		i++;
	}
	while (!bottom && rev_count--)
		rra(sys, str);
}

void	pb_plus(t_system *sys, char **str, int *sent)
{
	*sent = *sent + 1;
	pb(sys, str);
}

void	b_a(t_system *sys, int size, char **str)
{
	int	median;
	int	rev_count;
	int	i;
	int bottom;
	int	sent;

	i = 0;
	sent = 0;
	rev_count = 0;
	bottom = (size == sys->b->size);
	median = get_median(sys->b->array, size);
	while (i < size && sent < size / 2 + size % 2)
	{
		if (sys->b->array[0] >= median)
			pb_plus(sys, str, &sent);
		else
		{
			rb(sys, str);
			rev_count++;
		}
		i++;
	}
	while (!bottom && rev_count--)
		rrb(sys, str);
}
