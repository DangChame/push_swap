/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 00:57:29 by cchoi             #+#    #+#             */
/*   Updated: 2021/04/14 00:57:29 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ra(t_ListStack *stack_a)
{
	int		data;
	t_list	*first;
	t_list	*last_before;
	t_list	*last;

	last_before = stack_a->top;
	first = stack_a->top;
	while (last_before->next->next != NULL)
	{
		last_before = last_before->next;
	}
	last = last_before->next;
	last_before->next = first;
	stack_a->top = last;

	
}