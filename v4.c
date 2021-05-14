/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:00:09 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 22:45:51 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	find_low_3_move(int *arr, t_liststack *a, int *par)
{
	quicksort(arr, 0, a->size - 1);
	par[0] = arr[a->size / 3];
	par[1] = arr[a->size / 3 * 2];
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

void	move_a_to_b(int *arr, int size, t_liststack *s_a, t_liststack *s_b)
{
	int		index[4];
	int		result[4];
	int		result_index;
	int		temp_result_index;

	find_max_and_int(arr, size, index);
	save_index(result, size, index);
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
	move_a_to_b_util(result_index, s_a, s_b, temp_result_index);
}

void	v6(t_liststack *stack_a, t_liststack *stack_b)
{
	int		partion[2];
	int		*arr;
	int		nb_moved[3];
	int		temp[1];

	arr = make_int_list(stack_a);
	find_low_3_move(arr, stack_a, partion);
	free(arr);
	init_nbmoved(nb_moved);
	move_a_to_b_1_2(stack_a, stack_b, partion, nb_moved);
	move_2_to_b(stack_a, stack_b, arr, nb_moved);
	rotate_2_on_b(stack_b, partion);
	temp[0] = nb_moved[1];
	do_pa(stack_a, stack_b, temp);
	move_1_a_to_b(stack_a, stack_b, arr);
	rotate_1_on_b(stack_b, partion);
	temp[0] = nb_moved[0];
	do_pa(stack_a, stack_b, temp);
	move_0_a_to_b(stack_a, stack_b, arr);
	rotate_0_on_b(stack_b, partion);
	while (is_empty_stack_list(stack_b) != 1)
		pa(stack_a, stack_b);
}

int		check_sorted(t_liststack *stack_a)
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
