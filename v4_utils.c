/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:50:57 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/15 12:31:14 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_a_to_b_0_1(t_liststack *a, t_liststack *b, int *par, int *nb)
{
	int		size;

	size = a->size;
	while (size >= 0)
	{
		if (-2147483648 <= top_list(a)->data && top_list(a)->data <= par[0])
		{
			pb(a, b);
			rb(b, 1);
			nb[0] += 1;
		}
		else if (par[0] < top_list(a)->data && top_list(a)->data <= par[1])
		{
			pb(a, b);
			nb[1] += 1;
		}
		else if (par[1] < top_list(a)->data && top_list(a)->data <= 2147483647)
			ra(a, 1);
		size--;
	}
}

void	find_max_and_int(int *arr, int size, int *index_arr)
{
	int		min;
	int		max;
	int		temp;
	int		index;

	index = 0;
	temp = arr[index];
	min = 0;
	max = 0;
	while (index < size)
	{
		if (arr[index] > arr[max])
			max = index;
		if (arr[index] <= arr[min])
			min = index;
		index++;
	}
	index_arr[0] = min;
	index_arr[1] = max;
}

void	move_small(t_liststack *a, t_liststack *b, int *arr)
{
	int		index[2];
	int		min_to_top_up;
	int		min_to_top_down;

	find_max_and_int(arr, a->size, index);
	min_to_top_up = index[0];
	min_to_top_down = a->size - 1 - index[0] + 1;
	if (min_to_top_down < min_to_top_up)
	{
		while (min_to_top_down != 0)
		{
			rra(a, 1);
			min_to_top_down--;
		}
	}
	else
	{
		while (min_to_top_up != 0)
		{
			ra(a, 1);
			min_to_top_up--;
		}
	}
	pb(a, b);
}

void	move_small_b_to_a(int *arr, t_liststack *a, t_liststack *b, int size)
{
	int		index[2];
	int		min_to_top_up;
	int		moved;

	find_max_and_int(arr, size, index);
	min_to_top_up = index[1];
	moved = 0;
	while (min_to_top_up != 0)
	{
		rb(b, 1);
		min_to_top_up--;
		moved++;
	}
	pa(a, b);
	while (moved != 0)
	{
		rrb(b, 1);
		moved--;
	}
}

int		*make_int_list(t_liststack *stack)
{
	int		*arr;
	int		size;
	t_list	*temp;
	t_list	*temp2;
	int		index;

	temp = top_list(stack);
	temp2 = top_list(stack);
	size = stack->size;
	if (!(arr = malloc(sizeof(int) * size)))
		return (NULL);
	index = 0;
	temp = top_list(stack);
	while (index < size)
	{
		arr[index] = temp->data;
		index++;
		temp = temp->next;
	}
	return (arr);
}
