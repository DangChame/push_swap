/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:35:32 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 22:45:16 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate_0_on_b(t_liststack *s, int *partion)
{
	while (-2147483648 <= top_list(s)->data
		&& top_list(s)->data <= partion[0])
	{
		rb(s, 1);
	}
}

void	move_1_a_to_b(t_liststack *a, t_liststack *b, int *arr)
{
	while (is_empty_stack_list(a) != 1)
	{
		arr = make_int_list(a);
		move_a_to_b(arr, a->size, a, b);
		free(arr);
	}
}

void	move_0_a_to_b(t_liststack *a, t_liststack *b, int *arr)
{
	while (is_empty_stack_list(a) != 1)
	{
		arr = make_int_list(a);
		move_a_to_b(arr, a->size, a, b);
		free(arr);
	}
}

void	init_nbmoved(int *nb_moved)
{
	nb_moved[0] = 0;
	nb_moved[1] = 0;
	nb_moved[2] = 0;
}

void	do_pa(t_liststack *a, t_liststack *b, int *temp)
{
	while (temp[0] != 0)
	{
		pa(a, b);
		temp[0]--;
	}
}
