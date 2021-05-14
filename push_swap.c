/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:24:34 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 23:21:00 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_stack(t_liststack *a, t_liststack	*b)
{
	t_list *temp;

	printf("@@@@@@@@@@@@@@@@mmmmmmmmmmmmm\n");
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
	printf("@@@@@@@@@@@@@@@@mmmmmmmmmmmm\n");
}

int		main(int ac, char **av)
{
	t_liststack	*stack_a;
	t_liststack	*stack_b;

	if ((stack_a = make_stack(ac, av)) == NULL)
		return (0);
	if (check_int_error(stack_a) == -1)
		return (0);
	if (check_sorted(stack_a) == 1)
		return (0);
	stack_b = create_list_stack();
	v6(stack_a, stack_b);
/* 	print_stack(stack_a, stack_b);
 */	delete_stack_list(stack_a);
	delete_stack_list(stack_b);
}
