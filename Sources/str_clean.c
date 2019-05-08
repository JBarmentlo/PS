#include <string.h>
#include "ps.h"
#include "libft.h"
#include <stdlib.h>

t_op		str_to_t_op_two(char *str)
{
	if (*str == 'r')
	{
		if (str[1] != 'r')
		{
			if (str[1] == 'a' && (str[2] == '\n' || str[2] == '\0'))
				return (&ra);
			if (str[1] == 'b' && (str[2] == '\n' || str[2] == '\0'))
				return (&rb);
		}
		else if (str[1] == 'r')
		{
			if (str[2] == 'a' && (str[3] == '\n' || str[3] == '\0'))
				return (&rra);
			if (str[2] == 'b' && (str[3] == '\n' || str[3] == '\0'))
				return (&rrb);
		}
	}
	return (NULL);
}

t_op		str_to_t_op(char *str)
{
	if (str == NULL || *str == '\0' || str[1] == '\0')
		return (NULL);
	if (*str == 's')
	{
		if (str[1] == 'a' && (str[2] == '\n' || str[2] == '\0'))
			return (&sa);
		if (str[1] == 'b' && (str[2] == '\n' || str[2] == '\0'))
			return (&sb);
	}
	if (*str == 'p')
	{
		if (str[1] == 'a' && (str[2] == '\n' || str[2] == '\0'))
			return (&pa);
		if (str[1] == 'b' && (str[2] == '\n' || str[2] == '\0'))
			return (&pb);
	}
	return (str_to_t_op_two(str));
}

t_end_list	*new_end_list(t_op ptr)
{
	t_end_list	*new;

	new = malloco(sizeof(t_end_list));
	new->op = ptr;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		free_elem(t_end_list *elem)
{
	free(elem);
}

void		push_back(t_end_list **any, t_end_list *elem)
{
	t_end_list	*it;

	if (*any == NULL)
	{
		*any = elem;
		return ;
	}
	it = *any;
	while (it && it->next)
		it = it->next;
	it->next = elem;
	elem->prev = it;
}

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

int			count_end_list(t_end_list **start)
{
	t_end_list	*it;
	int			out;

	if (start == NULL)
		return (0);
	it = *start;
	out = 0;
	while (it)
	{
		it = it->next;
		out++;
	}
	return (out);
}

int			neutralise(t_op one, t_op two, int repeat)
{
	if (one == &pa && two == &pb)
		return (1);
	if (one == &ra && two == &rra)
		return (1);
	if (one == &rb && two == &rrb)
		return (1);
	if (repeat)
		return (neutralise(two, one, 0));
	return (0);
}
#include <stdio.h>

t_end_list	*triple(t_end_list **start, t_end_list *a, t_end_list *b, t_end_list *c)
{
	if (!c)
		return (a);
	if (a->op == &ra && b->op == &pa && c->op == &rra)
	{
		a->op = &sa;
		b->op = &pa;
		rm_elem(start, c);
		if (a->prev)
			return (a->prev);
		else
			return (a);
	}
	if (a->op == &rb && b->op == &pb && c->op == &rrb)
	{
		a->op = &sb;
		b->op = &pb;
		rm_elem(start, c);
		if (a->prev)
			return (a->prev);
		else
			return (a);
	}
	return (a);
}

t_end_list	*doble(t_end_list **start, t_end_list *a, t_end_list *b)
{
	if (a->op == &ra && b->op == &rb)
	{
		a->op = &rr;
		rm_elem(start, b);
		if (a->prev)
			return (a->prev);
		else
			return (a);
	}
	if (a->op == &rb && b->op == &ra)
	{
		a->op = &rr;
		rm_elem(start, b);
		if (a->prev)
			return (a->prev);
		else
			return (a);
	}
	return (a);
}

t_end_list	*doble_dos(t_end_list **start, t_end_list *a, t_end_list *b)
{
	if (a->op == &rra && b->op == &rrb)
	{
		a->op = &rrr;
		rm_elem(start, b);
		if (a->prev)
			return (a->prev);
		else
			return (a);
	}
	if (a->op == &rrb && b->op == &rra)
	{
		a->op = &rrr;
		rm_elem(start, b);
		if (a->prev)
			return (a->prev);
		else
			return (a);
	}
	return (a);
}

t_end_list	*doble_zer(t_end_list **start, t_end_list *a, t_end_list *b)
{
	t_end_list	*tmp;

	tmp = a->prev;
	if ((a->op == &pa && b->op == &pb)
		|| (a->op == &pb && b->op == &pa)
			|| (a->op == &ra && b->op == &rra)
				|| (a->op == &rb && b->op == &rrb))
					{
						rm_elem(start, a);
						rm_elem(start, b);
						if (tmp)
							return (tmp);
						return (*start);
					}
	return (a);
}
void		simplify(t_end_list **start)
{
	t_end_list	*it;
	t_end_list	*tmp;

	if (*start == NULL)
		return ;
	it = *start;
	while (it && it->next)
	{
		it = triple(start, it, it->next, it->next->next);
		it = doble(start, it, it->next);
		it = doble_dos(start, it, it->next);
		it = doble_zer(start, it, it->next);
		if (neutralise(it->op, it->next->op, 1))
		{
			tmp = it->prev;
			rm_elem(start, it->next);
			rm_elem(start, it);
			if (tmp)
				it = tmp;
			else
				it = *start;
		}
		else
			it = it->next;
	}
}
