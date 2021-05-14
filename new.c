/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:06:47 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 21:20:44 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int		find_lowest(int *result)
{
	int		index;
	int		low_index;

	index = 0;
	low_index = 0;
	while (index < 4)
	{
		if (result[low_index] > result[index])
		{
			low_index = index;
		}
		index++;
	}
	return (low_index);
}
void	move_a_to_b(int *arr, int size, t_ListStack *s_a, t_ListStack *s_b)
{
	int		index[4];
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
			rra(s_a, 1);
			temp_result_index--;
		}
	}
	else if (result_index == 0 || result_index == 1)
	{
		while (temp_result_index != 0)
		{
			ra(s_a, 1);
			temp_result_index--;
		}
	}
	pb(s_a, s_b);
	if (result_index == 1 || result_index == 3)
		rb(s_b, 1);
}
//this is for v5
/* void	move_a_to_b(int *arr, int size, t_ListStack *s_a, t_ListStack *s_b)
{
	int		index[4];
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
			rra(s_a, 1);
			temp_result_index--;
		}
	}
	else if (result_index == 0 || result_index == 1)
	{
		while (temp_result_index != 0)
		{
			ra(s_a, 1);
			temp_result_index--;
		}
	}
	pb(s_a, s_b);
	if (result_index == 0 || result_index == 2)
		rb(s_b, 1);
} */

int 	*make_int_list(t_ListStack *stack)
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

void	max_to_top(int *arr, t_ListStack *s_b)
{
	int		index;
	int		max_index;

	index = 0;
	max_index = 0;
	while (index < s_b->size)
	{
		if (arr[max_index] < arr[index])
			max_index = index;
		index++;
	}
	while (max_index > 0)
	{
		rb(s_b, 1);
		max_index--;
	}
}
