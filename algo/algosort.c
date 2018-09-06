/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algosort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:20:25 by tdiaz             #+#    #+#             */
/*   Updated: 2018/09/05 15:20:27 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

	i = 0;
	if (bound[1] - bound[0] > 4)
		sortwhole(src, dst, bound, !flag);
	sortish(src, bound, !flag);
	while (flag && i < bound[1] - bound[0])
	{
		ft_printf("pa\n");
		push_stack(dst, src);
		i++;
	}
}

void	splitter(t_stack **src, t_stack **dst, int bound[2], int flag)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < bound[1] - bound[0])
	{
		if ((flag) && (*src)->rank < ((bound[0] + bound[1]) / 2))
			prtpush(dst, src, "pb\n");
		else if ((flag == 0) && (*src)->rank >= ((bound[0] + bound[1]) / 2))
			prtpush(dst, src, "pa\n");
		else
		{
			(flag) ? ft_printf("ra\n") : ft_printf("rb\n");
			rot_stack(src);
			j++;
		}
		i++;
	}
	while (j > 0)
	{
		(flag) ? ft_printf("rra\n") : ft_printf("rrb\n");
		revrot_stack(src);
		j--;
	}
}

void	boundset(t_stack **src, t_stack **dst, int bound[2], int flag)
{
	int topelm;
	int boundr;
	int lowelm;

	topelm = bound[0];
	lowelm = bound[1];
	boundr = (bound[0] + bound[1]) / 2;
	bound[0] = boundr;
	if (!flag)
	{
		bound[1] = lowelm;
		sortwhole(dst, src, bound, !flag);
		bound[0] = topelm;
		bound[1] = boundr;
	}
	sortwhole(src, dst, bound, flag);
	if (flag)
	{
		bound[0] = topelm;
		bound[1] = boundr;
		recover(dst, src, bound, flag);
	}
}

void	sortwhole(t_stack **src, t_stack **dst, int bound[2], int flag)
{
	int size;

	size = bound[1] - bound[0];
	if (size > 4)
	{
		splitter(src, dst, bound, flag);
		boundset(src, dst, bound, flag);
	}
	else
		sortish(src, bound, flag);
	if (issort(*src, *dst))
		return ;
}
