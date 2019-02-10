#include "ps.h"

void	sb(t_system *sys)
{
	int	*arr;
	int	tmp;

	arr = sys->b->array;
	if (sys->b->size < 2)
		return;
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
}

void	pb(t_system *sys)
{
	t_stack	*a;
	t_stack	*b;

	a = sys->a;
	b = sys->b;

	if (b->size == 0)
		return;
	a->array--;
	a->array[0] = b->array[0];
	b->array++;
	a->size++;
	b->size--;
}

void	rrb(t_system *sys)
{
	t_stack *b;
	int		i;
	int		tmp;

	b = sys->b;
	i = b->size - 1;
	if (b->size <= 1)
		return;
	tmp = b->array[i];
	while (i)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = tmp;
}

void	rb(t_system *sys)
{
	t_stack *b;
	int		i;
	int		tmp;

	b = sys->b;
	i = 0;
	if (b->size <= 1)
		return;
	tmp = b->array[i];
	while (i + 1 < b->size)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->array[i] = tmp;
}
