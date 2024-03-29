/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 00:11:11 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 22:21:49 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		sa(t_liststack *stack_a, int msg)
{
	t_list		*temp;
	t_list		*temp2;
	t_list		*temp3;

	temp = top_list(stack_a);
	if (temp == NULL)
		return (-1);
	temp2 = temp->next;
	if (temp2 == NULL)
		return (-2);
	temp3 = temp2->next;
	stack_a->top = temp2;
	stack_a->top->next = temp;
	temp->next = temp3;
	if (msg == 1)
		write(1, "sa\n", 3);
	return (1);
}

int		sb(t_liststack *stack_b, int msg)
{
	t_list		*temp;
	t_list		*temp2;
	t_list		*temp3;

	temp = top_list(stack_b);
	if (temp == NULL)
		return (-1);
	temp2 = temp->next;
	if (temp2 == NULL)
		return (-2);
	temp3 = temp2->next;
	stack_b->top = temp2;
	stack_b->top->next = temp;
	temp->next = temp3;
	if (msg == 1)
		write(1, "sb\n", 3);
	return (1);
}

void	ss(t_liststack *stack_a, t_liststack *stack_b)
{
	int	nb;
	int	nb2;

	nb = sa(stack_a, -1);
	nb2 = sb(stack_b, -1);
	if (nb == 1 || nb2 == 1)
		write(1, "ss\n", 3);
}

void	pa(t_liststack *stack_a, t_liststack *stack_b)
{
	long int	data;

	if (is_empty_stack_list(stack_b) != 1)
	{
		data = pop_list(stack_b);
		push_list(stack_a, data);
		write(1, "pa\n", 3);
	}
}

void	pb(t_liststack *stack_a, t_liststack *stack_b)
{
	long int		data;

	if (is_empty_stack_list(stack_a) != 1)
	{
		data = pop_list(stack_a);
		push_list(stack_b, data);
		write(1, "pb\n", 3);
	}
}
