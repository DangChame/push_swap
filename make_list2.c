/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:50:02 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 22:21:49 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_liststack	*create_list_stack(void)
{
	t_liststack	*stk;

	if (!(stk = (t_liststack *)malloc(sizeof(t_liststack))))
	{
		write(2, "malloc error\n", 13);
		return (NULL);
	}
	stk->top = NULL;
	stk->size = 0;
	return (stk);
}

int			push_list(t_liststack *stk, long int data)
{
	t_list *temp;

	if (!(temp = (t_list *)malloc(sizeof(t_list))))
	{
		write(2, "malloc error\n", 13);
		return (-1);
	}
	temp->data = data;
	temp->next = stk->top;
	stk->top = temp;
	stk->size += 1;
	return (1);
}

int			is_empty_stack_list(t_liststack *stk)
{
	return (stk->top == NULL);
}

long int	pop_list(t_liststack *stk)
{
	long int	data;
	t_list		*temp;

	if (is_empty_stack_list(stk))
		return (-1);
	temp = stk->top;
	stk->top = stk->top->next;
	data = temp->data;
	free(temp);
	stk->size -= 1;
	return (data);
}
