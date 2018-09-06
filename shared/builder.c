/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 10:17:12 by tdiaz             #+#    #+#             */
/*   Updated: 2018/08/24 10:17:15 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		errorck(char **s, int size)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < size)
	{
		tmp = ft_itoa(ft_atoi(s[i]));
		if (ft_strcmp(tmp, s[i]) != 0)
		{
			free(tmp);
			return (0);
		}
		free(tmp);
		i++;
	}
	return (1);
}

int		dups(int *arr, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		*arrbuild(char **s, int size)
{
	int	*arr;
	int i;
	int j;

	i = 0;
	if (errorck(s, size) == 0)
		return (NULL);
	if (!(arr = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	i = size;
	j = -1;
	while (--i >= 0)
		arr[++j] = ft_atoi(s[i]);
	if (dups(arr, size) == 0)
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}

void	makestack(t_stack **top, int *arr, int size)
{
	int		i;
	t_stack	*tmp;

	i = -1;
	while (++i < size)
	{
		if ((tmp = new_stack(arr[i])) != NULL)
			push_stack(top, &tmp);
	}
}
