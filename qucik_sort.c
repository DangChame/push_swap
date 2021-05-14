/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qucik_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchoi <cchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:51:32 by cchoi             #+#    #+#             */
/*   Updated: 2021/05/14 11:52:42 by cchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void swap(int *A, int low, int high)
{
	int temp;

	temp = A[low];
	A[low] = A[high];
	A[high] = temp;
}

int Partition(int *A, int left, int right)
{
	int low;
	int	high;
	int	pivot_item;
	
	pivot_item = A[left];
	low = left;
	high = right;
	while(low < high)
	{
		while(low<=right && A[low] <= pivot_item)
			low++;
		while(left<=high && A[high] > pivot_item)
			high--;
		if(low < high)
			swap(A, low, high);
	}
	A[left] = A[high];
	A[high] = pivot_item;
	return high;
}

void QuickSort(int *A, int left, int right)
{
	int pivot;

	if(left < right)
	{
		pivot = Partition(A, left, right);
		QuickSort(A, left, pivot-1);
		QuickSort(A, pivot+1, right);
	}
}