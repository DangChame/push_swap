/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:11:37 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 22:46:16 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	save_index(int *result, int size, int *index)
{
	result[0] = index[0];
	result[1] = index[1];
	result[2] = size - 1 - index[0] + 1;
	result[3] = size - 1 - index[1] + 1;
}

void	move_a_to_b_util(int ri, t_liststack *a, t_liststack *b, int tri)
{
	if (ri == 0 || ri == 1)
	{
		while (tri != 0)
		{
			ra(a, 1);
			tri--;
		}
	}
	pb(a, b);
	if (ri == 1 || ri == 3)
		rb(b, 1);
}

void	move_2_to_b(t_liststack *a, t_liststack *b, int *arr, int *nb_moved)
{
	while (is_empty_stack_list(a) != 1)
	{
		arr = make_int_list(a);
		move_a_to_b(arr, a->size, a, b);
		free(arr);
		nb_moved[2] += 1;
	}
}

void	rotate_2_on_b(t_liststack *s, int *partion)
{
	while (partion[1] < top_list(s)->data
		&& top_list(s)->data <= 2147483648)
	{
		rb(s, 1);
	}
}

void	rotate_1_on_b(t_liststack *s, int *partion)
{
	while (partion[0] < top_list(s)->data
		&& top_list(s)->data <= partion[1])
	{
		rb(s, 1);
	}
}
