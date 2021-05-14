/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:38:01 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 11:54:45 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	find_low_3_move(int *arr, t_ListStack *a, t_ListStack *b)
{
	int		partion_index;

	QuickSort(arr, 0, a->size - 1);
	
}
void	v3(t_ListStack *stack_a, t_ListStack *stack_b)
{
	int		size_3;
	int		temp;
	int		*arr;


	arr = make_int_list(stack_a);
	move_b_to_a_large(arr, stack_b->size, stack_a, stack_b);
	free(arr);

}