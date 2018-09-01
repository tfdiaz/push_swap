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

#include "push_swap.h"

void	prtarr(int *arr, int size)
{
	int i;

	i = -1;
	while (++i < size)
		ft_printf("%i, ", arr[i]);
}

int	**rankmake(int *arr, int size)
{
	int **rank;
	int i;
	int j;

	i = -1;
	rank = (int**)malloc(sizeof(int*) * size);
	while (++i < size)
	{
		rank[i] = (int*)malloc(sizeof(int) * 2);
		rank[i][0] = arr[i];
		rank[i][1] = arr[i];
	}
	buildheap(arr, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (rank[i][0] == arr[j])
			{
				rank[i][1] = j;
				j = size;
			}
			else
				j++;
		}
		i++;
	}
	return (rank);
}

void	revarr(int *arr, int size)
{
	int i;
	int j;
	int tmp;

	i = -1;
	j = size - 1;
	while (++i < size/2)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		j--;
	}
}

int swapsn(int **arr, int size)
{
	int i;
	int zerox;
	int swapsn;

	i = 0;
	swapsn = 0;
	while (i < size)
	{
		if (arr[i][1] == 0)
			break ;
		i++;
	}
	zerox = i;
	while (i + 1 < size)
	{
		if (arr[i][1] > arr[i + 1][1])
			swapsn++;
		i++;
	}
	if (zerox != 0 && arr[size - 1][1] > arr[0][1])
		swapsn++;
	i = 0;
	while (i < zerox - 1)
	{
		if (arr[i][1] > arr[i + 1][1])
			swapsn++;
		i++;
	}
	return (swapsn);
}

void	sortc(t_stack **a, t_stack **b, int size, int bigrank)
{
	while (issort((*a), NULL) != 1)
	{
		if ((*a)->rank > (*a)->down->rank && (*a)->rank <= size - 2)
		{
			ft_printf("sa\n");
			swap_stack(a);
		}
		else
		{
			ft_printf("ra\n");
			rot_stack(a);
		}
	}
	while (*b != NULL)
	{
		if ((*b)->rank == bigrank)
		{
			ft_printf("pa\n");
			push_stack(a, b);
			bigrank--;
		}
		else
		{
			ft_printf("rb\n");
			rot_stack(b);
		}
	}
}

void	sortb(t_stack **a, t_stack **b, int size)
{
	int i;
	int varsize;
	int count;
	int swapnum;
	int	bigrank;
	t_stack *tmp;

	i = 0;
	count = size / 2;
	bigrank = 0;
	varsize = count;
	while (count > 2)
	{
		tmp = (*a)->up;
		while ((*a) != tmp)
		{
			if ((*a)->rank > (*a)->down->rank && (*a)->rank <= varsize - 2)
			{
				ft_printf("sa\n");
				swap_stack(a);
			}
			if ((*a)->rank > (*a)->down->rank && (*a)->down->rank > varsize)
			{
				ft_printf("sa\n");
				swap_stack(a);
			}
			if ((*a)->rank < varsize)
			{
				if (bigrank < (*a)->rank)
					bigrank = (*a)->rank;
				ft_printf("pb\n");
				push_stack(b, a);
				tmp = (*a)->up;
			}
			else
			{
				ft_printf("ra\n");
				rot_stack(a);
				if (issort(*a, *b))
					break ;
			}
		}
		if ((*a)->rank < varsize)
		{
			if (bigrank < (*a)->rank)
				bigrank = (*a)->rank;
			ft_printf("pb\n");
			push_stack(b, a);
		}
		count /= 2;
		varsize += count;
	}
	sortc(a, b, size, bigrank);
	//prt_stack(*a);
}

void	presetter(t_stack **st, int bound, int size, int flag)
{
	if ((*st)->rank > (*st)->down->rank && (*st)->rank <= bound - 2)
	{
		(flag) ? ft_printf("sa\n"): ft_printf("sb\n");
		swap_stack(st);
	}
	if ((*st)->rank > (*st)->down->rank && (*st)->down->rank >= bound && (*st)->down->rank <= size - 2)
	{
		(flag) ? ft_printf("sa\n"): ft_printf("sb\n");
		swap_stack(st);
	}
}

void	pusher(t_stack **st, t_stack **st2, int bound, int flag)
{
	if (flag && (*st)->rank < bound)
	{
		ft_printf("pb\n");
		push_stack(st2, st);
	}
	else if (!flag && (*st)->rank >= bound)
	{
		ft_printf("pa\n");
		push_stack(st2, st);
	}
	else
	{
		(flag) ? ft_printf("ra\n"): ft_printf("rb\n");
		rot_stack(st);
	}
}

void	quicky(t_stack **st, int size, int flag)
{
	int i;

	i = 0;
	if (flag)
	{
		while (issort((*st), NULL) != 1)
		{
			if (countstacks(*st) == 2)
			{
				ft_printf("sa\n");
				swap_stack(st);
				return ;
			}
			else if ((*st)->rank > (*st)->down->rank && (*st)->rank - (*st)->down->rank < size / 2 + 1) // && (*st)->rank <= size - 2 && (*st)->rank - (*st)->down->rank < size / 2 + 1
			{
				ft_printf("sa\n");
				swap_stack(st);
			}
			else if (i < 2) //size - bound - 2)
			{
				ft_printf("ra\n");
				rot_stack(st);
				i++;
			}
			else if (i >= 2 && i < 4) //size - bound - 2 && i < size + size - bound - bound - 4)
			{
				ft_printf("rra\n");
				revrot_stack(st);
				i++;
			}
			else if (i == 4)
			{
				ft_printf("ra\n");
				rot_stack(st);
				i++;
			}
			else if (i == 5)
			{
				ft_printf("rra\n");
				revrot_stack(st);
				i++;
			}
		}
	}
	else
	{
		while (nrevissort((*st), NULL, size) != 1) //nrevissort((*st), NULL, bound - 1) != 1
		{
			if (countstacks(*st) == 2)
			{
				ft_printf("sb\n");
				swap_stack(st);
				return ;
			}
			else if ((*st)->rank < (*st)->down->rank && (*st)->down->rank - (*st)->rank < size / 2 + 1) //&& (*st)->rank != 0  && (*st)->down->rank - (*st)->rank < size / 2 + 1
			{
				ft_printf("sb\n");
				swap_stack(st);
			}
			else if (i < 2)
			{
				ft_printf("rb\n");
				rot_stack(st);
				i++;
			}
			else if (i >= 2 && i < 4)
			{
				ft_printf("rrb\n");
				revrot_stack(st);
				i++;
			}
			else if (i == 4)
			{
				ft_printf("rb\n");
				rot_stack(st);
				i++;
			}
			else if (i == 5)
			{
				ft_printf("rrb\n");
				revrot_stack(st);
				i++;
			}
		}
	}
}

void	grabber(t_stack **a, t_stack **b, int size, int flag)
{
	int i;

	i = 0;
	if (flag)
	{
		if (size <= 4)
		{
			quicky(b, size, 0);
			while (i < size)
			{
				ft_printf("pa\n");
				push_stack(a, b);
				i++;
			}
			if (issort(*a, *b))
				return ;
			else
				grabber(a, b, size * 2, 1);
		}
		else
		{
			sortforce(a, b, size, 0);
		}
	}
	else
	{
		if (size <= 4)
		{
			quicky(a, size, 1);
			while (i < size)
			{
				ft_printf("pb\n");
				push_stack(b, a);
				i++;
			}
			grabber(a, b, countstacks(*b), 1);
		}
		else
			sortforce(a, b, size, 1);
	}
}

void	sortforce(t_stack **a, t_stack **b, int size, int flag)
{
	int tmp;
	int i;
	int count;

	if (flag)
		count = countstacks(*b);
	else
		count = (*a)->rank;
	if (size > 4)
	{
		i = 0;
		while (i < size)
		{
			(flag) ? pusher(a, b, size / 2 + count, 1): pusher(b, a, count - size / 2, 0);
			if (flag && issort(*a, *b))
				return ;
			i++;
		}
		sortforce(a, b, size / 2, flag);
	}
	else
		(flag) ? quicky(a, size, flag): quicky(b, size, flag);
	if (issort(*a, *b) != 1)
		grabber(a, b, size, flag);
}

void	a_sort4(t_stack **a, int bound[2])
{
	int i;

	i = 0;
//ft_printf("ASORT4: Top: %i, Bottom: %i \n", bound[0], bound[1]);
	while (issort((*a), NULL) != 1)
	{
			if ((*a)->rank > (*a)->down->rank)
			{
				ft_printf("sa\n");
				swap_stack(a);
			}
			else if (i < 2)
			{
				ft_printf("ra\n");
				rot_stack(a);
				i++;
			}
			else if (i >= 2 && i < 4)
			{
				ft_printf("rra\n");
				revrot_stack(a);
				i++;
			}
			else if (i == 4)
			{
				ft_printf("ra\n");
				rot_stack(a);
				i++;
			}
			else if (i == 5)
			{
				ft_printf("rra\n");
				revrot_stack(a);
				i++;
			}
	}
}

void	a_sort3(t_stack **a, int bound[2])
{
//ft_printf("ASORT3: Top: %i, Bottom: %i \n", bound[0], bound[1]);
//prt_stack(*a);
//ft_printf("\n");
	while (issort((*a), NULL) != 1)
	{
		if ((*a)->rank > (*a)->down->rank)
		{
			ft_printf("sa\n");
			swap_stack(a);
		}
		else
		{
			ft_printf("ra\n");
			rot_stack(a);
			if ((*a)->rank > (*a)->down->rank)
			{
				ft_printf("sa\n");
				swap_stack(a);
			}
			ft_printf("rra\n");
			revrot_stack(a);
		}
	}
}

void	b_sort4(t_stack **b, int bound[2])
{
	int i;

	i = 0;
//ft_printf("BSORT4: Top: %i, Bottom: %i \n", bound[0], bound[1]);
	while (nrevissort((*b), NULL, (bound[1] - bound[0])) != 1)
	{
		if ((*b)->rank < (*b)->down->rank)
		{
			ft_printf("sb\n");
			swap_stack(b);
		}
		else if (i < 2)
		{
			ft_printf("rb\n");
			rot_stack(b);
			if ((*b)->rank < (*b)->down->rank)
			{
				ft_printf("sb\n");
				swap_stack(b);
				ft_printf("rb\n");
				rot_stack(b);
				if ((*b)->rank < (*b)->down->rank)
				{
					ft_printf("sb\n");
					swap_stack(b);
				}
				ft_printf("rrb\n");
				revrot_stack(b);
				if ((*b)->rank < (*b)->down->rank)
				{
					ft_printf("sb\n");
					swap_stack(b);
				}
				ft_printf("rrb\n");
				revrot_stack(b);
			}
			else
			{
				ft_printf("rb\n");
				rot_stack(b);
				if ((*b)->rank < (*b)->down->rank)
				{
					ft_printf("sb\n");
					swap_stack(b);
					ft_printf("rrb\n");
					revrot_stack(b);
				}
				ft_printf("rrb\n");
				revrot_stack(b);
			}
			i++;
		}
		// else
		// {
		// 	ft_printf("rb\n");
		// 	rot_stack(b);
		// 	if ((*b)->rank < (*b)->down->rank)
		// 	{
		// 		ft_printf("sb\n");
		// 		swap_stack(b);
		// 		ft_printf("rrb\n");
		// 		revrot_stack(b);
		// 	}
		// }
	}
}

void	b_sort3(t_stack **b, int bound[2])
{
//ft_printf("BSORT3: Top: %i, Bottom: %i \n", bound[0], bound[1]);
	while (nrevissort((*b), NULL, (bound[1] - bound[0])) != 1)
	{
		if ((*b)->rank < (*b)->down->rank)
		{
			ft_printf("sb\n");
			swap_stack(b);
		}
		else
		{
			ft_printf("rb\n");
			rot_stack(b);
			if ((*b)->rank < (*b)->down->rank)
			{
				ft_printf("sb\n");
				swap_stack(b);
			}
			ft_printf("rrb\n");
			revrot_stack(b);
		}
	}
}


void	sortish(t_stack **st, int bound[2], int flag)
{
	if (flag)
	{
		if (bound[1] - bound[0] < 4)
			a_sort3(st, bound);
		else
			a_sort4(st, bound);
	}
	else
	{
		if (bound[1] - bound[0] < 4)
			b_sort3(st, bound);
		else
			b_sort4(st, bound);
	}
}

void	recover(t_stack **src, t_stack **dst, int bound[2], int flag)
{
	int i;
	int top = bound[0];
	int bottom = bound[1];

	i = 0;
//ft_printf("RECOVER: Top: %i, Bottom: %i, Flag: %i\n", bound[0], bound[1], flag);
	if (bottom - top > 4)
		sortwhole(src, dst, bound, !flag);
//ft_printf("AFTER SORT IN RECOVER: Top: %i, Bottom: %i, Flag: %i\n", bound[0], bound[1], flag);
	sortish(src, bound, !flag);
	while (flag && i < bound[1] - bound[0])
	{
		ft_printf("pa\n");
		push_stack(dst, src);
		i++;
	}
}

void	sortwhole(t_stack **src, t_stack **dst, int bound[2], int flag)
{
	int i;
	int j;
	int size;
	int topelm;
	int boundr;
	int lowelm;

	i = 0;
	j = 0;
	topelm = bound[0];
	lowelm = bound[1];
	boundr = (bound[0] + bound[1]) / 2;
	size = lowelm - topelm;
	if (size > 4)
	{
//ft_printf("sortwhole: Top: %i, Bottom: %i Bound: %i Flag: %i \n", bound[0], bound[1], boundr, flag);
		while (i < size)
		{
			if ((flag) && (*src)->rank < boundr)
			{
				ft_printf("pb\n");
//ft_printf("Pushing to B: %i, bound: %i\n", (*src)->rank, boundr);
				push_stack(dst, src);
			}
			else if ((flag == 0) && (*src)->rank >= boundr)
			{
				ft_printf("pa\n");
//ft_printf("Pushing to A: %i, bound: %i\n", (*src)->rank, boundr);
				push_stack(dst, src);
			}
			else
			{
				(flag) ? ft_printf("ra\n"): ft_printf("rb\n");
				rot_stack(src);
				j++;
			}
			i++;
		}
		while (j > 0)
		{
			(flag) ? ft_printf("rra\n"): ft_printf("rrb\n");
			revrot_stack(src);
			j--;
		}
		bound[0] = boundr;
		if (!flag)
		{
			bound[1] = lowelm;
//ft_printf("Prior to Asortwhole: Top: %i, Bottom: %i Bound: %i Flag: %i \n", bound[0], bound[1], boundr, flag);
			sortwhole(dst, src, bound, !flag);
//ft_printf("After to Asortwhole: Top: %i, Bottom: %i Bound: %i Flag: %i \n", bound[0], bound[1], boundr, flag);
			bound[0] = topelm;
			bound[1] = boundr;

		}
		sortwhole(src, dst, bound, flag);
		if (flag)
		{
			bound[0] = topelm;
			bound[1] = boundr;
		}
		if (flag)
			recover(dst, src, bound, flag);
	}
	else
		sortish(src, bound, flag);
	if (issort(*src, *dst))
		return ;
}	

void	attachrank(int **rank, t_stack **a, int size)
{
	t_stack *tmp;
	int 	i;

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

void	sorta(int *arr, int size)
{
	int **rank;
	int bound[2];
	t_stack *a = NULL;
	t_stack *b = NULL;

	makestack(&a, arr, size);
	if (issort(a, b))
	{
		free(a);
		free(arr);
		return;
	}
	revarr(arr, size);
	bound[0] = 0;
	bound[1] = size;
	rank = rankmake(arr, size);
	attachrank(rank, &a, size);
	sortwhole(&a, &b, bound, 1);
	// jsoc(&a, &b , size);
	free_stack(&a);
	free_stack(&b);
	// sortb(&a, &b, size);
	free_arr((void**)rank, size);
	free(arr);
	// for (int i = 0; i < size; i++)
	// 	prtarr(rank[i], 2);
	// ft_printf("\n");
	//prtarr(arr, size);
}

int main(int argc, char **argv)
{
	int *arr;
	char **strs;
	int flag;
	int size;

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

// void	jsoc(t_stack **a, t_stack **b, int size)
// {
// 	int count;
// 	int tmp;
// 	int bound;
// 	int i;
// 	int flag;
// 	int sizecpy;

// 	tmp = size;
// 	sizecpy = size;
// 	count = 0;
// 	i = 0;
// 	flag = 1;
// 	while (tmp >= 2)
// 	{
// 		count++;
// 		tmp /= 2;
// 	}
// 	tmp = count;
// 	while (tmp > 1)
// 	{
// 		bound = (tmp - 1) * (size / count);
// 		i = 0;
// 		while (i < sizecpy)
// 		{
// 			//(flag) ? presetter(a, bound, size, flag): presetter(b, bound, size, flag);
// 			(flag) ? pusher(a, b, bound, flag): pusher(b, a, bound, flag);
// 			if (flag)
// 			{
// 				if (countstacks(*b) == bound)
// 					break;
// 			}
// 			else
// 			{
// 				if (countstacks(*a) == bound)
// 					break;
// 			}
// 			if (flag && issort(*a, *b))
// 				return ;
// 			i++;
// 		}
// 		sizecpy = bound;
// 		(flag) ? quicky(a, size, bound, flag): quicky(b, size, bound, flag);
// 		if (flag && issort(*a, *b))
// 			return ;
// 		flag = 1 - flag;
// 		tmp--;
// 	}
// 	quicky(a, size, bound, 1);
// 	while (*b != NULL)
// 	{
// 		ft_printf("pa\n");
// 		push_stack(a, b);
// 	}
// }