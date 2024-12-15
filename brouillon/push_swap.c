/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:35:21 by marvin            #+#    #+#             */
/*   Updated: 2024/12/14 14:35:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_strcmp_plus(int tab0, int tab1, int tablst)
{
	int tmp = g_tmp(0,1);
	if( tmp < tab0 && tmp < tab1 && tmp < tablst)
		return (-1);
	if ((tab0 > tab1 && tab0 > tablst && tab0 <= tmp) || (tab0 <= tmp &&
		tab1 > tmp && tab0 < tab1 && tablst <= tmp && tab0 > tablst) ||
			(tab0 <= tmp && tablst > tmp && tab0 < tablst && tab1 <= tmp &&
				tab0 > tab1) ||  (tab0 <= tmp && tab1 > tmp && tablst > tmp &&
					tab0 < tab1 && tab0 < tablst))
		return (g_tmp(tab0,0), 0);
	else if ((tab1 > tab0 && tab1 > tablst && tab1 <= tmp) || (tab1 <= tmp &&
		tab0 > tmp && tab1 < tab0 && tablst <= tmp && tab1 > tablst) ||
			(tab1 <= tmp && tablst > tmp && tab1 < tablst && tab0 <= tmp &&
				tab1 > tab0) ||  (tab1 <= tmp && tab0 > tmp && tablst > tmp &&
					tab1 < tab0 && tab1 < tablst))
		return (g_tmp(tab1,0), 1);
	else if ((tablst > tab1 && tablst > tab0 && tablst <= tmp) || (tablst <= tmp &&
		tab1 > tmp && tablst < tab1 && tab0 <= tmp && tablst > tab0) ||
			(tablst <= tmp && tab0 > tmp && tablst < tab0 && tab1 <= tmp &&
				tablst > tab1) || (tablst <= tmp && tab1 > tmp && tab0 > tmp &&
					tablst < tab1 && tablst < tab0))
		return (g_tmp(tablst,0), 2);
	return (-1);
}

int	push_swap(int *tab_a, int *tab_b, int size_a, int size_b)
{
	int cmp;

	cmp = 0;
	(void)size_b;
	(void)size_a;
	while (g_size_a(0,1) != 0)
	{
		if (g_size_b(0,1) != 0 && tab_b[0] < tab_a[g_size_a(0,1) - 1] && tab_b[0] < tab_a[0] && tab_b[0] < tab_a[1]) // rajouter des if
		{
			while (tab_b[0] < tab_a[g_size_a(0,1) - 1])
				pa(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
			if (g_size_b(0,1) == 0)
				g_tmp(2147483647,0);
		}
		if (g_size_a(0,1) > 2)
			cmp = ft_strcmp_plus(tab_a[0], tab_a[1], tab_a[g_size_a(0,1) - 1]);
		else if (g_size_a(0,1) == 2)
			if ((tab_a[0] > tab_a[1] && tab_a[0] < g_tmp(0,1) && tab_a[1] < g_tmp(0,1)) || (tab_a[0] < tab_a[1] && tab_a[0] < g_tmp(0,1) && tab_a[1] > g_tmp(0,1)))
				cmp = 0;
			else if ((tab_a[1] > tab_a[0] && tab_a[0] < g_tmp(0,1) && tab_a[1] < g_tmp(0,1)) || (tab_a[1] < tab_a[0] && tab_a[1] < g_tmp(0,1) && tab_a[0] > g_tmp(0,1)))
				cmp = 1;
			else 
				cmp = -1;
		else if (g_size_a(0,1) == 1)
			if (tab_a[0] <= g_tmp(0,1))
				cmp = 0;
			else
				cmp = -1;
		else if (g_size_a(0,1) == 0)
			return(1);
		if (cmp == 0)
			pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
		else if (cmp == 1)
		{
			sa(tab_a);
			pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
		}
		else if (cmp == 2)
		{
			rra(tab_a, g_size_a(0,1));
			pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
		}
		else if (cmp == -1)
		{
			if (tab_a[0] > tab_a[g_size_a(0,1) - 1] && tab_a[0] > tab_a[1])
				ra(tab_a, g_size_a(0,1));
			else if (tab_a[1] > tab_a[g_size_a(0,1) - 1] && tab_a[1] > tab_a[0])
			{
				sa(tab_a);
				ra(tab_a, g_size_a(0,1));
			}
		}
	}
	return (1);
}
