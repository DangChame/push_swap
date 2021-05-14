/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:51:32 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 22:21:49 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(int *a, int low, int high)
{
	int temp;

	temp = a[low];
	a[low] = a[high];
	a[high] = temp;
}

int		partition(int *a, int left, int right)
{
	int low;
	int	high;
	int	pivot_item;

	pivot_item = a[left];
	low = left;
	high = right;
	while (low < high)
	{
		while (low <= right && a[low] <= pivot_item)
			low++;
		while (left <= high && a[high] > pivot_item)
			high--;
		if (low < high)
			swap(a, low, high);
	}
	a[left] = a[high];
	a[high] = pivot_item;
	return (high);
}

void	quicksort(int *a, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(a, left, right);
		quicksort(a, left, pivot - 1);
		quicksort(a, pivot + 1, right);
	}
}
