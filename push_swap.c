/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:24:34 by cchoi             #+#    #+#             */
/*   Updated: 2021/04/14 01:16:19 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_ListStack	*stack_a;
	t_ListStack	*stack_b;

	stack_a = make_stack(ac, av);
	if (check_twice(stack_a) == -1)
	{
		write(2, "Error duple\n", 12);
		free(stack_a);
		return (0);
	}
	stack_b = create_list_stack();
	ra(stack_a);




	printf("stack a\n");
	while (is_empty_stack_list(stack_a) != 1)
		printf("%d\n", pop_list(stack_a));

	printf("stack b\n");
	while (is_empty_stack_list(stack_b) != 1)
		printf("%d\n", pop_list(stack_b));

}
