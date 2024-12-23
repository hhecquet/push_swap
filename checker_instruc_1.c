/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instruc_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:00:13 by marvin            #+#    #+#             */
/*   Updated: 2024/12/23 12:56:15 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

void	sa(int *tab_a)
{
	int	tmp;

	tmp = tab_a[0];
	tab_a[0] = tab_a[1];
	tab_a[1] = tmp;
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
}

void	ra(int *tab_a)
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
}

void	rb(int *tab_b)
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
}
