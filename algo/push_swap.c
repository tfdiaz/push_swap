/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 18:04:12 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/20 18:04:18 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	shortsorthelp(t_stack **a, t_stack **b, int size, int bigrank)
{
	while (issort(*a, NULL) != 1)
	{
		if ((*a)->rank > (*a)->down->rank && (*a)->rank <= size - 2)
			prtswap(a, "sa\n");
		else
			prtrot(a, "ra\n");
	}
	while (*b != NULL)
	{
		if ((*b)->rank == bigrank)
		{
			prtpush(a, b, "pa\n");
			bigrank--;
		}
		else
			prtrot(b, "rb\n");
	}
}

void	shortsort(t_stack **a, t_stack **b, int size)
{
	int i;
	int bigrank;

	i = 0;
	bigrank = 0;
	if (size > 3)
	{
		while (i < size || countstacks(*b) > 2)
		{
			if ((*a)->rank < size / 2)
			{
				if ((*a)->rank > bigrank)
					bigrank = (*a)->rank;
				prtpush(b, a, "pb\n");
			}
			else
				prtrot(a, "ra\n");
			i++;
		}
	}
	shortsorthelp(a, b, size, bigrank);
}

void	sorta(int *arr, int size)
{
	int			**rank;
	int			bound[2];
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	makestack(&a, arr, size);
	if (issort(a, b))
	{
		free_stack(&a);
		free(arr);
		return ;
	}
	setrank(arr, &a, size);
	bound[0] = 0;
	bound[1] = size;
	if (size < 6)
		shortsort(&a, &b, size);
	else
		sortwhole(&a, &b, bound, 1);
	freebothst(&a, &b);
	free(arr);
}

int		main(int argc, char **argv)
{
	int		*arr;
	char	**strs;
	int		flag;
	int		size;

	if (argc > 1)
	{
		if (argc == 2)
		{
			strs = ft_strsplit(argv[1], ' ');
			size = strlenarr(strs);
		}
		else
		{
			strs = argv + 1;
			size = argc - 1;
		}
		arr = arrbuild(strs, size);
		if (arr)
			sorta(arr, size);
		else
			ft_printf("Error\n");
		if (argc == 2)
			free_arr((void**)strs, size);
	}
}
