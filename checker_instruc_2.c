/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instruc_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:45:15 by marvin            #+#    #+#             */
/*   Updated: 2024/12/23 16:56:04 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

void	rr(int *tab_a, int *tab_b)
{
	ra(tab_a);
	rb(tab_b);
}

void	rra(int *tab_a)
{
	int	i;
	int	tmp;

	i = s_a(0, 1) - 2;
	tmp = tab_a[s_a(0, 1) - 1];
	while (i >= 0)
	{
		tab_a[i + 1] = tab_a[i];
		i--;
	}
	tab_a[0] = tmp;
}

void	rrb(int *tab_b)
{
	int	i;
	int	tmp;

	i = s_b(0, 1) - 2;
	tmp = tab_b[s_b(0, 1) - 1];
	while (i >= 0)
	{
		tab_b[i + 1] = tab_b[i];
		i--;
	}
	tab_b[0] = tmp;
}

void	rrr(int *tab_a, int *tab_b)
{
	rra(tab_a);
	rrb(tab_b);
}

void	pb_rb(int *a, int *b)
{
	pb(a, b);
	rb(b);
}
