#include <string.h>
#include "ps.h"
#include "libft.h"
#include <stdlib.h>

void		add_new_to_list(t_end_list **start, t_op op)
{
	t_end_list	*new;

	new = new_end_list(op);
	push_back(start, new);
}

void		rm_elem(t_end_list **start, t_end_list *elem)
{
	if (*start == elem)
		*start = (*start)->next;
	if (elem->prev)
		elem->prev->next = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
	free(elem);
}

void		str_to_list(t_end_list **start, char *str)
{
	t_op		op;

	while (str && *str)
	{
		op = str_to_t_op(str);
		if (op != NULL)
			add_new_to_list(start, op);
		else
			error();
		while (*str && *str != '\n')
			str++;
		if (*str)
			str++;
	}
}

void		print_op(t_op op)
{
	if (op == &pa)
		ft_printf("pa\n");
	else if (op == &pb)
		ft_printf("pb\n");
	else if (op == &ra)
		ft_printf("ra\n");
	else if (op == &rb)
		ft_printf("rb\n");
	else if (op == &sa)
		ft_printf("sa\n");
	else if (op == &sb)
		ft_printf("sb\n");
	else if (op == &rr)
		ft_printf("rr\n");
	else if (op == &rra)
		ft_printf("rra\n");
	else if (op == &rrb)
		ft_printf("rrb\n");
	else if (op == &rrr)
		ft_printf("rrr\n");
	else
		ft_printf("sheit\n");
}

void		print_list(t_end_list **start)
{
	t_end_list	*it;

	if (start == NULL)
		return ;
	it = *start;
	while (it)
	{
		print_op(it->op);
		it = it->next;
	}
}
