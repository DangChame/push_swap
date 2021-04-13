/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:38:53 by cchoi             #+#    #+#             */
/*   Updated: 2021/04/13 17:27:29 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_nb(char c)
{
	if (!('0' <= c && c <= '9'))
		return (-1);
	else
		return (1);
}

int		check_int(char *s)
{
	int		index;

	index = 0;
	while (s[index])
	{
		if (check_nb(s[index]) == -1)
			return (-1);
		index++;
	}
	return (1);
}

int		check_all_int(int ac, char **av)
{
	int			index;

	index = 1;
	while (index < ac)
	{
		if (check_int(av[index]) == -1)
			return (-1);
		index++;
	}
	return (1);
}

int		check_twice(t_ListStack *stack)
{
	int		data;
	t_list	*temp1;
	t_list	*temp2;

	temp1 = stack->top;
	while (temp1->next != NULL)
	{
		data = temp1->data;
		temp2 = temp1->next;
		while (temp2 != NULL)
		{
			if (data == temp2->data)
				return (-1);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (1);
}