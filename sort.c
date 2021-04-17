/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 10:31:24 by cchoi             #+#    #+#             */
/*   Updated: 2021/04/17 11:30:48 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		find_highest(t_ListStack *stack_a)
{
	t_list	*temp;
	int		temp_data;
	int		index;
	int		temp_index;

	temp = top_list(stack_a);
	index = 0;
	while (temp->next != NULL)
	{
		if (temp_data < temp->data)
		{
			temp_data = temp->data;
			temp_index = index;
		}
		temp = temp->next;
		index++;
	}
	return (temp_index);
}

void	sorting_a_to_b(t_ListStack *stack_a, t_ListStack *stack_b)
{
	t_list	*temp;
	int		index;
	int		temp_index;

	while (is_empty_stack_list(stack_a) == 0)
	{
		index = find_highest(stack_a);
		temp = top_list(stack_a);
		temp_index = 0;
		while (temp_index < index)
		{
			ra(stack_a, 1);
			temp_index++;
		}
		pb(stack_a, stack_b);
	}
}
/*
void	sorting_b_to_a(t_ListStack *stack_a, t_ListStack *stack_b)
{
	t_list	*temp;

	temp = top_list(stack_b);
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->data > temp->next->next->data)
		{
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
		else
		{
			rb(stack_b, 1);
			rb(stack_b, 1);
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
			rrb(stack_b, 1);
			rrb(stack_b, 1);
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
		temp = top_list(stack_b);
	}
}

void	sort(t_ListStack *stack_a, t_ListStack *stack_b)
{
	while (check_sorted(stack_a) == -1)
	{
		sorting_a_to_b(stack_a, stack_b);
			write(1, "pqpqpqpqpq\n", 11);
		sorting_b_to_a(stack_a, stack_b);
		break ;
	}
	write(1, "pqpqpqpqpq\n", 11);
}
 */
