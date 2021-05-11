/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:12:30 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/11 18:13:00 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_c(char to, char c)
{
	if (to == c)
		return (1);
	else
		return (0);
}

int		check_nb_to_mal(char const *s, char c)
{
	int index;
	int len;
	int out;

	out = 0;
	index = 0;
	while (s[index])
		index++;
	len = index;
	index = 0;
	while (s[index])
	{
		if (!check_c(s[index], c) && (check_c(s[index - 1], c)
				|| index == 0))
			out++;
		index++;
	}
	return (out);
}

int		ar_mal(char const *s, char c, int index3)
{
	int count;

	count = 0;
	while (check_c(s[index3], c) == 0 && s[index3] != '\0')
	{
		count++;
		index3++;
	}
	return (count + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		index;
	int		index2;
	int		index3;

	if (s == NULL)
		return (NULL);
	index = 0;
	index3 = 0;
	if (!(arr = (char **)malloc(sizeof(char *) * (check_nb_to_mal(s, c) + 1))))
		return (0);
	while (s[index3] && index < check_nb_to_mal(s, c))
	{
		index2 = 0;
		while (s[index3] == c)
			index3++;
		if (!(arr[index] = (char *)malloc(sizeof(char) * ar_mal(s, c, index3))))
			return (0);
		while (check_c(s[index3], c) == 0 && s[index3])
			arr[index][index2++] = s[index3++];
		arr[index][index2] = '\0';
		index++;
	}
	arr[index] = NULL;
	return (arr);
}
