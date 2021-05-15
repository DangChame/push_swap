/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:22:25 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/15 14:43:30 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exec_4_case(t_liststack *a, t_liststack *b)
{
	int		*arr;

	arr = make_int_list(a);
	move_small(a, b, arr);
	free(arr);
	arr = make_int_list(a);
	move_small(a, b, arr);
	free(arr);
	if (top_list(a)->data > top_list(a)->next->data)
		sa(a, 1);
	pa(a, b);
	pa(a, b);
}

void	exec_3_case_b(t_liststack *b)
{
	int		nb[4];

	nb[0] = b->top->data;
	nb[1] = b->top->next->data;
	nb[2] = b->top->next->next->data;
	if (nb[0] < nb[2] && nb[2] < nb[1])
		rb(b, 1);
	else if (nb[1] < nb[0] && nb[0] < nb[2])
		rrb(b, 1);
	else if (nb[2] < nb[0] && nb[0] < nb[1])
		sb(b, 1);
	else if (nb[2] > nb[1] && nb[1] > nb[0])
	{
		sb(b, 1);
		rrb(b, 1);
	}
	else if (nb[1] < nb[2] && nb[2] < nb[0])
	{
		rrb(b, 1);
		sb(b, 1);
	}
}

void	exec_6_case(t_liststack *a, t_liststack *b)
{
	int		*arr;
	int		iter;

	iter = 3;
	while (iter != 0)
	{
		arr = make_int_list(a);
		move_small(a, b, arr);
		free(arr);
		iter--;
	}
	exec_3_case(a);
	if (check_sorted(b) == -1)
		exec_3_case_b(b);
	pa(a, b);
	pa(a, b);
	pa(a, b);
}
