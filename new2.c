/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:07:28 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 18:08:41 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_b_to_a(int *arr, int size, t_ListStack *s_a, t_ListStack *s_b)
{
	int		index[2];
	int		result[4];
	int		result_index;
	int		temp_result_index;

	
	find_max_and_int(arr, size, index);
	result[0] = index[0];
	result[1] = index[1];
	result[2] = size - 1 - index[0] + 1;
	result[3] = size - 1 - index[1] + 1;
	result_index = find_lowest(result);
	temp_result_index = result[result_index];
	if (result_index == 3 || result_index == 2)
	{
		while (temp_result_index != 0)
		{
			rrb(s_b, 1);
			temp_result_index--;
		}
	}
	else if (result_index == 0 || result_index == 1)
	{
		while (temp_result_index != 0)
		{
			rb(s_b, 1);
			temp_result_index--;
		}
	}
	pa(s_a, s_b);
	if (result_index == 0 || result_index == 2)
		ra(s_a, 1);
}

void	move_b_to_a_large(int *arr, int size, t_ListStack *a, t_ListStack *b)
{
	int		index[2];
	int		max_to_top_up;
	int		max_to_top_down;

	find_max_and_int(arr, size, index);
	max_to_top_up = index[1];
	max_to_top_down = size - 1 - index[1] + 1;
	if (max_to_top_down < max_to_top_up)
	{
		while (max_to_top_down != 0)
		{
			rrb(b, 1);
			max_to_top_down--;
		}
	}
	else
	{
		while (max_to_top_up != 0)
		{
			rb(b, 1);
			max_to_top_up--;
		}
	}
	pa(a, b);
}

void	move_a_to_b_small(int *arr, int size, t_ListStack *a, t_ListStack *b)
{
	int		index[2];
	int		min_to_top_up;
	int		min_to_top_down;

	find_max_and_int(arr, size, index);
	min_to_top_up = index[0];
	min_to_top_down = size - 1 - index[0] + 1;
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

void	v2(t_ListStack *stack_a, t_ListStack *stack_b)
{
	int		half_size;
	int		temp;
	int		*arr;

	half_size = stack_a->size / 2;
	temp = half_size;
	while (temp >= 0)
	{
		pb(stack_a, stack_b);
		temp--;
	}
		print_stack(stack_a, stack_b);
	half_size = stack_b->size;
	while (is_empty_stack_list(stack_b) != 1)
	{
		arr = make_int_list(stack_b);
		move_b_to_a_large(arr, stack_b->size, stack_a, stack_b);
		free(arr);
	}
	while (half_size != 0)
	{
		pb(stack_a, stack_b);
		half_size--;
	}
	while (is_empty_stack_list(stack_a) != 1)
	{
		arr = make_int_list(stack_a);
		move_a_to_b_small(arr, stack_a->size, stack_a, stack_b);
		free(arr);
	}
	arr = make_int_list(stack_b);
	max_to_top(arr, stack_b);
	free(arr);
	while (is_empty_stack_list(stack_b) != 1)
		pa(stack_a, stack_b);
}