/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackandprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:05:00 by tdiaz             #+#    #+#             */
/*   Updated: 2018/09/05 14:05:02 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	prtswap(t_stack **st, char *s)
{
	ft_printf("%s", s);
	swap_stack(st);
}

void	prtrot(t_stack **st, char *s)
{
	ft_printf("%s", s);
	rot_stack(st);
}

void	prtrevrot(t_stack **st, char *s)
{
	ft_printf("%s", s);
	revrot_stack(st);
}

void	prtpush(t_stack **dst, t_stack **src, char *s)
{
	ft_printf("%s", s);
	push_stack(dst, src);
}
