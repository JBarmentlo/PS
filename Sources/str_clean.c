#include <string.h>
#include "ps.h"
#include <stdlib.h>


static char	*ft_strdup(char *str)
{
	int	i = 0;
	int	j = 0;
	char	*out;

	while (str && str[i])
		i++;
	if ( i == 0)
		return (NULL);
	out = malloco(i + 1);
	while (i && j <= i)
	{
		out[j] = str[i];
		j++;
	}
	return (out);
}

t_end_list	*new_end_list(char	*str)
{
	t_end_list	*new;

	new = malloco(sizeof(t_end_list));
	new->str = ft_strdup(str);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		free_elem(t_end_list *elem)
{
	free(elem->str);
	free(elem->next);
	free(elem->prev);
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

void		add_new_to_list(t_end_list **start, char *str)
{
	t_end_list	*new;

	new = new_end_list(str);
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

void		str_to_list(t_end_list **start, char *str)
{
	char		*str_cp;

	str_cp = str;
	start = NULL;

	while (*str_cp)
	{
		add_new_to_list(start, line_copy(&str_cp));
	}
}