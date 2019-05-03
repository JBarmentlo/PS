#include "ps.h"

void	sa(t_system *sys, char **str)
{
	int	*arr;
	int	tmp;

	arr = sys->a->array;
	if (sys->a->size < 2)
		return ;
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
	ft_append(str, "sa\n");
}

void	pa(t_system *sys, char **str)
{
	t_stack	*a;
	t_stack	*b;

	a = sys->a;
	b = sys->b;
	if (a->size == 0)
		return ;
	b->array--;
	b->array[0] = a->array[0];
	a->array++;
	b->size++;
	a->size--;
	ft_append(str, "pa\n");
}

void	rra(t_system *sys, char **str)
{
	t_stack *a;
	int		i;
	int		tmp;

	a = sys->a;
	i = a->size - 1;
	if (a->size <= 1)
		return ;
	tmp = a->array[a->size - 1];
	while (i)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = tmp;
	ft_append(str, "rra\n");
}

void	ra(t_system *sys, char **str)
{
	t_stack *a;
	int		i;
	int		tmp;

	a = sys->a;
	i = 0;
	if (a->size <= 1)
		return ;
	tmp = a->array[i];
	while (i + 1 < a->size)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[i] = tmp;
	ft_append(str, "ra\n");
}
