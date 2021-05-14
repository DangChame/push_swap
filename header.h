/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:21:46 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 20:40:19 by cchoi            ###   ########.fr       */
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

typedef struct		s_ListStack
{
	t_list			*top;
	int				size;
}					t_ListStack;

/*
	ft_atoi.c
*/
int			ck_spa(const char s);
long int	make_ten(int nb);
long int	make_nb(const char *s, int ini, int last, int m_count);
long int	ft_atoi(const char *s);


/*
	check_utils.c
*/
int			check_nb(char c);
int			check_int(char *s);
int			check_all_int(int ac, char **av);
int			check_twice(t_ListStack *stack);
int			check_int_error(t_ListStack *stack_a);

/*
	check_utils2.c
*/
int			check_p_or_m_alone(int ac, char **av);
int			p_m_alone(char *s);

/*
	make_list.c
*/
t_ListStack	*create_list_stack(void);
int			push_list(t_ListStack *stk, long int data);
int			is_empty_stack_list(t_ListStack *stk);
long int	pop_list(t_ListStack *stk);
t_list		*top_list(t_ListStack *stk);
void		delete_stack_list(t_ListStack *stk);
t_ListStack	*make_stack(int ac, char **av);
t_list		*bottom_list(t_ListStack *stk);


/*
	game.c
*/
int			sa(t_ListStack *stack_a, int msg);
int			sb(t_ListStack *stack_b, int msg);
void		ss(t_ListStack *stack_a, t_ListStack *stack_b);
void		pa(t_ListStack *stack_a, t_ListStack *stack_b);
void		pb(t_ListStack *stack_a, t_ListStack *stack_b);

/*
	game2.c
*/
void		ra(t_ListStack *stack_a, int msg);
void		rb(t_ListStack *stack_b, int msg);
void		rr(t_ListStack *stack_a, t_ListStack *stack_b);
void		rra(t_ListStack *stack_a, int msg);

/*
	game3.c
*/
void		rrb(t_ListStack *stack_b, int msg);
void		rrr(t_ListStack *stack_a, t_ListStack *stack_b);

/*
	sort.c
*/

void		sort(t_ListStack *stack_a, t_ListStack *stack_b);
void		sorting_b_to_a(t_ListStack *stack_a, t_ListStack *stack_b);
void		sorting_a_to_b(t_ListStack *stack_a, t_ListStack *stack_b);

int			check_sorted(t_ListStack *stack_a);

/// pivot.c

t_list		*find_mid(t_ListStack *stack);
void		move_high(t_ListStack *a, t_ListStack *b);
void		move_low(t_ListStack *a, t_ListStack *b);
void		move_all_again(t_ListStack *a);

/// ft_split.c

int			check_c(char to, char c);
int			check_nb_to_mal(char const *s, char c);
int			ar_mal(char const *s, char c, int index3);
char		**ft_split(char const *s, char c);

/// new.c
int 		*make_int_list(t_ListStack *stack);
void		find_max_and_int(int *arr, int size, int *index_arr);
void		move_a_to_b(int *arr, int size, t_ListStack *s_a, t_ListStack *s_b);
/// result[4] 의 결과물은 min_to_top_up, max_to_top_up, min_to_top_down, max_to_top_down 순임.
void		max_to_top(int *arr, t_ListStack *s_b);
int			find_lowest(int *result);


/// new2.c
void		v2(t_ListStack *stack_a, t_ListStack *stack_b);
void		move_b_to_a(int *arr, int size, t_ListStack *s_a, t_ListStack *s_b);
void		move_b_to_a_large(int *arr, int size, t_ListStack *a, t_ListStack *b);
void		move_a_to_b_small(int *arr, int size, t_ListStack *a, t_ListStack *b);


///	quick_sort.c
void 		QuickSort(int *A, int left, int right);
void 		swap(int *A, int low, int high);
int 		Partition(int *A, int left, int right);

void	print_stack(t_ListStack *a, t_ListStack	*b);
void		v3(t_ListStack *stack_a, t_ListStack *stack_b);
void		v4(t_ListStack *stack_a, t_ListStack *stack_b);
void		move_a_to_b_1_2(t_ListStack *a, t_ListStack *b, int *par, int *nb);
void	find_low_3_move(int *arr, t_ListStack *a, int *par);
void	v5(t_ListStack *stack_a, t_ListStack *stack_b);
void	v6(t_ListStack *stack_a, t_ListStack *stack_b);

#endif
