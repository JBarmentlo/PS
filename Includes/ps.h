#ifndef PS_H
# define PS_H

typedef struct  s_stack
{
  int           size;
  int           *array;
}				t_stack;

typedef struct   s_system
{
  int           size;
  t_stack       *a;
  t_stack       *b;
}				t_system;

t_system		*init(int ac, char **av);
void			print_sys(t_system *sys);

void			sa(t_system *sys);
void			pa(t_system *sys);
void			ra(t_system *sys);
void			rra(t_system *sys);

void			sb(t_system *sys);
void			pb(t_system *sys);
void			rb(t_system *sys);
void			rrb(t_system *sys);

int				get_median(int *array, int size);
void			push_half(t_system *sys);

#endif
