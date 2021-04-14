/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:38:53 by cchoi             #+#    #+#             */
/*   Updated: 2021/04/14 19:48:54 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_nb(char c)
{
	if (!(('0' <= c && c <= '9') || c == '-' || c == '+'))
		return (-1);
	else
		return (1);
}

int		check_int(char *s)
{
	int		index;

	index = 0;
	if (((s[index] == '-' || s[index] == '+') && s[index + 1] == '\0'))
		return (-1);
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
	long int	data;
	t_list		*temp1;
	t_list		*temp2;

	temp1 = stack->top;
	while (temp1->next != NULL)
	{
		data = temp1->data;
		temp2 = temp1->next;
		if (-2147483648 > data || 2147483647 < data)
			return (-2);
		while (temp2 != NULL)
		{
			if (data == temp2->data)
				return (-1);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	if (-2147483648 > temp1->data || 2147483647 < temp1->data)
		return (-2);
	return (1);
}

int		check_int_error(t_ListStack *stack_a)
{
	if (check_twice(stack_a) == -1)
	{
		write(2, "Error duple\n", 12);
		free(stack_a);
		return (-1);
	}
	else if (check_twice(stack_a) == -2)
	{
		write(2, "Error bigger than an integer \n", 30);
		free(stack_a);
		return (-1);
	}
	return (1);
}
