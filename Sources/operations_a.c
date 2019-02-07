#include "ps.h"

void	sa(t_system *sys)
{
	int	*arr;
	int	tmp;

	arr = sys->a->array;
	if (sys->a->size < 2)
		return;
	tmp = arr[sys->a->size - 1];
	arr[sys->a->size - 1] = arr[sys->a->size - 2];
	arr[sys->a->size - 2] = tmp;
}

void	pa(t_system *sys)
{
	t_stack	*a;
	t_stack	*b;

	a = sys->a;
	b = sys->b;

	if (a->size == 0)
		return;
	b->array[b->size] = a->array[a->size - 1];
	b->size++;
	a->size--;
}

void	ra(t_system *sys)
{
	t_stack *a;
	int		i;
	int		tmp;

	a = sys->a;
	i = a->size - 1;
	if (a->size <= 1)
		return;
	tmp = a->array[i];
	while (i)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = tmp;
}

void	rra(t_system *sys)
{
	t_stack *a;
	int		i;
	int		tmp;

	a = sys->a;
	i = 0;
	if (a->size <= 1)
		return;
	tmp = a->array[i];
	while (i + 1 < a->size)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[i] = tmp;
}
