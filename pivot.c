/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 21:48:35 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/02 01:00:57 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

/* t_list	*find_mid(t_ListStack *stack)
{
	t_list	*temp;
	int		index;

	temp = top_list(stack);
	index = 0;
	while (index < stack->size / 2)
	{
		temp = temp->next;
		index++;
	}
	return (temp);
} */

t_list	*find_mid(t_ListStack *stack)
{
	t_list	*temp;
	int		index;
	t_list	*temp1;
	t_list	*temp2;
	t_list	*temp3;

	temp1 = top_list(stack);
	index = 0;
	while (index < stack->size / 2)
	{
		temp = temp->next;
		index++;
	}
	temp2 = temp;
	temp3 = bottom_list(stack);
	if (temp->data < temp2->data && temp2->data < temp3->data)
		return (temp2);
	else if (temp1->data < temp3->data && temp3->data < temp2->data)
		return (temp3);
	else
		return (temp1);
}

void	move_high(t_ListStack *a, t_ListStack *b)
{
	t_list	*mid;
	t_list	*temp;

	mid = find_mid(a);
	temp = top_list(a);
	while (mid != temp)
	{
		if (mid->data < temp->data)
			pb(a, b);
		else
			ra(a, 1);
		temp = top_list(a);
	}
	temp = bottom_list(a);
	while (mid != temp)
	{
		if (mid->data < temp->data)
		{
			rra(a, 1);
			pb(a, b);
		}
		else
			rra(a, 1);
		temp = bottom_list(a);
	}
	rra(a, 1);
	pb(a, b);
}

void	move_low(t_ListStack *a, t_ListStack *b)
{
	t_list	*mid;
	t_list	*temp;

	mid = find_mid(b);
	temp = top_list(b);
	while (mid != temp)
	{
		if (mid->data > temp->data)
			pa(a, b);
		else
			rb(b, 1);
		temp = top_list(b);
	}
	temp = bottom_list(b);
	while (mid != temp)
	{
		if (mid->data > temp->data)
		{
			rrb(b, 1);
			pa(a, b);
		}
		else
			rrb(b, 1);
		temp = bottom_list(b);
	}
	rrb(b, 1);
	pa(a, b);
}

void	move_all_again(t_ListStack *a)
{
	int		index;

	index = a->size;
	printf("%d\n", index);
	while (index >= 0)
	{

		ra(a, 1);
		index--;
	}
}
