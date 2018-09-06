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
	struct s_stack	*up;
	int				data;
	int				rank;
	struct s_stack	*down;

}				t_stack;

void			push_stack(t_stack **dst, t_stack **src);
void			swap_stack(t_stack **top);
void			rot_stack(t_stack **top);
void			revrot_stack(t_stack **top);
void			free_stack(t_stack **top);
void			freebothst(t_stack **a, t_stack **b);
int				countstacks(t_stack *st);
t_stack			*new_stack(int data);

void			srap(char *line, t_stack **a, t_stack **b);
void			rrap(char *line, t_stack **a, t_stack **b);
void			rrrap(char *line, t_stack **a, t_stack **b);

void			buildheap(int *arr, int size);
void			maxheap(int *arr, int size, int i);
void			setrank(int *arr, t_stack **a, int size);
int				**rankmake(int *arr, int size);
void			attachrank(int **rank, t_stack **a, int size);
void			revarr(int *arr, int size);

int				*arrbuild(char **s, int size);
void			makestack(t_stack **top, int *arr, int size);

int				issort(t_stack *a, t_stack *b);
int				revissort(t_stack *a, t_stack *b);
int				nrevissort(t_stack *a, t_stack *b, int n);
void			free_arr(void **arr, int size);
int				strlenarr(char **s);
void			sortwhole(t_stack **a, t_stack **b, int bound[2], int flag);

void			prtcolor(t_stack *a, t_stack *b, int size);
void			setcolor(int rank, int size);
void			resetcolor(void);
void			clearscreen(void);
void			prtspace(int size, int *j);
void			prtchar(int size, int *j);

void			onestack(t_stack *st, int bound, int size, int flag);
void			prtrow(t_stack *a, t_stack *b, int size);
void			twostack(t_stack *a, t_stack *b, int amount, int size);
void			athenb(t_stack *a, t_stack *b, int size);
void			bthena(t_stack *a, t_stack *b, int size);

void			prtswap(t_stack **st, char *s);
void			prtrot(t_stack **st, char *s);
void			prtrevrot(t_stack **st, char *s);
void			prtpush(t_stack **dst, t_stack **src, char *s);

void			a_sort4(t_stack **a, int bound[2]);
void			a_sort3(t_stack **a, int bound[2]);
void			b_sort4help(t_stack **b);
void			b_sort4(t_stack **b, int bound[2]);
void			b_sort3(t_stack **b, int bound[2]);

#endif
