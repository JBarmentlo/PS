#include "ps.h"

#include <stdio.h>
void	sort_three(t_system *sys)
{
	int	*a;
	int	offset; //EXCEPTIONIF SIZE = 3 USE RA RRA

//	print_sys(sys);
//	printf("size%d\n", sys->a->size);
//	printf("sorted_till :%d\n", sorted_till(sys));
	offset = sys->size - sys->a->size;
	a = sys->a->array;
	if (a[0] - offset == 0)
	{
		if (a[1] - offset != 1)
		{
			pa(sys);
			if (a[1] - offset == 2)
				sa(sys);
			pb(sys);
		}
	}
	else if (a[1] - offset == 0)
	{
		sa(sys);
		sort_three(sys);
	}
	else if (a[2] - offset == 0)
	{
		if (a[1] - offset == 2)
		{
			pa(sys);
			sa(sys);
			pb(sys);
			sa(sys);
		}
		else if (a[1] - offset == 1)
		{
			sa(sys);
			pa(sys);
			sa(sys);
			pb(sys);
			sa(sys);
		}
	}
//	print_sys(sys);
}
