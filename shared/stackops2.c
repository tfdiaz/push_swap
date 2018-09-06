/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:30:40 by tdiaz             #+#    #+#             */
/*   Updated: 2018/09/05 10:30:42 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	freebothst(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}

void	free_stack(t_stack **top)
{
	t_stack *tmp;
	t_stack *next;

	if (*top == NULL)
		return ;
	next = (*top)->down;
	while (next != *top)
	{
		tmp = next;
		next = next->down;
		free(tmp);
	}
	free(*top);
	(*top) = NULL;
}

int		countstacks(t_stack *st)
{
	void	*prt;
	int		i;

	i = 0;
	if (st == NULL)
		return (i);
	prt = st->up;
	while (st != prt)
	{
		i++;
		st = st->down;
	}
	i++;
	return (i);
}
