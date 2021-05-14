/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:21:46 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 22:53:21 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_list
{
	long int		data;
	struct s_list	*next;
}					t_list;

typedef struct		s_liststack
{
	t_list			*top;
	int				size;
}					t_liststack;

int					ck_spa(const char s);
long int			make_ten(int nb);
long int			make_nb(const char *s, int ini, int last, int m_count);
long int			ft_atoi(const char *s);

int					check_nb(char c);
int					check_int(char *s);
int					check_all_int(int ac, char **av);
int					check_twice(t_liststack *stack);
int					check_int_error(t_liststack *stack_a);

int					check_p_or_m_alone(int ac, char **av);
int					p_m_alone(char *s);

t_liststack			*create_list_stack(void);
int					push_list(t_liststack *stk, long int data);
int					is_empty_stack_list(t_liststack *stk);
long int			pop_list(t_liststack *stk);
t_list				*top_list(t_liststack *stk);
void				delete_stack_list(t_liststack *stk);
t_liststack			*make_stack(int ac, char **av);
t_list				*bottom_list(t_liststack *stk);

int					sa(t_liststack *stack_a, int msg);
int					sb(t_liststack *stack_b, int msg);
void				ss(t_liststack *stack_a, t_liststack *stack_b);
void				pa(t_liststack *stack_a, t_liststack *stack_b);
void				pb(t_liststack *stack_a, t_liststack *stack_b);

void				ra(t_liststack *stack_a, int msg);
void				rb(t_liststack *stack_b, int msg);
void				rr(t_liststack *stack_a, t_liststack *stack_b);
void				rra(t_liststack *stack_a, int msg);

void				rrb(t_liststack *stack_b, int msg);
void				rrr(t_liststack *stack_a, t_liststack *stack_b);

void				sort(t_liststack *stack_a, t_liststack *stack_b);
void				sorting_b_to_a(t_liststack *stack_a, t_liststack *stack_b);
void				sorting_a_to_b(t_liststack *stack_a, t_liststack *stack_b);

int					check_sorted(t_liststack *stack_a);

t_list				*find_mid(t_liststack *stack);
void				move_high(t_liststack *a, t_liststack *b);
void				move_low(t_liststack *a, t_liststack *b);
void				move_all_again(t_liststack *a);
int					check_c(char to, char c);
int					check_nb_to_mal(char const *s, char c);
int					ar_mal(char const *s, char c, int index3);
char				**ft_split(char const *s, char c);

int					*make_int_list(t_liststack *stack);
void				find_max_and_int(int *arr, int size, int *index_arr);
void				move_a_to_b(int *arr, int size, t_liststack *s_a,
	t_liststack *s_b);
void				max_to_top(int *arr, t_liststack *s_b);
int					find_lowest(int *result);
void				v2(t_liststack *stack_a, t_liststack *stack_b);
void				move_b_to_a(int *arr, int size, t_liststack *s_a,
	t_liststack *s_b);
void				move_b_to_a_large(int *arr, int size, t_liststack *a,
	t_liststack *b);
void				move_a_to_b_small(int *arr, int size, t_liststack *a,
	t_liststack *b);

void				save_index(int *result, int size, int *index);

void				quicksort(int *a, int left, int right);
void				swap(int *a, int low, int high);
int					partition(int *a, int left, int right);

void				print_stack(t_liststack *a, t_liststack	*b);
void				v3(t_liststack *stack_a, t_liststack *stack_b);
void				v4(t_liststack *stack_a, t_liststack *stack_b);
void				move_a_to_b_1_2(t_liststack *a, t_liststack *b,
	int *par, int *nb);
void				find_low_3_move(int *arr, t_liststack *a, int *par);
void				v5(t_liststack *stack_a, t_liststack *stack_b);
void				v6(t_liststack *stack_a, t_liststack *stack_b);
void				move_a_to_b_util(int ri, t_liststack *a, t_liststack *b,
	int tri);
void				move_2_to_b(t_liststack *a, t_liststack *b, int *arr,
	int *nb_moved);
void				rotate_2_on_b(t_liststack *s, int *partion);
void				rotate_1_on_b(t_liststack *s, int *partion);
void				rotate_0_on_b(t_liststack *s, int *partion);
void				move_1_a_to_b(t_liststack *a, t_liststack *b, int *arr);
void				move_0_a_to_b(t_liststack *a, t_liststack *b, int *arr);
void				init_nbmoved(int *nb_moved);
void				do_pa(t_liststack *a, t_liststack *b, int *temp);

#endif
