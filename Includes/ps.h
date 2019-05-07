#ifndef PS_H
# define PS_H
# include <string.h>
# define IT_MAX 15
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

typedef struct		s_op_list
{
	void			(*f)(t_system*, char**);
	struct s_op_list	*next;
}					t_op_list;

typedef struct			s_end_list
{
	void 				(*op)(t_system*, char**);
	struct s_end_list	*next;
	struct s_end_list	*prev;
}						t_end_list;

typedef void (*t_op)(t_system*, char**);

void  			*malloco(size_t size);
void			ft_append(char **str, char *add);
t_system		*sys_clone(t_system *sys);
void			sys_free(t_system *sys);
t_system		*sys_fake(int size, int a_size, int b_size);
void			free_sys_fake(t_system *sys);

void			apply_list(t_op_list **start, t_system *sys, char **str);
void			pf_list(t_op_list **start, void (*ff)(t_system*, char**));

t_system		*init(char **av);
void			print_sys(t_system *sys);

void			sa(t_system *sys, char **str);
void			pa(t_system *sys, char **str);
void			ra(t_system *sys, char **str);
void			rra(t_system *sys, char **str);

void			sb(t_system *sys, char **str);
void			pb(t_system *sys, char **str);
void			rb(t_system *sys, char **str);
void			rrb(t_system *sys, char **str);

void			ss(t_system *sys, char **str);
void			rr(t_system *sys, char **str);
void			rrr(t_system *sys, char **str);

int				get_median(int *array, int size);
int				get_median_s(int *array, int size);
int				get_min(int *arr, int size);
void			push_half(t_system *sys);

void			b_a(t_system *sys, int size, char **str);
void			a_b(t_system *sys, int size, char **str);
void			a_b_first(t_system *sys, int size, char **str);
void			m_ab_first(t_system *sys, int size, char **str);
void			m_ba(t_system *sys, int size, char **str);
void			m_ab(t_system *sys, int size, char **str);

void			clean_input(t_system *sys);
int				sorted_till(t_system *sys);

int				clean_str(char *str);
int				str_rm_part(char *str, int begin, int end);

void			new_sort(t_system *sys, char **str);
void			rec_start(t_system *syst, char **str);

void			daman(void);
int				tab_check(char **av);
int				baktrak(int *lst, int pos, int size);

void			str_to_list(t_end_list **start, char *str);
void			print_list(t_end_list **start);
int				count_end_list(t_end_list **start);
void			print_op(t_op op);
void			simplify(t_end_list **start);

int				recpa(t_system *sys, t_system *og_sys, t_op_list **start, int it);
int				recpb(t_system *sys, t_system *og_sys, t_op_list **start, int it);
int				recsa(t_system *sys, t_system *og_sys, t_op_list **start,int it);
int				recsb(t_system *sys, t_system *og_sys, t_op_list **start, int it);
int				recrb(t_system *sys, t_system *og_sys, t_op_list **start, int it);
int				recrrb(t_system *sys, t_system *og_sys, t_op_list **start,  int it);
int				recra(t_system *sys, t_system *og_sys, t_op_list **start, int it);
int				recrra(t_system *sys, t_system *og_sys, t_op_list **start, int it);


void			only_digits(char **av);
void			is_super_walid(char **tab);
int				int_maxou(char *str);
void			error(void);

int				is_walid(t_system *sys);
int				is_sorted(t_system *sys);
#endif
