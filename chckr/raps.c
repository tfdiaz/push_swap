/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:39:50 by tdiaz             #+#    #+#             */
/*   Updated: 2018/09/05 09:39:52 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	srap(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sb"))
		swap_stack(b);
	else
	{
		swap_stack(a);
		swap_stack(b);
	}
}

void	rrap(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "rb"))
		rot_stack(b);
	else if (!ft_strcmp(line, "rr"))
	{
		rot_stack(a);
		rot_stack(b);
	}
}

void	rrrap(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "rrb"))
		revrot_stack(b);
	else if (!ft_strcmp(line, "rrr"))
	{
		revrot_stack(a);
		revrot_stack(b);
	}
}
