#include "ps.h"

#include <stdio.h>
void	sort_three(t_system *sys, char **str)
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
			pa(sys, str);
			if (a[1] - offset == 2)
				sa(sys, str);
			pb(sys, str);
		}
	}
	else if (a[1] - offset == 0)
	{
		sa(sys, str);
		sort_three(sys, str);
	}
	else if (a[2] - offset == 0)
	{
		if (a[1] - offset == 2)
		{
			pa(sys, str);
			sa(sys, str);
			pb(sys, str);
			sa(sys, str);
		}
		else if (a[1] - offset == 1)
		{
			sa(sys, str);
			pa(sys, str);
			sa(sys, str);
			pb(sys, str);
			sa(sys, str);
		}
	}
//	print_sys(sys);
}
/*
void	sort_four(t_system *sys, char **str)
{

}
*/
