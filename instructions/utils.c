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

int	s_a(int i, int read_only)
{
	static int	size_a = 0;

	if (read_only == 1)
		return (size_a);
	size_a = i;
	return (size_a);
}

int	s_b(int i, int read_only)
{
	static int	size_b = 0;

	if (read_only == 1)
		return (size_b);
	size_b = i;
	return (size_b);
}

int	g_ac(int i, int read_only)
{
	static int	ac;

	if (read_only == 0)
		ac = i;
	return (ac);
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
