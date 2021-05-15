/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:22:25 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/15 12:41:38 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exec_4_case(t_liststack *a, t_liststack *b)
{
	int		*arr;

	arr = make_int_list(a);
	move_small(a, b, arr);
	free(arr);
	arr = make_int_list(a);
	move_small(a, b, arr);
	free(arr);
	if (top_list(a)->data > top_list(a)->next->data)
		sa(a, 1);
	pa(a, b);
	pa(a, b);
		print_stack(a, b);

}
