/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlcol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:54:32 by tdiaz             #+#    #+#             */
/*   Updated: 2018/09/05 11:54:34 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	onestack(t_stack *st, int bound, int size, int flag)
{
	int i;
	int j;

	i = 0;
	while (i < bound)
	{
		if (i % 2 == 0)
		{
			j = 0;
			if (flag == 0)
				prtspace(size, &j);
			j = 0;
			prtspace((size - st->rank) / 2, &j);
			j = 0;
			setcolor(st->rank, size);
			prtchar(st->rank + 1, &j);
			resetcolor();
			ft_printf("\n");
		}
		i++;
		st = st->down;
	}
}

void	prtrow(t_stack *a, t_stack *b, int size)
{
	int j;
	int k;

	j = 0;
	prtspace((size - a->rank) / 2, &j);
	k = 0;
	setcolor(a->rank, size);
	prtchar(a->rank + 1, &k);
	j += k;
	resetcolor();
	prtspace(size, &j);
	j = 0;
	prtspace((size - b->rank) / 2, &j);
	j = 0;
	setcolor(b->rank, size);
	prtchar(b->rank + 1, &j);
	resetcolor();
	ft_printf("\n");
}

void	twostack(t_stack *a, t_stack *b, int amount, int size)
{
	int i;

	i = 0;
	while (i < amount)
	{
		if (i % 2 == 0)
			prtrow(a, b, size);
		a = a->down;
		b = b->down;
		i++;
	}
}

void	athenb(t_stack *a, t_stack *b, int size)
{
	int i;

	onestack(a, countstacks(a) - countstacks(b), size, 1);
	i = -1;
	while (++i < countstacks(a) - countstacks(b))
		a = a->down;
	twostack(a, b, countstacks(b), size);
}

void	bthena(t_stack *a, t_stack *b, int size)
{
	int i;

	onestack(b, countstacks(b) - countstacks(a), size, 0);
	i = -1;
	while (++i < countstacks(b) - countstacks(a))
		b = b->down;
	twostack(a, b, countstacks(a), size);
}
