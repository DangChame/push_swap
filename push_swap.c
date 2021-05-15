/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:24:34 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/15 14:57:40 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exec_3_case(t_liststack *a)
{
	int		nb[4];

	nb[0] = a->top->data;
	nb[1] = a->top->next->data;
	nb[2] = a->top->next->next->data;
	if (nb[0] < nb[2] && nb[2] < nb[1])
	{
		ra(a, 1);
		sa(a, 1);
		rra(a, 1);
	}
	else if (nb[1] < nb[0] && nb[0] < nb[2])
		sa(a, 1);
	else if (nb[2] < nb[0] && nb[0] < nb[1])
		rra(a, 1);
	else if (nb[2] < nb[1] && nb[1] < nb[0])
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (nb[1] < nb[2] && nb[2] < nb[0])
		ra(a, 1);
}

int		find_middle(int *arr)
{
	int		temp;

	quicksort(arr, 0, 4);
	temp = arr[2];
	return (temp);
}

void	exec_5_case(t_liststack *a, t_liststack *b)
{
	int		*arr;
	int		middle;
	int		iter;

	arr = make_int_list(a);
	middle = find_middle(arr);
	free(arr);
	iter = 5;
	while (iter-- > 0)
	{
		if (a->top->data < middle)
			pb(a, b);
		else
			ra(a, 1);
	}
	exec_3_case(a);
	if (b->top->data < b->top->next->data)
		sb(b, 1);
	pa(a, b);
	pa(a, b);
}

int		check_small_case(t_liststack *a, t_liststack *b)
{
	if (2 <= a->size && a->size <= 6)
	{
		if (a->size == 2)
			ra(a, 1);
		else if (a->size == 3)
				exec_3_case(a);
		else if (a->size == 4)
			exec_4_case(a, b);
		else if (a->size == 5)
			exec_5_case(a, b);
		else if (a->size == 6)
			exec_6_case(a, b);
		return (777);
	}
	return (-1);
}

int		main(int ac, char **av)
{
	t_liststack	*stack_a;
	t_liststack	*stack_b;

	if (ac == 1)
		return (0);
	if ((stack_a = make_stack(ac, av)) == NULL)
		return (0);
	if (check_int_error(stack_a) == -1)
		return (0);
	if (check_sorted(stack_a) == 1)
		return (0);
	stack_b = create_list_stack();
	if (check_small_case(stack_a, stack_b) == 777)
		return (0);
	v6(stack_a, stack_b);
	delete_stack_list(stack_a);
	delete_stack_list(stack_b);
}
