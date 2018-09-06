/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranktools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:37:40 by tdiaz             #+#    #+#             */
/*   Updated: 2018/09/05 10:37:43 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	setrank(int *arr, t_stack **a, int size)
{
	int	**rank;

	revarr(arr, size);
	rank = rankmake(arr, size);
	attachrank(rank, a, size);
	free_arr((void**)rank, size);
}

void	ranker(int *arr, int size, int ***rank)
{
	int i;
	int j;

	buildheap(arr, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if ((*rank)[i][0] == arr[j])
			{
				(*rank)[i][1] = j;
				j = size;
			}
			else
				j++;
		}
		i++;
	}
}

int		**rankmake(int *arr, int size)
{
	int	**rank;
	int	i;

	i = -1;
	rank = (int**)malloc(sizeof(int*) * size);
	while (++i < size)
	{
		rank[i] = (int*)malloc(sizeof(int) * 2);
		rank[i][0] = arr[i];
		rank[i][1] = arr[i];
	}
	ranker(arr, size, &rank);
	return (rank);
}

void	revarr(int *arr, int size)
{
	int i;
	int j;
	int tmp;

	i = -1;
	j = size - 1;
	while (++i < size / 2)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		j--;
	}
}

void	attachrank(int **rank, t_stack **a, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = (*a);
	while ((*a)->down != tmp)
	{
		i = 0;
		while (i < size)
		{
			if (rank[i][0] == (*a)->data)
				(*a)->rank = rank[i][1];
			i++;
		}
		(*a) = (*a)->down;
	}
	i = 0;
	while (i < size)
	{
		if (rank[i][0] == (*a)->data)
			(*a)->rank = rank[i][1];
		i++;
	}
	(*a) = (*a)->down;
}
