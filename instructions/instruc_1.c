/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:00:13 by marvin            #+#    #+#             */
/*   Updated: 2024/12/14 13:00:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(int tab_a1, int tab_a2)
{
	int	tmp;

	tmp = tab_a1;
	tab_a1 = tab_a2;
	tab_a2 = tmp;
	wirte(1, "sa\n", 3);
}

void	sb(int tab_b1, int tab_b2)
{
	int	tmp;

	tmp = tab_b1;
	tab_b1 = tab_b2;
	tab_b2 = tmp;
	wirte(1, "sb\n", 3);
}

void	ss(int tab_a1, int tab_a2, int tab_b1, int tab_b2)
{
	sa(tab_a1, tab_a2);
	sb(tab_b1, tab_b2);
	wirte(1, "ss\n", 3);
}

void	pa(int *tab_a, int *tab_b, int size_a, int size_b)
{
	int	i;
	int	tmp;

	tmp = tab_b[0];
	i = 0;
	while (i < size_b)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	i = 0;
	while (i <= size_a)
	{
		tab_a[i + 1] = tab_a[i];
		i++;
	}
	tab_a[0] = tmp;
	wirte(1, "pa\n", 3);
}

void	pb(int *tab_a, int *tab_b, int size_a, int size_b)
{
	int	i;
	int	tmp;

	tmp = tab_a[0];
	i = 0;
	while (i < size_a)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	i = 0;
	while (i <= size_b)
	{
		tab_b[i + 1] = tab_b[i];
		i++;
	}
	tab_b[0] = tmp;
	wirte(1, "pb\n", 3);
}
