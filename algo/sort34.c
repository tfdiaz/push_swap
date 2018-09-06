/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort34.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:16:30 by tdiaz             #+#    #+#             */
/*   Updated: 2018/09/05 15:16:32 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	a_sort4(t_stack **a, int bound[2])
{
	int i;

	i = 0;
	while (issort((*a), NULL) != 1)
	{
		if ((*a)->rank > (*a)->down->rank)
			prtswap(a, "sa\n");
		else if (i < 6)
		{
			if (i < 2)
				prtrot(a, "ra\n");
			else if (i >= 2 && i < 4)
				prtrevrot(a, "rra\n");
			else if (i == 4)
				prtrot(a, "ra\n");
			else if (i == 5)
				prtrevrot(a, "rra\n");
			i++;
		}
	}
}

void	a_sort3(t_stack **a, int bound[2])
{
	while (issort((*a), NULL) != 1)
	{
		if ((*a)->rank > (*a)->down->rank)
			prtswap(a, "sa\n");
		else
		{
			prtrot(a, "ra\n");
			if ((*a)->rank > (*a)->down->rank)
				prtswap(a, "sa\n");
			prtrevrot(a, "rra\n");
		}
	}
}

void	b_sort4help(t_stack **b)
{
	if ((*b)->rank < (*b)->down->rank)
	{
		prtswap(b, "sb\n");
		prtrot(b, "rb\n");
		if ((*b)->rank < (*b)->down->rank)
			prtswap(b, "sb\n");
		prtrevrot(b, "rrb\n");
		if ((*b)->rank < (*b)->down->rank)
			prtswap(b, "sb\n");
		prtrevrot(b, "rrb\n");
	}
	else
	{
		prtrot(b, "rb\n");
		if ((*b)->rank < (*b)->down->rank)
		{
			prtswap(b, "sb\n");
			prtrevrot(b, "rrb\n");
		}
		prtrevrot(b, "rrb\n");
	}
}

void	b_sort4(t_stack **b, int bound[2])
{
	int i;

	i = 0;
	while (nrevissort((*b), NULL, (bound[1] - bound[0])) != 1)
	{
		if ((*b)->rank < (*b)->down->rank)
			prtswap(b, "sb\n");
		else if (i < 2)
		{
			prtrot(b, "rb\n");
			b_sort4help(b);
			i++;
		}
	}
}

void	b_sort3(t_stack **b, int bound[2])
{
	while (nrevissort((*b), NULL, (bound[1] - bound[0])) != 1)
	{
		if ((*b)->rank < (*b)->down->rank)
			prtswap(b, "sb\n");
		else
		{
			prtrot(b, "rb\n");
			if ((*b)->rank < (*b)->down->rank)
				prtswap(b, "sb\n");
			prtrevrot(b, "rrb\n");
		}
	}
}
