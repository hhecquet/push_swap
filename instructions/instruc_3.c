/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:45:54 by marvin            #+#    #+#             */
/*   Updated: 2024/12/14 14:45:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(int *tab_a, int *tab_b, int size_a, int size_b)
{
	rra(tab_a, size_a);
	rrb(tab_b, size_b);
}
write(1, "rrr\n", 4);

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