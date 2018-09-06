/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:51:56 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/20 12:51:59 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*new_stack(int data)
{
	t_stack	*nstack;

	nstack = (t_stack *)malloc(sizeof(t_stack));
	if (!nstack)
		return (NULL);
	nstack->data = data;
	nstack->up = nstack;
	nstack->down = nstack;
	return (nstack);
}

void	push_stack(t_stack **dst, t_stack **src)
{
	t_stack *src_tmp;

	if (*src == NULL)
		return ;
	src_tmp = (*src);
	if ((*src)->down != *src)
	{
		(*src)->up->down = (*src)->down;
		(*src)->down->up = (*src)->up;
		(*src) = (*src)->down;
	}
	else
		(*src) = NULL;
	if ((*dst) == NULL)
	{
		(*dst) = src_tmp;
		(*dst)->up = src_tmp;
		(*dst)->down = src_tmp;
		return ;
	}
	src_tmp->up = (*dst)->up;
	src_tmp->down = (*dst);
	(*dst)->up->down = src_tmp;
	(*dst)->up = src_tmp;
	(*dst) = src_tmp;
}

void	swap_stack(t_stack **top)
{
	t_stack	*elm1;
	t_stack *elm2;

	elm1 = (*top);
	if (elm1 == NULL || elm1->down == elm1)
		return ;
	if (elm1->down->down == elm1)
	{
		rot_stack(top);
		return ;
	}
	elm2 = elm1->down;
	elm1->up->down = elm2;
	elm2->down->up = elm1;
	elm1->down = elm2->down;
	elm2->up = elm1->up;
	elm1->up = elm2;
	elm2->down = elm1;
	(*top) = elm2;
}

void	rot_stack(t_stack **top)
{
	if ((*top) == NULL)
		return ;
	(*top) = (*top)->down;
}

void	revrot_stack(t_stack **top)
{
	if ((*top) == NULL)
		return ;
	(*top) = (*top)->up;
}
