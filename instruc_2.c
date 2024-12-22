/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:45:15 by marvin            #+#    #+#             */
/*   Updated: 2024/12/16 13:45:57 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(int *tab_a, int *tab_b)
{
	ra(tab_a, 1);
	rb(tab_b, 1);
	write(1, "rr\n", 3);
}

void	rra(int *tab_a, int rrr)
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
	if (rrr == 0)
		write(1, "rra\n", 4);
}

void	rrb(int *tab_b, int rrr)
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
	if (rrr == 0)
		write(1, "rrb\n", 4);
}

void	rrr(int *tab_a, int *tab_b)
{
	rra(tab_a, 1);
	rrb(tab_b, 1);
	write(1, "rrr\n", 4);
}

void	pb_rb(int *a, int *b)
{
	pb(a, b);
	rb(b, 0);
}
