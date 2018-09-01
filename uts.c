/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uts.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 21:38:34 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/24 21:38:36 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		issort(t_stack *a, t_stack *b)
{
	void	*prt;
	int		flag;

	flag = 1;
	if (!a)
		return (-1);
	if (b)
		flag = 0;
	prt = a;
	while (a->down != prt)
	{
		if (a->data > a->down->data)
			flag = 0;
		a = a->down;
	}
	return (flag);
}

int		nissort(t_stack *a, t_stack *b, int n)
{
	int		flag;
	int		i;

	flag = 1;
	i = 0;
	if (!a)
		return (-1);
	if (b)
		flag = 0;
	while (i < n)
	{
		if (a->data > a->down->data)
			flag = 0;
		a = a->down;
		i++;
	}
	return (flag);
}

int		nrevissort(t_stack *a, t_stack *b, int n)
{
	int		flag;
	int		i;

	flag = 1;
	i = 0;
	if (!a)
		return (-1);
	if (b)
		flag = 0;
	n--;
	if (n > countstacks(a))
		n = countstacks(a);
	while (i < n)
	{
		if (a->data < a->down->data)
			flag = 0;
		a = a->down;
		i++;
	}
	return (flag);
}

int		revissort(t_stack *a, t_stack *b)
{
	void	*prt;
	int		flag;

	flag = 1;
	if (!a)
		return (-1);
	if (b)
		flag = 0;
	prt = a;
	while (a->down != prt)
	{
		if (a->data < a->down->data)
			flag = 0;
		a = a->down;
	}
	return (flag);
}

void	prt_stack(t_stack *top)
{
	void *prt;

	if (!top)
		return ;
	prt = top;
	while (top->down != prt)
	{
		ft_printf("%i\n", top->data);
		top = top->down;
	}
	ft_printf("%i\n", top->data);
}

void	free_arr(void **arr, int size)
{
	int i;
	
	i = -1;
	if (arr == NULL)
		return ;
	while (++i < size)
		free(arr[i]);
	free(arr);
	arr = NULL;
}

int	strlenarr(char **s)
{
	int i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}
