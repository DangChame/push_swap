/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:21:46 by cchoi             #+#    #+#             */
/*   Updated: 2021/04/13 17:21:57 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	int				data;
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
int			make_ten(int nb);
int			make_nb(const char *s, int ini, int last, int m_count);
int			ft_atoi(const char *s);


/*
	check_utils.c
*/
int			check_nb(char c);
int			check_int(char *s);
int			check_all_int(int ac, char **av);
int			check_twice(t_ListStack *stack);

/*
	make_list.c
*/
t_ListStack	*create_list_stack(void);
int			push_list(t_ListStack *stk, int data);
int			is_empty_stack_list(t_ListStack *stk);
int			pop_list(t_ListStack *stk);
t_list		*top_list(t_ListStack *stk);
void		delete_stack_list(t_ListStack *stk);
t_ListStack	*make_stack(int ac, char **av);

/*
	game.c
*/
void		sa(t_ListStack *stack_a, int msg);
void		sb(t_ListStack *stack_b, int msg);
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

#endif
