#include <string.h>
#include "ps.h"
#include <stdlib.h>


typedef void (*t_op)(t_system*, char**);


t_op	str_to_t_op_two(char *str) //"rratt" will return &rra
{
	if (*str == 'r')
	{
		if (str[1] != 'r')
		{
			if (str[1] == 'a')
				return (&ra);
			if (str[1] == 'b')
				return (&rb);
		}
		else if (str[1] == 'r')
		{
			if (str[2] == 'a')
				return (&rra);
			if (str[2] == 'b')
				return (&rrb);
		}
	}
	return (NULL);
}

t_op		str_to_t_op(char *str)
{
	if (str == NULL || *str == '\0' || str[1] == '\0')
		return (NULL);
	if (*str == 'p')
	{
		if (str[1] == 'a')
			return (&pa);
		if (str[1] == 'b')
			return (&pb);
	}
	if (*str == 's')
	{
		if (str[1] == 'a')
			return (&sa);
		if (str[1] == 'b')
			return (&sb);
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

void		push_back(t_end_list **start, t_end_list *elem)
{
	t_end_list	*it;

	it = *start;
	while (it && it->next)
	{
		elem->prev = it;
		it = it->next;
	}
	it = elem;

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
/*
char		*line_copy(char **str_in)
{
	int		i;
	int		j;
	char	*out;
	char	*str;

	str = *str_in;
	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	out = malloco(i + 1);
	out[i] = '\0';
	j = 0;
	while (j < i)
	{
		out[j] = **str_in;
		(*str_in)++;
		j++;
	}
	if (**str_in)
		(*str_in)++;
	return (out);
}
*/

void		str_to_list(t_end_list **start, char *str)
{
	t_op		op;

	start = NULL;

	while (*str)
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