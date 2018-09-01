/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:59:39 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/20 12:59:41 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void srap(char *line, t_stack **a, t_stack **b)
{
	if(!ft_strcmp(line, "sb"))
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

int checkargs(char *line)
{
	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb") || !ft_strcmp(line, "ss") ||
		!ft_strcmp(line, "ra") || !ft_strcmp(line, "rb") || !ft_strcmp(line, "rr") ||
		!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb") || !ft_strcmp(line, "rrr") ||
		!ft_strcmp(line, "pa") || !ft_strcmp(line, "pb"))
		return (0);
	return (1);
}

int commands(t_stack **a, t_stack **b)
{
	char *line;

	while(get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (checkargs(line))
		{
			free(line);
			return (0);
		}
		if (line[0] == 's')
			(!ft_strcmp(line, "sa")) ? swap_stack(a): srap(line, a, b);
		else if (line[0] == 'p')
			(!ft_strcmp(line, "pa")) ? push_stack(a, b): push_stack(b, a);
		else if (line[0] == 'r' && ft_strlen(line) == 2)
			(!ft_strcmp(line, "ra")) ? rot_stack(a): rrap(line, a, b);
		else
			(!ft_strcmp(line, "rra")) ? revrot_stack(a): rrrap(line, a, b);
		prt_stack(*a);
		ft_printf("B:\n");
		prt_stack(*b);
		ft_printf("\n");
		free(line);
	}
	return (1);
}

int main(int argc, char **argv)
{
	int *arr;
	char **strs;
	t_stack *a;
	t_stack *b;
	int flag;
	int i;
	int size;

	if (argc > 1)
	{
		if (argc == 2)
		{
			strs = ft_strsplit(argv[1], ' ');
			size = strlenarr(strs);
		}
		else
		{
			strs = argv + 1;
			size = argc - 1;
		}
		flag = (arr = arrbuild(strs, size)) ? 1: 0;
		if (arr != NULL)
			makestack(&a, arr, size);
		if (arr != NULL)
		{
			if ((flag = commands(&a, &b)) > 0)
				(issort(a, b)) ? ft_printf("OK\n"): ft_printf("KO\n");
			free_stack(&a);
			free_stack(&b);
			free(arr);
		}
		if (!flag)
			ft_printf("Error\n");
		if (argc == 2)
			free_arr((void**)strs, size);
	}
}
