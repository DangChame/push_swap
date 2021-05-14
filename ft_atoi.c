/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:18:51 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 22:21:49 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ck_spa(const char s)
{
	if (s == '\t' || s == '\n' || s == '\v' || s == '\f' || s == '\r'
			|| s == ' ')
		return (1);
	return (-1);
}

long int	make_ten(int nb)
{
	long int	out;

	out = 1;
	while (nb-- > 0)
	{
		out = out * 10;
	}
	return (out);
}

long int	make_nb(const char *s, int ini, int last, int m_count)
{
	long int	out;

	out = 0;
	while (ini <= last)
	{
		out = out + (s[ini] - 48) * make_ten(last - ini);
		ini++;
	}
	if (m_count == 1)
		out = out * -1;
	return (out);
}

long int	ft_atoi(const char *s)
{
	int i;
	int	m_count;
	int index;

	i = 0;
	m_count = 0;
	while (ck_spa(s[i]) == 1)
		i++;
	if (!(s[i] == '+' || s[i] == '-' || ('0' <= s[i] && s[i] <= '9')))
		return (0);
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			m_count = 1;
		i++;
	}
	index = i;
	while ('0' <= s[i] && s[i] <= '9')
		i++;
	return (make_nb(s, index, i - 1, m_count));
}
