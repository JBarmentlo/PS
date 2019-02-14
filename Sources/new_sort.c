#include "ps.h"
#include <stdio.h>

int		recpa(t_system *sys, t_op_list **start, int it_max, int it);
int		recpb(t_system *sys, t_op_list **start, int it_max, int it);
int		recsa(t_system *sys, t_op_list **start, int it_max, int it);
int		recsb(t_system *sys, t_op_list **start, int it_max, int it);
int		recrb(t_system *sys, t_op_list **start, int it_max, int it);
int		recrrb(t_system *sys, t_op_list **start, int it_max, int it);
int		recra(t_system *sys, t_op_list **start, int it_max, int it);
int		recrra(t_system *sys, t_op_list **start, int it_max, int it);

int		recpa(t_system *sys, t_op_list **start, int it_max, int it)
{
//	printf("recpa\n");
	if (sys->a->size < 1)
		return (0);
	pa(sys, NULL);
	if (sorted_till(sys) == sys->size)
	{
		pf_list(start, &pa);
		return (it);
	}
	if (it == it_max)
	{
		pb(sys, NULL);
		return (0);
	}
	if (recsa(sys, start, it_max, it + 1))
	{
		pf_list(start, &pa);
		return (1);
	}
	if (recsb(sys, start, it_max, it + 1))
	{
		pf_list(start, &pa);
		return (1);
	}
	if (recpa(sys, start, it_max, it + 1))
	{
		pf_list(start, &pa);
		return (1);
	}
	if (recra(sys, start, it_max, it + 1))
	{
		pf_list(start, &pa);
		return (1);
	}
	if (recrra(sys, start, it_max, it + 1))
	{
		pf_list(start, &pa);
		return (1);
	}
	if (recrrb(sys, start, it_max, it + 1))
	{
		pf_list(start, &pa);
		return (1);
	}
	if (recrb(sys, start, it_max, it + 1))
	{
		pf_list(start, &pa);
		return (1);
	}
	pb(sys, NULL);
	return (0);
}

int		recpb(t_system *sys, t_op_list **start, int it_max, int it)
{
//	printf("recpb\n");
	if (sys->b->size < 1)
		return (0);
	pb(sys, NULL);
	if (sorted_till(sys) == sys->size)
	{
		pf_list(start, &pb);
		return (1);
	}
	if (it == it_max)
	{
		pa(sys, NULL);
		return (0);
	}
	if (recpb(sys, start, it_max, it + 1))
	{
		pf_list(start, &pb);
		return (1);
	}
	if (recsa(sys, start, it_max, it + 1))
	{
		pf_list(start, &pb);
		return (1);
	}
	if (recsb(sys, start, it_max, it + 1))
	{
		pf_list(start, &pb);
		return (1);
	}
	if (recra(sys, start, it_max, it + 1))
	{
		pf_list(start, &pb);
		return (1);
	}
	if (recrra(sys, start, it_max, it + 1))
	{
		pf_list(start, &pb);
		return (1);
	}
	if (recrrb(sys, start, it_max, it + 1))
	{
		pf_list(start, &pb);
		return (1);
	}
	if (recrb(sys, start, it_max, it + 1))
	{
		pf_list(start, &pb);
		return (1);
	}
	pa(sys, NULL);
	return (0);
}

int		recsb(t_system *sys, t_op_list **start, int it_max, int it)
{
//	printf("recsb\n");
	if (sys->b->size < 2)
		return (0);
	sb(sys, NULL);
	if (sorted_till(sys) == sys->size)
	{
		pf_list(start, &sb);
		return (1);
	}
	if (it == it_max)
	{
		sb(sys, NULL);
		return (0);
	}
	if (recsa(sys, start, it_max, it + 1))
	{
		pf_list(start, &sb);
		return (1);
	}
	if (recpb(sys, start, it_max, it + 1))
	{
		pf_list(start, &sb);
		return (1);
	}
	if (recpa(sys, start, it_max, it + 1))
	{
		pf_list(start, &sb);
		return (1);
	}
	if (recra(sys, start, it_max, it + 1))
	{
		pf_list(start, &sb);
		return (1);
	}
	if (recrra(sys, start, it_max, it + 1))
	{
		pf_list(start, &sb);
		return (1);
	}
	if (recrrb(sys, start, it_max, it + 1))
	{
		pf_list(start, &sb);
		return (1);
	}
	if (recrb(sys, start, it_max, it + 1))
	{
		pf_list(start, &sb);
		return (1);
	}
	sb(sys, NULL);
	return (0);
}

int		recsa(t_system *sys, t_op_list **start, int it_max, int it)
{
//	printf("recsa\n");
	if (sys->a->size < 2)
		return (0);
	sa(sys, NULL);
	if (sorted_till(sys) == sys->size)
	{
		pf_list(start, &sa);
		return (1);
	}
	if (it == it_max)
	{
		sa(sys, NULL);
		return (0);
	}
	if (recsb(sys, start, it_max, it + 1))
	{
		pf_list(start, &sa);
		return (1);
	}
	if (recpb(sys, start, it_max, it + 1))
	{
		pf_list(start, &sa);
		return (1);
	}
	if (recpa(sys, start, it_max, it + 1))
	{
		pf_list(start, &sa);
		return (1);
	}
	if (recra(sys, start, it_max, it + 1))
	{
		pf_list(start, &sa);
		return (1);
	}
	if (recrra(sys, start, it_max, it + 1))
	{
		pf_list(start, &sa);
		return (1);
	}
	if (recrrb(sys, start, it_max, it + 1))
	{
		pf_list(start, &sa);
		return (1);
	}
	if (recrb(sys, start, it_max, it + 1))
	{
		pf_list(start, &sa);
		return (1);
	}
	sa(sys, NULL);
	return (0);
}

int		recra(t_system *sys, t_op_list **start, int it_max, int it)
{
	if (sys->a->size < 2)
		return (0);
	ra(sys, NULL);
	if (sorted_till(sys) == sys->size)
	{
		pf_list(start, &ra);
		return (1);
	}
	if (it == it_max)
	{
		rra(sys, NULL);
		return (0);
	}
	if (recsb(sys, start, it_max, it + 1))
	{
		pf_list(start, &ra);
		return (1);
	}
	if (recpb(sys, start, it_max, it + 1))
	{
		pf_list(start, &ra);
		return (1);
	}
	if (recpa(sys, start, it_max, it + 1))
	{
		pf_list(start, &ra);
		return (1);
	}
	if (recra(sys, start, it_max, it + 1))
	{
		pf_list(start, &ra);
		return (1);
	}
	if (recrrb(sys, start, it_max, it + 1))
	{
		pf_list(start, &ra);
		return (1);
	}
	if (recrb(sys, start, it_max, it + 1))
	{
		pf_list(start, &ra);
		return (1);
	}
	rra(sys, NULL);
	return (0);
}

int		recrra(t_system *sys, t_op_list **start, int it_max, int it)
{
//	printf("recsa\n");
	if (sys->a->size < 2)
		return (0);
	rra(sys, NULL);
	if (sorted_till(sys) == sys->size)
	{
		pf_list(start, &rra);
		return (1);
	}
	if (it == it_max)
	{
		ra(sys, NULL);
		return (0);
	}
	if (recsb(sys, start, it_max, it + 1))
	{
		pf_list(start, &rra);
		return (1);
	}
	if (recpb(sys, start, it_max, it + 1))
	{
		pf_list(start, &rra);
		return (1);
	}
	if (recpa(sys, start, it_max, it + 1))
	{
		pf_list(start, &rra);
		return (1);
	}
	if (recrra(sys, start, it_max, it + 1))
	{
		pf_list(start, &rra);
		return (1);
	}
	if (recrrb(sys, start, it_max, it + 1))
	{
		pf_list(start, &rra);
		return (1);
	}
	if (recrb(sys, start, it_max, it + 1))
	{
		pf_list(start, &rra);
		return (1);
	}
	ra(sys, NULL);
	return (0);
}

int		recrb(t_system *sys, t_op_list **start, int it_max, int it)
{
//	printf("recsa\n");
	if (sys->a->size < 2)
		return (0);
	rb(sys, NULL);
	if (sorted_till(sys) == sys->size)
	{
		pf_list(start, &rb);
		return (1);
	}
	if (it == it_max)
	{
		rra(sys, NULL);
		return (0);
	}
	if (recsb(sys, start, it_max, it + 1))
	{
		pf_list(start, &rb);
		return (1);
	}
	if (recpb(sys, start, it_max, it + 1))
	{
		pf_list(start, &rb);
		return (1);
	}
	if (recpa(sys, start, it_max, it + 1))
	{
		pf_list(start, &rb);
		return (1);
	}
	if (recra(sys, start, it_max, it + 1))
	{
		pf_list(start, &rb);
		return (1);
	}
	if (recrb(sys, start, it_max, it + 1))
	{
		pf_list(start, &rb);
		return (1);
	}
	if (recrra(sys, start, it_max, it + 1))
	{
		pf_list(start, &rb);
		return (1);
	}
	if (recrrb(sys, start, it_max, it + 1))
	{
		pf_list(start, &rb);
		return (1);
	}
	rrb(sys, NULL);
	return (0);
}

int		recrrb(t_system *sys, t_op_list **start, int it_max, int it)
{
//	printf("recsa\n");
	if (sys->a->size < 2)
		return (0);
	rrb(sys, NULL);
	if (sorted_till(sys) == sys->size)
	{
		pf_list(start, &rrb);
		return (1);
	}
	if (it == it_max)
	{
		ra(sys, NULL);
		return (0);
	}
	if (recsb(sys, start, it_max, it + 1))
	{
		pf_list(start, &rrb);
		return (1);
	}
	if (recpb(sys, start, it_max, it + 1))
	{
		pf_list(start, &rrb);
		return (1);
	}
	if (recpa(sys, start, it_max, it + 1))
	{
		pf_list(start, &rrb);
		return (1);
	}
	if (recrra(sys, start, it_max, it + 1))
	{
		pf_list(start, &rrb);
		return (1);
	}
	if (recra(sys, start, it_max, it + 1))
	{
		pf_list(start, &rrb);
		return (1);
	}
	if (recrrb(sys, start, it_max, it + 1))
	{
		pf_list(start, &rrb);
		return (1);
	}
	rb(sys, NULL);
	return (0);
}


void	rev_print(char *str)
{
	int i = strlen(str);
	while (i--)
		printf("%c", str[i]);
}

void	rec_start(t_system *syst, char **str, int size)
{
	int			i;
	t_system 	*sys;
	t_op_list	*start;
	int it_max;

	it_max = 15;
	start = NULL;
	sys = sys_clone(syst, size);
	clean_input(sys);
	if (sorted_till(sys) == sys->size)
		return ;
	i = 0;
	while (i++ < it_max && start == NULL)
	{
		recsa(sys, &start, i, 0);
		if (start == NULL)
			recpa(sys, &start, i, 0);
	}
	apply_list(&start, syst, str);
	print_sys(sys);
	sys_free(sys);
}
