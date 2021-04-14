/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:06:33 by cchoi             #+#    #+#             */
/*   Updated: 2021/04/14 19:02:45 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rrb(t_ListStack *stack_b, int msg)
{
	t_list	*last_before;
	t_list	*last;
	t_list	*second;

	if (msg == 1)
		write(1,"rrb\n", 4);
	last_before = stack_b->top;
	if (last_before == NULL)
		return ;
	second = stack_b->top->next;
	if (second == NULL)
		return ;
	while (last_before->next->next != NULL)
	{
		last_before = last_before->next;
	}
	last = last_before->next;
	last->next = stack_b->top;
	stack_b->top = last;
	last_before->next = NULL;
}

void	rrr(t_ListStack *stack_a, t_ListStack *stack_b)
{
	rra(stack_a, -1);
	rrb(stack_b, -1);
	write(1,"rrr\n", 4);
}
