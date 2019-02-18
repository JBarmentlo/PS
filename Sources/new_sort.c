#include "ps.h"
#include <stdio.h>
#define IT_MAX 15

int		recpa(t_system *sys, t_system *og_sys, t_op_list **start, int it);
int		recpb(t_system *sys, t_system *og_sys, t_op_list **start, int it);
int		recsa(t_system *sys, t_system *og_sys, t_op_list **start,int it);
int		recsb(t_system *sys, t_system *og_sys, t_op_list **start, int it);
int		recrb(t_system *sys, t_system *og_sys, t_op_list **start, int it);
int		recrrb(t_system *sys, t_system *og_sys, t_op_list **start,  int it);
int		recra(t_system *sys, t_system *og_sys, t_op_list **start, int it);
int		recrra(t_system *sys, t_system *og_sys, t_op_list **start, int it);

int		recpa(t_system *sys, t_system *og_sys, t_op_list **start, int it)
{
	if (sys->a->size < 1)
		return (0);
	pa(sys, NULL);
	if (sorted_till(sys) == og_sys->a->size)
	{
		pf_list(start, &pa);
		return (it);
	}
	if (it == og_sys->size)
	{
		pb(sys, NULL);
		return (0);
	}
	if (recsa(sys, og_sys, start, it + 1) || recsb(sys, og_sys, start, it + 1) ||
		recpa(sys, og_sys, start, it + 1) || recra(sys, og_sys, start, it + 1) ||
		recrra(sys, og_sys, start, it + 1) || recrrb(sys, og_sys, start, it + 1) ||
		recrb(sys, og_sys, start, it + 1))
	{
		pf_list(start, &pa);
		return (1);
	}
	pb(sys, NULL);
	return (0);
}

int		recpb(t_system *sys, t_system *og_sys, t_op_list **start, int it)
{
//	printf("recpb\n");
	if (sys->b->size < 1)
		return (0);
	pb(sys, NULL);
	if (sorted_till(sys) == og_sys->a->size)
	{
		pf_list(start, &pb);
		return (1);
	}
	if (it == og_sys->size)
	{
		pa(sys, NULL);
		return (0);
	}
	if (recpb(sys, og_sys, start, it + 1) || recsa(sys, og_sys, start, it + 1) ||
		recsb(sys, og_sys, start, it + 1) || recra(sys, og_sys, start, it + 1) ||
		recrra(sys, og_sys, start, it + 1) || recrrb(sys, og_sys, start, it + 1) ||
		recrb(sys, og_sys, start, it + 1))
	{
		pf_list(start, &pb);
		return (1);
	}
	pa(sys, NULL);
	return (0);
}

int		recsb(t_system *sys, t_system *og_sys, t_op_list **start, int it)
{
//	printf("recsb\n");
	if (sys->b->size < 2)
		return (0);
	sb(sys, NULL);
	if (sorted_till(sys) == og_sys->a->size)
	{
		pf_list(start, &sb);
		return (1);
	}
	if (it == og_sys->size)
	{
		sb(sys, NULL);
		return (0);
	}
	if (recsa(sys, og_sys, start, it + 1) || recpb(sys, og_sys, start, it + 1) ||
		recpa(sys, og_sys, start, it + 1) || recra(sys, og_sys, start, it + 1) ||
		recrra(sys, og_sys, start, it + 1) || recrrb(sys, og_sys, start, it + 1) ||
		recrb(sys, og_sys, start, it + 1))
	{
		pf_list(start, &sb);
		return (1);
	}
	sb(sys, NULL);
	return (0);
}

int		recsa(t_system *sys, t_system *og_sys, t_op_list **start, int it)
{
//	printf("recsa\n");
	if (sys->a->size < 2)
		return (0);
	sa(sys, NULL);
	if (sorted_till(sys) == og_sys->a->size)
	{
		pf_list(start, &sa);
		return (1);
	}
	if (it == og_sys->size)
	{
		sa(sys, NULL);
		return (0);
	}
	if (recsb(sys, og_sys, start, it + 1) || recpb(sys, og_sys, start, it + 1) ||
		recpa(sys, og_sys, start, it + 1) || recra(sys, og_sys, start, it + 1) ||
		recrra(sys, og_sys, start, it + 1) || recrrb(sys, og_sys, start, it + 1) ||
		recrb(sys, og_sys, start, it + 1))
	{
		pf_list(start, &sa);
		return (1);
	}
	sa(sys, NULL);
	return (0);
}

int		recra(t_system *sys, t_system *og_sys, t_op_list **start, int it)
{
	if (sys->a->size < 2)
		return (0);
	ra(sys, NULL);
	if (sorted_till(sys) == og_sys->a->size)
	{
		pf_list(start, &ra);
		return (1);
	}
	if (it == og_sys->size)
	{
		rra(sys, NULL);
		return (0);
	}
	if (recsb(sys, og_sys, start, it + 1) || recpb(sys, og_sys, start, it + 1) ||
		recpa(sys, og_sys, start, it + 1) || recra(sys, og_sys, start, it + 1) ||
		recrrb(sys, og_sys, start, it + 1) || recrb(sys, og_sys, start, it + 1) ||
		recra(sys, og_sys, start, it + 1))
	{
		pf_list(start, &ra);
		return (1);
	}
	rra(sys, NULL);
	return (0);
}

int		recrra(t_system *sys, t_system *og_sys, t_op_list **start, int it)
{
//	printf("recsa\n");
	if (sys->a->size < 2)
		return (0);
	rra(sys, NULL);
	if (sorted_till(sys) == og_sys->a->size)
	{
		pf_list(start, &rra);
		return (1);
	}
	if (it == og_sys->size)
	{
		ra(sys, NULL);
		return (0);
	}
	if (recsb(sys, og_sys, start, it + 1) || recpb(sys, og_sys, start, it + 1) ||
		recpa(sys, og_sys, start, it + 1) || recrra(sys, og_sys, start, it + 1) ||
		recrrb(sys, og_sys, start, it + 1) || recrb(sys, og_sys, start, it + 1) ||
		recsa(sys, og_sys, start, it + 1))
	{
		pf_list(start, &rra);
		return (1);
	}
	ra(sys, NULL);
	return (0);
}

int		recrb(t_system *sys, t_system *og_sys, t_op_list **start, int it)
{
//	printf("recsa\n");
	if (sys->b->size < 2)
		return (0);
	rb(sys, NULL);
	if (sorted_till(sys) == og_sys->a->size)
	{
		pf_list(start, &rb);
		return (1);
	}
	if (it == og_sys->size)
	{
		rrb(sys, NULL);
		return (0);
	}
	if (recsb(sys, og_sys, start, it + 1) || recpb(sys, og_sys, start, it + 1) ||
		recpa(sys, og_sys, start, it + 1) || recra(sys, og_sys, start, it + 1) ||
		recrb(sys, og_sys, start, it + 1) || recrra(sys, og_sys, start, it + 1) ||
		recrrb(sys, og_sys, start, it + 1))
	{
		pf_list(start, &rb);
		return (1);
	}
	rrb(sys, NULL);
	return (0);
}

int		recrrb(t_system *sys, t_system *og_sys, t_op_list **start, int it)
{
//	printf("recsa\n");
	if (sys->b->size < 2)
		return (0);
	rrb(sys, NULL);
	if (sorted_till(sys) == og_sys->a->size)
	{
		pf_list(start, &rrb);
		return (1);
	}
	if (it == og_sys->size)
	{
		rb(sys, NULL);
		return (0);
	}
	if (recsb(sys, og_sys, start, it + 1) || recpb(sys, og_sys, start, it + 1) ||
		recpa(sys, og_sys, start, it + 1) || recrra(sys, og_sys, start, it + 1) ||
		recra(sys, og_sys, start, it + 1) || recrrb(sys, og_sys, start, it + 1) ||
		recsa(sys, og_sys, start, it + 1))
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

void	rec_start(t_system *syst, char **str)
{
	t_system 	*sys;
	t_system	*fake;
	t_op_list	*start;
	int			bool;

	bool = 0;
	start = NULL;
	sys = sys_clone(syst);
	fake = sys_fake(0 , sys->a->size, sys->b->size);
	printf("still %d size %d\n", sorted_till(sys) ,sys->a->size);
	if (sorted_till(sys) == sys->a->size)
		return ;

	while (bool == 0)
	{
		printf("itmax %d\n", fake->size);
		bool = recsa(sys, fake, &start, 0);
		if (bool == 0)
			bool = recpa(sys, fake, &start, 0);
		if (bool == 0)
			bool = recra(sys, fake, &start, 0);
		fake->size++;
	}

	apply_list(&start, syst, str); //free dat shit

	sys_free(sys);
	free_sys_fake(fake);
}
