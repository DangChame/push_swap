/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:58:46 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 22:21:49 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		p_m_alone(char *s)
{
	int		index;
	int		nb_of_p_or_m;

	nb_of_p_or_m = 0;
	index = 0;
	while (s[index])
	{
		if (!(s[index] == '+' || s[index] == '-'))
			return (nb_of_p_or_m);
		if (s[index] == '+' || s[index] == '-')
			nb_of_p_or_m += 1;
		index++;
	}
	return (2);
}

int		check_p_or_m_alone(int ac, char **av)
{
	int		index;

	index = 1;
	while (index < ac)
	{
		if (p_m_alone(av[index]) >= 2)
			return (-1);
		index++;
	}
	return (1);
}
