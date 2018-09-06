/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:50:11 by tdiaz             #+#    #+#             */
/*   Updated: 2018/09/05 11:50:17 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	setcolor(int rank, int size)
{
	int x;

	if (size > 20)
		x = size / 20;
	else
		x = 20 / size;
	if (size > 20)
		ft_printf("\033[38;5;%im", 255 - (rank / (x + 1)));
	else
		ft_printf("\033[38;5;%im", 255 - (rank * x));
}

void	resetcolor(void)
{
	ft_printf("\033[0m");
}

void	clearscreen(void)
{
	ft_printf("\033[2J");
	ft_printf("\033[H");
}

void	prtspace(int size, int *j)
{
	while ((*j) < size)
	{
		ft_printf(" ");
		(*j)++;
	}
}

void	prtchar(int size, int *j)
{
	while ((*j) < size)
	{
		ft_printf("|");
		(*j)++;
	}
}
