#include <string.h>
#include "ps.h"
#include <stdlib.h>



#include<stdio.h>
t_op	str_to_t_op_two(char *str)
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
	if (start == &elem)
		*start = (*start)->next;
	if (elem->prev)
		elem->prev->next = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
}

void		str_to_list(t_end_list **start, char *str)
{
	t_op		op;

	while (str && *str)
	{
		op = str_to_t_op(str);
		if (op != NULL)
			add_new_to_list(start, op);
		while (*str && *str != '\n')
			str++;
		if (*str)
			str++;
	}
}

void		print_list(t_end_list **start)
{
	t_end_list	*it;

	if (start == NULL)
		return ;
	it = *start;
	while (it)
	{
		if (it->op == &pa)
			printf("pa\n");
		else if (it->op == &pb)
			printf("pb\n");
		else if (it->op == &sa)
			printf("sa\n");
		else if (it->op == &sb)
			printf("sb\n");
		else if (it->op == &ra)
			printf("ra\n");
		else if (it->op == &rb)
			printf("rb\n");
		else if (it->op == &rr)
			printf("rr\n");
		else if (it->op == &rra)
			printf("rra\n");
		else if (it->op == &rrb)
			printf("rrb\n");
		else if (it->op == &rrr)
			printf("rrr\n");
		else
			printf("sheit\n");
		it = it->next;
	}
}

void		print_op(t_op op)
{
	if (op == &pa)
		printf("pa\n");
	else if (op == &pb)
		printf("pb\n");
	else if (op == &ra)
		printf("ra\n");
	else if (op == &rb)
		printf("rb\n");
	else if (op == &sa)
		printf("sa\n");
	else if (op == &sb)
		printf("sb\n");
	else if (op == &rr)
		printf("rr\n");
	else if (op == &rra)
		printf("rra\n");
	else if (op == &rrb)
		printf("rrb\n");
	else if (op == &rrr)
		printf("rrr\n");
	else
		printf("sheit\n");
}

int	count_end_list(t_end_list **start)
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