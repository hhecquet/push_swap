/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:45:54 by marvin            #+#    #+#             */
/*   Updated: 2024/12/18 17:00:35 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(int *tab_a, int *tab_b, int size_a, int size_b)
{
	rra(tab_a, size_a, 1);
	rrb(tab_b, size_b, 1);
	write(1, "rrr\n", 4);
}

int	g_size_a(int i, int read_only)
{
	static int	size_a = 0;
	if (read_only == 1)
		return(size_a);
	size_a = i;
	return (size_a);
}

int	g_size_b(int i, int read_only)
{
	static int	size_b = 0;
	if (read_only == 1)
		return(size_b);
	size_b = i;
	return (size_b);
}

int	g_min(int i, int read_only)
{
	static int	min = 0;
	if (read_only == 1)
		return(min);
	min = i;
	return (min);
}

int	g_max(int i, int read_only)
{
	static int	max = 0;
	if (read_only == 1)
		return(max);
	max = i;
	return (max);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	i = 0;
	j = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			j *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * j);
}