/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:24:34 by cchoi             #+#    #+#             */
/*   Updated: 2021/04/14 19:04:20 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_ListStack	*stack_a;
	t_ListStack	*stack_b;

	stack_a = make_stack(ac, av);

	if (check_int_error(stack_a) == -1)
		return (0);
	stack_b = create_list_stack();
	pb(stack_a, stack_b);
		pb(stack_a, stack_b);
	pb(stack_a, stack_b);

	rrb(stack_b, 1);


	printf("stack a\n");
	while (is_empty_stack_list(stack_a) != 1)
		printf("%ld\n", pop_list(stack_a));

	printf("stack b\n");
	while (is_empty_stack_list(stack_b) != 1)
		printf("%ld\n", pop_list(stack_b));

}
