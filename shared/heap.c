/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 16:28:54 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/21 16:29:08 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swapint(int *arr, int first, int second)
{
	int tmp;

	tmp = arr[first];
	arr[first] = arr[second];
	arr[second] = tmp;
}

void	maxheap(int *arr, int size, int i)
{
	int root;
	int left;
	int right;

	root = i;
	left = i * 2 + 1;
	right = i * 2 + 2;
	if (left < size && arr[left] > arr[root])
		root = left;
	if (right < size && arr[right] > arr[root])
		root = right;
	if (root != i)
	{
		swapint(arr, i, root);
		maxheap(arr, size, root);
	}
}

void	buildheap(int *arr, int size)
{
	int i;
	int tmp;

	i = size / 2 - 1;
	while (i >= 0)
	{
		maxheap(arr, size, i);
		i--;
	}
	i = size - 1;
	while (i >= 0)
	{
		swapint(arr, 0, i);
		maxheap(arr, i, 0);
		i--;
	}
}
