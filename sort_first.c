/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_first.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 10:31:24 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/01 22:22:04 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_sorted(t_ListStack *stack_a)
{
	t_list	*temp;

	temp = top_list(stack_a);
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
			return (-1);
		temp = temp->next;
	}
	return (1);
}

/* void	sorting_a_to_b(t_ListStack *stack_a, t_ListStack *stack_b)
{
	t_list	*temp;

	temp = top_list(stack_a);
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
		{
			pb(stack_a, stack_b);
			pb(stack_a, stack_b);
		}
		else
		{
			sa(stack_a, 1);
			pb(stack_a, stack_b);
			pb(stack_a, stack_b);
		}
		temp = top_list(stack_a);
	}
}

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
} */
