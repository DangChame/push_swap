/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:31:40 by cchoi             #+#    #+#             */
/*   Updated: 2021/04/15 17:07:03 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_ListStack	*create_list_stack(void)
{
	t_ListStack	*stk;
	if (!(stk = (t_ListStack *)malloc(sizeof(t_ListStack))))
	{
		write(2, "malloc error\n", 13);
		return (NULL);
	}
	stk->top = NULL;
	return (stk);
}

int			push_list(t_ListStack *stk, long int data)
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
	return (1);
}

int			is_empty_stack_list(t_ListStack *stk)
{
	return (stk->top == NULL);
}

long int	pop_list(t_ListStack *stk)
{
	long int	data;
	t_list		*temp;

	if (is_empty_stack_list(stk))
		return (-1);
	temp = stk->top;
	stk->top = stk->top->next;
	data = temp->data;
	free(temp);
	return (data);
}

t_list		*top_list(t_ListStack *stk)
{
	if (is_empty_stack_list(stk))
		return (NULL);
	return (stk->top);
}

void		delete_stack_list(t_ListStack *stk)
{
	t_list	*temp;
	t_list	*p;

	p = stk->top;
	while (p)
	{
		temp = p->next;
		free(p);
		p = temp;
	}
	free(stk);
}

t_ListStack	*make_stack(int ac, char **av)
{
	int			index;
	t_ListStack	*stack;
	long int	data;

	if (check_all_int(ac, av) == -1 || check_p_or_m_alone(ac, av) == -1)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	index = ac - 1;
	stack = create_list_stack();
	while (index >= 1)
	{
		data = ft_atoi(av[index]);
		push_list(stack, data);
		index--;
	}
	return (stack);
}
