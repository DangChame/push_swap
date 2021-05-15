/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:31:40 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/15 15:14:20 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list		*top_list(t_liststack *stk)
{
	if (is_empty_stack_list(stk))
		return (NULL);
	return (stk->top);
}

t_list		*bottom_list(t_liststack *stk)
{
	t_list	*temp;

	if (is_empty_stack_list(stk))
		return (NULL);
	temp = top_list(stk);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void		delete_stack_list(t_liststack *stk)
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

int			check_nb_next_c(char *s)
{
	int		index;
	int		len;

	len = 0;
	while (s[len])
		len++;
	index = 0;
	while (s[index] && index < len - 1)
	{
		if (('0' <= s[index] && s[index] <= '9') && (!('0' <= s[index + 1]
			&& s[index + 1] <= '9')))
			return (-1);
		index++;
	}
	return (1);
}

t_liststack	*make_stack(int ac, char **av)
{
	int			index;
	t_liststack	*stack;
 	char		**temp;

	index = ac - 1;
	stack = create_list_stack();
	if (ac == 2)
	{
		temp = NULL;
		if (make_stack3(temp, index, stack, av) == -1)
			return (NULL);
	}
	else
	{
		if (make_stack2(ac, av, index, stack) == -1)
			return (NULL);
	}
	return (stack);
}
