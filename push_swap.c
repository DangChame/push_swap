/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:24:34 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/11 18:06:28 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
void	print_stack(t_ListStack *a, t_ListStack	*b)
{
	t_list *temp;

		printf("@@@@@@@@@@@@@@@@\n");

	printf("stack a \n");
	temp = top_list(a);
	if (temp == NULL)
	{
		printf("stack_a is empty\n");
	}
	else
	{
		while (temp != NULL)
		{
			printf("%ld\n", temp->data);
			temp = temp->next;
		}
	}
	printf("stack b\n");
	temp = top_list(b);
	if (temp == NULL)
	{
		printf("stack_b is empty\n");
		return ;
	}
	while (temp != NULL)
	{
		printf("%ld\n", temp->data);
		temp = temp->next;
	}
	printf("@@@@@@@@@@@@@@@@\n");
}
int		main(int ac, char **av)
{
	t_ListStack	*stack_a;
	t_ListStack	*stack_b;

	if ((stack_a = make_stack(ac, av)) == NULL)
		return (0);
	if (check_int_error(stack_a) == -1)
		return (0);
	stack_b = create_list_stack();
	while (1)
	{
		while (is_empty_stack_list(stack_a) != 1)
		{
 			move_low(stack_b, stack_a);
		}
		while (is_empty_stack_list(stack_b) != 1)
		{
			move_high(stack_b, stack_a);
		}
		if (check_sorted(stack_a) == 1)
			break ;
	}



	print_stack(stack_a, stack_b);
	delete_stack_list(stack_a);
	delete_stack_list(stack_b);
}
