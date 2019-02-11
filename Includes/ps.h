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
int				get_median_s(int *array, int size);
int				get_min(int *arr, int size);
void			push_half(t_system *sys);

void			b_a(t_system *sys, int size);
void			a_b(t_system *sys, int size);
void			a_b_first(t_system *sys, int size);
void			m_ab_first(t_system *sys, int size);
void			m_ba(t_system *sys, int size, int iter);
void			m_ab(t_system *sys, int size, int iter);

void			clean_input(t_system *sys);
int				sorted_till(t_system *sys);

void			sort_three(t_system *sys);

#endif
