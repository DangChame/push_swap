/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:31:40 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 22:21:49 by cchoi            ###   ########.fr       */
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

t_liststack	*make_stack(int ac, char **av)
{
	int			index;
	t_liststack	*stack;
	long int	data;
	char		**temp;

/* 	if (check_all_int(ac, av) == -1 || check_p_or_m_alone(ac, av) == -1)
	{
		write(2, "Error\n", 6);
		return (NULL);
	} */
	index = ac - 1;
	stack = create_list_stack();
	if (ac == 2)
	{
		temp = ft_split(av[1], ' ');
		index = check_nb_to_mal(av[1], ' ') - 1;
		while (index >= 0)
		{
			data = ft_atoi(temp[index]);
			push_list(stack, data);
			index--;
		}
	}
	else
	{
		while (index >= 1)
		{
			data = ft_atoi(av[index]);
			push_list(stack, data);
			index--;
		}
	}
	return (stack);
}
