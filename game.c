/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 00:11:11 by cchoi             #+#    #+#             */
/*   Updated: 2021/04/14 00:11:11 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_ListStack *stack_a)
{
	t_list		*temp;
	t_list		*temp2;
	t_list		*temp3;

	temp = top_list(stack_a);
	temp2 = temp->next;
	temp3 = temp2->next;
	stack_a->top = temp2;
	stack_a->top->next = temp;
	temp->next = temp3;
	write(1,"sa\n", 3);
}

void	sb(t_ListStack *stack_b)
{
	t_list		*temp;
	t_list		*temp2;
	t_list		*temp3;

	temp = top_list(stack_b);
	temp2 = temp->next;
	temp3 = temp2->next;
	stack_b->top = temp2;
	stack_b->top->next = temp;
	temp->next = temp3;
	write(1,"sb\n", 3);
}

void	ss(t_ListStack *stack_a, t_ListStack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}

void	pa(t_ListStack *stack_a, t_ListStack *stack_b)
{
	int		data;

	if (is_empty_stack_list(stack_b) != -1)
	{
		data = pop_list(stack_b);
		push_list(stack_a, data);
	}
}

void	pb(t_ListStack *stack_a, t_ListStack *stack_b)
{
	int		data;

	if (is_empty_stack_list(stack_a) == -1)
	{
		data = pop_list(stack_a);
		push_list(stack_b, data);
	}
}