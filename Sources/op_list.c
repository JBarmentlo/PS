#include "ps.h"
#include <stdlib.h>

#include <stdio.h>
void	pf_list(t_op_list **start, void (*ff)(t_system*, char**))
{
	t_op_list	*node;
	t_op_list	*it;

	node = (t_op_list*)malloco(sizeof(t_op_list));
	node->f = (*ff);
	node->next = NULL;
	it = *start;
	while (it && it->next)
		it = it->next;
	if (it == NULL)
		*start = node;
	else
		it->next = node;
}

void	apply_list(t_op_list **start, t_system *sys, char **str)
{
	t_op_list	*it;
	it = *start;
	while (it)
	{
		it->f(sys, str);
		it = it->next;
	}
}
