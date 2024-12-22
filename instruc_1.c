/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:00:13 by marvin            #+#    #+#             */
/*   Updated: 2024/12/19 09:40:01 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *tab_a)
{
	int	tmp;

	tmp = tab_a[0];
	tab_a[0] = tab_a[1];
	tab_a[1] = tmp;
	write(1, "sa\n", 3);
}

void	pa(int *tab_a, int *tab_b)
{
	int	i;
	int	tmp;

	tmp = tab_b[0];
	i = 0;
	while (i < s_b(0, 1) - 1)
	{
		tab_b[i] = tab_b[i + 1];
		i++;
	}
	i = s_a(0, 1) - 1;
	while (i >= 0)
	{
		tab_a[i + 1] = tab_a[i];
		i--;
	}
	tab_a[0] = tmp;
	s_a(s_a(0, 1) + 1, 0);
	s_b(s_b(0, 1) - 1, 0);
	write(1, "pa\n", 3);
}

void	pb(int *tab_a, int *tab_b)
{
	int	i;
	int	tmp;

	tmp = tab_a[0];
	i = 0;
	while (i < s_a(0, 1) - 1)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	i = s_b(0, 1) - 1;
	while (i >= 0)
	{
		tab_b[i + 1] = tab_b[i];
		i--;
	}
	tab_b[0] = tmp;
	s_a(s_a(0, 1) - 1, 0);
	s_b(s_b(0, 1) + 1, 0);
	write(1, "pb\n", 3);
}

void	ra(int *tab_a, int rr)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = tab_a[0];
	while (i < s_a(0, 1) - 1)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	tab_a[s_a(0, 1) - 1] = tmp;
	if (rr == 0)
		write(1, "ra\n", 3);
}

void	rb(int *tab_b, int rr)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = tab_b[0];
	while (i < s_b(0, 1) - 1)
	{
		tab_b[i] = tab_b[i + 1];
		i++;
	}
	tab_b[s_b(0, 1) - 1] = tmp;
	if (rr == 0)
		write(1, "rb\n", 3);
}
