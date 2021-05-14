/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:38:01 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 16:52:09 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	find_max_min_part(int *arr, int size, int *index_arr, int *par)
{
	int		min;
	int		max;
	int		index;

	index = 0;
	min = 0;
	max = 0;

	while (index < size)
	{
		if (arr[index] <= arr[min] && arr[index] >= par[0]) /* && arr[index] <= par[1]) */
			min = index;
		if (arr[index] >= arr[min] && arr[index] <= par[1]) /* && arr[index] >= par[0]) */
			max = index;
		index++;
	}
	index_arr[0] = min;
	index_arr[1] = max;
}


void	move_b_to_a_small(int *arr, int size, t_ListStack *a, t_ListStack *b)
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
			rrb(b, 1);
			min_to_top_down--;
		}
	}
	else
	{
		while (min_to_top_up != 0)
		{
			rb(b, 1);
			min_to_top_up--;
		}
	}
	pa(a, b);
}

void	find_low_3_move(int *arr, t_ListStack *a, int *par)
{
	QuickSort(arr, 0, a->size - 1);
	par[0] = arr[a->size / 3];
	par[1] = arr[a->size / 3 * 2];
}

void	move_a_to_b_low_3(int *arr, t_ListStack *a, t_ListStack *b, int *par)
{
	int		min_max[2];
	int		result[4];
	int		result_index;
	int		temp_result_index;

	find_max_min_part(arr, a->size, min_max, par);
	result[0] = min_max[0];
	result[1] = min_max[1];
	result[2] = a->size - 1 - min_max[0] + 1;
	result[3] = a->size - 1 - min_max[1] + 1;
	result_index = find_lowest(result);
	temp_result_index = result[result_index];
	if (result_index == 3 || result_index == 2)
	{
		while (temp_result_index != 0)
		{
			rra(a, 1);
			temp_result_index--;
		}
	}
	else if (result_index == 0 || result_index == 1)
	{
		while (temp_result_index != 0)
		{
			ra(a, 1);
			temp_result_index--;
		}
	}
	pb(a, b);
	if (result_index == 0 || result_index == 2)
		rb(b, 1);

}

void	find_in_partion(int *arr, int size, int *index_arr, int *par)
{
	int		min;
	int		max;
	int		index;
	int		out;

	index = 0;
	min = 0;
	max = 0;
	if ((par[0] <= arr[index] && arr[index] <= par[1]))
		out = 0;
	else
		out = 2147483647;
	while (index < size)
	{
		if ((par[0] <= arr[index] && arr[index] <= par[1]) && out > index)
			out = index;
		if (arr[index] >= arr[min] && arr[index] <= par[1]) /* && arr[index] >= par[0]) */
			max = index;
		index++;
	}
	index_arr[0] = out;
	index_arr[1] = max;
}

void	move_a_to_b_middle(int *arr, t_ListStack *a, t_ListStack *b, int *par)
{
	int		index[2];
	int		min_to_top_up;
	int		min_to_top_down;

	find_in_partion(arr, a->size, index, par);
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

void	v3(t_ListStack *stack_a, t_ListStack *stack_b)
{
	int		partion[2];
	int		*arr;
	int		temp_par[2];
	int		temp;
	int		a_size;


	arr = make_int_list(stack_a);
	find_low_3_move(arr, stack_a, partion);
	free(arr);
	a_size = stack_a->size;
	temp_par[0] = -2147483648;
	temp_par[1] = partion[0];
	temp = a_size/ 3;

	while (temp >= 0)
	{
		arr = make_int_list(stack_a);
		move_a_to_b_low_3(arr, stack_a, stack_b, temp_par);
		free(arr);
		temp--;
	}
	while (is_empty_stack_list(stack_b) != 1)
	{
		arr = make_int_list(stack_b);
		move_b_to_a_small(arr, stack_b->size, stack_a, stack_b);
		free(arr);
		temp++;
	}
	while (temp >= 0)
	{
		ra(stack_a, 1);
		temp--;
	}


/* 	temp = a_size / 3 * 2 - a_size / 3;
	temp_par[0] = partion[0];
	temp_par[1] = partion[1];
	while (temp >= 0)
	{
		arr = make_int_list(stack_a);
		move_a_to_b_low_3(arr, stack_a, stack_b, temp_par);
		free(arr);
		temp--;
	}
		print_stack(stack_a, stack_b); */

	temp = a_size / 3 * 2 - a_size / 3;
	temp_par[0] = partion[0];
	temp_par[1] = partion[1];
	while (temp >= 0)
	{
		arr = make_int_list(stack_a);
		move_a_to_b_middle(arr, stack_a, stack_b, temp_par);
		free(arr);
		temp--;
	}

	while (is_empty_stack_list(stack_b) != 1)
	{
		arr = make_int_list(stack_b);
		move_b_to_a_small(arr, stack_b->size, stack_a, stack_b);
		free(arr);
		temp++;
	}
	while (temp >= 0)
	{
		ra(stack_a, 1);
		temp--;
	}
	arr = make_int_list(stack_a);

	find_max_and_int(arr, stack_a->size, temp_par);
	temp = temp_par[0];
	free(arr);
	while (temp >= 0)
	{
		ra(stack_a, 1);
		temp--;
	}
	temp = stack_a->size;
	while (temp >= 0)
	{
		if (top_list(stack_a)->data > partion[1])
			pb(stack_a, stack_b);
		temp--;
	}
/* 	temp = a_size  - a_size / 3 * 2;
	temp_par[0] = partion[1];
	temp_par[1] = 2147483647;

	while (temp >= 0)
	{
		arr = make_int_list(stack_a);
		move_a_to_b_middle(arr, stack_a, stack_b, temp_par);
		free(arr);
		temp--;
	} */
	while (is_empty_stack_list(stack_b) != 1)
	{
		arr = make_int_list(stack_b);
		move_b_to_a_small(arr, stack_b->size, stack_a, stack_b);
		free(arr);
		temp++;
	}
	temp = top_list(stack_a)->data;
/* 	ra(stack_a, 1);
	while (temp != top_list(stack_a)->data)
		ra(stack_a, 1); */
/* 	while (temp >= 0)
	{
		ra(stack_a, 1);
		temp--;
	} */

}