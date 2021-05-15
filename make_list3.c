/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 15:15:28 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/15 15:15:53 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			make_stack2(int ac, char **av, int index, t_liststack *s)
{
	int		data;

	if (check_all_int(ac, av) == -1 || check_p_or_m_alone(ac, av) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	while (index >= 1)
	{
		if (check_nb_next_c(av[index]) == -1)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		data = ft_atoi(av[index]);
		push_list(s, data);
		index--;
	}
	return (1);
}
