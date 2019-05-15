/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:24:21 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/15 15:19:18 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H
# include <string.h>
# define IT_MAX 15

typedef struct			s_stack
{
	int					size;
	int					*array;
}						t_stack;

typedef struct			s_s
{
	int					size;
	t_stack				*a;
	t_stack				*b;
}						t_s;

typedef struct			s_end_list
{
	void				(*op)(t_s*, struct s_end_list**);
	struct s_end_list	*next;
	struct s_end_list	*prev;
}						t_end_list;

typedef struct			s_op_list
{
	void				(*f)(t_s*, struct s_end_list**);
	struct s_op_list	*next;
}						t_op_list;

typedef void			(*t_op)(t_s*, t_end_list**);

void					*malloco(size_t size);
void					ft_append(char **str, char *add);
t_s						*sys_clone(t_s *sys);
void					sys_free(t_s *sys);
t_s						*sys_fake(int size, int a_size, int b_size);
void					free_sys_fake(t_s *sys);

void					apply_list(t_op_list **s, t_s *sys, t_end_list **st);
void					pf_list(t_op_list **s, void (*ff)(t_s*, t_end_list**));

t_s						*init(char **av);
void					print_sys(t_s *sys);

void					sa(t_s *sys, t_end_list **start);
void					pa(t_s *sys, t_end_list **start);
void					ra(t_s *sys, t_end_list **start);
void					rra(t_s *sys, t_end_list **start);

void					sb(t_s *sys, t_end_list **start);
void					pb(t_s *sys, t_end_list **start);
void					rb(t_s *sys, t_end_list **start);
void					rrb(t_s *sys, t_end_list **start);

void					ss(t_s *sys, t_end_list **start);
void					rr(t_s *sys, t_end_list **start);
void					rrr(t_s *sys, t_end_list **start);

int						get_median(int *array, int size);
int						get_median_s(int *array, int size);
int						get_min(int *arr, int size);
void					push_half(t_s *sys);

void					b_a(t_s *sys, int size, t_end_list **start);
void					a_b(t_s *sys, int size, t_end_list **start);
void					a_b_first(t_s *sys, int size, t_end_list **start);
void					m_ab_first(t_s *sys, int size, t_end_list **start);
void					m_ba(t_s *sys, int size, t_end_list **start);
void					m_ab(t_s *sys, int size, t_end_list **start);

void					clean_input(t_s *sys);
int						sorted_till(t_s *sys);

int						clean_str(char *str);
int						str_rm_part(char *str, int begin, int end);

void					new_sort(t_s *sys, char **str);
void					rec_start(t_s *syst, t_end_list **start);

void					daman(void);
int						tab_check(char **av);
int						baktrak(int *lst, int pos, int size);

void					str_to_list(t_end_list **start, char *str);
void					print_list(t_end_list **start);
void					print_op(t_op op);
void					simplify(t_end_list **start);

int						recpa(t_s *sys, t_s *og_sys, t_op_list **start, int it);
int						recpb(t_s *sys, t_s *og_sys, t_op_list **start, int it);
int						recsa(t_s *sys, t_s *og_sys, t_op_list **start, int it);
int						recsb(t_s *sys, t_s *og_sys, t_op_list **start, int it);
int						recrb(t_s *sys, t_s *og_sys, t_op_list **start, int it);
int						recrrb(t_s *sys, t_s *og_sys, t_op_list **st, int it);
int						recra(t_s *sys, t_s *og_sys, t_op_list **start, int it);
int						recrra(t_s *sys, t_s *og_sys, t_op_list **st, int it);

void					only_digits(char **av);
void					is_super_walid(char **tab);
int						int_maxou(char *str);
void					error(void);

int						is_walid(t_s *sys);
int						is_sorted(t_s *sys);

void					add_new_to_list(t_end_list **start, t_op op);
void					rm_elem(t_end_list **start, t_end_list *elem);
void					str_to_list(t_end_list **start, char *str);
void					print_op(t_op op);
void					print_list(t_end_list **start);

t_op					str_to_t_op_two(char *str);
t_op					str_to_t_op(char *str);
t_end_list				*new_end_list(t_op ptr);
void					free_elem(t_end_list *elem);
void					push_back(t_end_list **any, t_end_list *elem);
void					only_digits(char **av);
int						int_maxou_two(char *str);

void					free_end_list(t_end_list **start);
#endif
