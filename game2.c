/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 00:57:29 by cchoi             #+#    #+#             */
/*   Updated: 2021/04/14 01:15:37 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ra(t_ListStack *stack_a, int msg)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	last = stack_a->top;
	first = stack_a->top;
	second = first->next;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first;
	first->next = NULL;
	stack_a->top = second;
	if (msg == 1)
		write(1,"ra\n", 3);
}

void	rb(t_ListStack *stack_b, int msg)
{
	t_list	*first;
	t_list	*last_before;
	t_list	*last;
	t_list	*second;

	last_before = stack_b->top;
	first = stack_b->top;
	second = first->next;
	while (last_before->next->next != NULL)
	{
		last_before = last_before->next;
	}
	last = last_before->next;
	last_before->next = first;
	first->next = NULL;
	stack_b->top = last;
	stack_b->top->next = second;
	if (msg == 1)
		write(1,"rb\n", 3);
}

void	rr(t_ListStack *stack_a, t_ListStack *stack_b)
{
	ra(stack_a, -1);
	rb(stack_b, -1);
	write(1,"rr\n", 3);
}

void	rra(t_ListStack *stack_a, int msg)
{
	t_list	*first;
	t_list	*last_before;
	t_list	*last;
	t_list	*second;

	last_before = stack_a->top;
	first = stack_a->top;
	second = first->next;
	while (last_before->next->next != NULL)
	{
		last_before = last_before->next;
	}
	last = last_before->next;
	stack_a->top = last;
	stack_a->top->next = second;
	last = first;
	last->next = NULL;
	last_before->next = last;
	if (msg == 1)
		write(1,"rra\n", 4);
}