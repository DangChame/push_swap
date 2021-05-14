/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 00:57:29 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 22:21:49 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ra(t_liststack *stack_a, int msg)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	if (msg == 1)
		write(1, "ra\n", 3);
	last = stack_a->top;
	if (last == NULL)
		return ;
	first = stack_a->top;
	second = first->next;
	if (second == NULL)
		return ;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first;
	first->next = NULL;
	stack_a->top = second;
}

void	rb(t_liststack *stack_b, int msg)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	if (msg == 1)
		write(1, "rb\n", 3);
	last = stack_b->top;
	if (last == NULL)
		return ;
	first = stack_b->top;
	second = first->next;
	if (second == NULL)
		return ;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first;
	first->next = NULL;
	stack_b->top = second;
}

void	rr(t_liststack *stack_a, t_liststack *stack_b)
{
	ra(stack_a, -1);
	rb(stack_b, -1);
	write(1, "rr\n", 3);
}

void	rra(t_liststack *stack_a, int msg)
{
	t_list	*last_before;
	t_list	*last;
	t_list	*second;

	if (msg == 1)
		write(1, "rra\n", 4);
	last_before = stack_a->top;
	if (last_before == NULL)
		return ;
	second = stack_a->top->next;
	if (second == NULL)
		return ;
	while (last_before->next->next != NULL)
	{
		last_before = last_before->next;
	}
	last = last_before->next;
	last->next = stack_a->top;
	stack_a->top = last;
	last_before->next = NULL;
}
