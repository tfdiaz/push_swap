/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:27:36 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/17 12:28:11 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include "libft/libft.h"
# include "libft/printf/ft_printf.h"

typedef struct	s_stack
{
	struct	s_stack	*up;
	int				data;
	int				rank;
	struct	s_stack	*down;

}				t_stack;

void	push_stack(t_stack **dst, t_stack **src);
void	swap_stack(t_stack **top);
void	rot_stack(t_stack **top);
void	revrot_stack(t_stack **top);
void	free_stack(t_stack **top);
t_stack *new_stack(int data);

void	prt_stack(t_stack *top);

void	buildheap(int *arr, int size);
void	maxheap(int *arr, int size, int i);
void	swapint(int *arr, int first, int second);

int		*arrbuild(char **s, int size);
void	makestack(t_stack **top, int *arr, int size);

int		issort(t_stack *a, t_stack *b);
int		nissort(t_stack *a, t_stack *b, int n);
int		revissort(t_stack *a, t_stack *b);
int		nrevissort(t_stack *a, t_stack *b, int n);
void	prt_stack(t_stack *top);
int		countstacks(t_stack *st);
void	free_arr(void **arr, int size);
int		strlenarr(char **s);
void	sortforce(t_stack **a, t_stack **b, int size, int flag);
void	sortwhole(t_stack **a, t_stack **b, int bound[2], int flag);

#endif
