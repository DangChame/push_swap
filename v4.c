/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:00:09 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 18:22:15 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_a_to_b_1_2(t_ListStack *a, t_ListStack *b, int *par, int *nb)
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

void	move_small(t_ListStack *a, t_ListStack *b, int *arr)
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
void	move_small_b_to_a(int *arr, t_ListStack *a, t_ListStack *b, int size)
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

void	v4(t_ListStack *stack_a, t_ListStack *stack_b)
{
	int		partion[2];
	int		*arr;
	int		nb_moved[3];
	
	arr = make_int_list(stack_a);
	find_low_3_move(arr, stack_a, partion);
	free(arr);
	printf("par0 is %d par1 is %d\n", partion[0], partion[1]);
	nb_moved[0] = 0;
	nb_moved[1] = 0;
	nb_moved[2] = 0;
	move_a_to_b_1_2(stack_a, stack_b, partion, nb_moved);
	while (is_empty_stack_list(stack_a) != 1)
	{
		arr = make_int_list(stack_a);
		move_small(stack_a, stack_b, arr);
		free(arr);
		nb_moved[2] += 1;
	}
	while (nb_moved[2] != 0)
	{
		pa(stack_a, stack_b);
		nb_moved[2]--;
	}
	while (nb_moved[1] != 0)
	{
		arr = make_int_list(stack_b);
		move_small_b_to_a(arr, stack_a, stack_b, nb_moved[1]);
		free(arr);
		nb_moved[1]--;
	}

	
	while (nb_moved[0] != 0)
	{
		arr = make_int_list(stack_b);
		move_small_b_to_a(arr, stack_a, stack_b, nb_moved[0]);
		free(arr);
		nb_moved[0]--;
	}
}

void	v5(t_ListStack *stack_a, t_ListStack *stack_b)
{
	int		partion[2];
	int		*arr;
	int		nb_moved[3];
	int		temp;
	
	arr = make_int_list(stack_a);
	find_low_3_move(arr, stack_a, partion);
	free(arr);
	nb_moved[0] = 0;
	nb_moved[1] = 0;
	nb_moved[2] = 0;
	move_a_to_b_1_2(stack_a, stack_b, partion, nb_moved);
	while (is_empty_stack_list(stack_a) != 1)
	{
		arr = make_int_list(stack_a);
		move_small(stack_a, stack_b, arr);
		free(arr);
		nb_moved[2] += 1;
	}
	while (nb_moved[2] != 0)
	{
		pa(stack_a, stack_b);
		nb_moved[2]--;
	}
	temp = nb_moved[1];
	while (nb_moved[1] != 0)
	{
		pa(stack_a, stack_b);
		nb_moved[1]--;
	}
	while (is_empty_stack_list(stack_b) != 1)
	{
		arr = make_int_list(stack_b);
		move_b_to_a(arr, stack_b->size, stack_a, stack_b);
		free(arr);
	}
	while (-2147483648 <= top_list(stack_a)->data && top_list(stack_a)->data <= partion[0])
	{
		ra(stack_a, 1);
	}
	while (temp != 0)
	{
		pb(stack_a, stack_b);
		temp--;
	}
	while (is_empty_stack_list(stack_b) != 1)
	{
		arr = make_int_list(stack_b);
		move_b_to_a(arr, stack_b->size, stack_a, stack_b);
		free(arr);
	}
	while (partion[0] < top_list(stack_a)->data && top_list(stack_a)->data <= partion[1])
	{
		ra(stack_a, 1);
	}
	while (partion[1] < top_list(stack_a)->data && top_list(stack_a)->data <= 2147483648)
	{
		ra(stack_a, 1);
	}
}