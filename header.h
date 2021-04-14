/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:21:46 by cchoi             #+#    #+#             */
/*   Updated: 2021/04/14 18:50:43 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	long int		data;
	struct s_list	*next;
}					t_list;

typedef struct		s_ListStack
{
	t_list			*top;
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
	make_list.c
*/
t_ListStack	*create_list_stack(void);
int			push_list(t_ListStack *stk, long int data);
int			is_empty_stack_list(t_ListStack *stk);
long int	pop_list(t_ListStack *stk);
t_list		*top_list(t_ListStack *stk);
void		delete_stack_list(t_ListStack *stk);
t_ListStack	*make_stack(int ac, char **av);

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

#endif
