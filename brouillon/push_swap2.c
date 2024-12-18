/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:35:21 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/16 14:47:41 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*take_min(int *tab_a)
{
	int *tab_min;
	int tmp;
	
	tmp = 0;
	tab_min = malloc(sizeof(int) * 3);
	if (!tab_min)
		return (free(tab_min), NULL);
	tab_min[0] = 0;
	tab_min[1] = 1;
	tab_min[2] = g_size_a(0,1) - 1;
	while (!(tab_a[tab_min[0]] < tab_a[tab_min[1]] && tab_a[tab_min[1]] < tab_a[tab_min[2]]))
	{
		tmp = tab_min[1];
		tab_min[1] = tab_min[2];
		tab_min[2] = tmp;
		if (tab_a[tab_min[0]] < tab_a[tab_min[1]] && tab_a[tab_min[1]] < tab_a[tab_min[2]])
			return (tab_min);
		tmp = tab_min[0];
		tab_min[0] = tab_min[2];
		tab_min[2] = tmp;
	}
	return (tab_min);
}

int ft_strcmp_plus(int *tab_a, int *tab_b)
{ 
	int i;
	int *tab_min;

	i = 0;
	tab_min = take_min(tab_a);
	if (tab_a[tab_min[0]] < tab_b[g_size_b(0,1) - 1])
	{
		g_tmp(tab_a[tab_min[0]],0);
		if (tab_min[0] == g_size_a(0,1) - 1)
			tab_min[0] = 2;
		return (g_sign(1,0), tab_min[0]);	
	}
	while (i != 3)
	{
		if (tab_a[tab_min[i]] > tab_b[0])
		{
			g_tmp(tab_a[tab_min[i]],0);
			if (tab_min[i] == g_size_a(0,1) - 1)
				tab_min[i] = 2;
			return (tab_min[i]);
		}
		i++;
	}
	return (-1);
}

int	check_order(int *tab_a)
{
	int i;

	i = 0;
	while (i < g_size_a(0,1) - 1)
	{
		if (tab_a[i] > tab_a[i + 1] || g_size_b(0,1) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_orderb(int *tab_a, int *tab_b)
{
	int i;

	i = 0;
	while (i < g_size_b(0,1) - 1)
	{
		if (tab_b[i] < tab_b[i + 1])
			return (0);
		i++;
	}
	if (tab_a[1] > tab_a[0])
	{
		if (tab_b[0] > tab_a[1])
			return (0);
		sa(tab_a);
	}
	else if (tab_a[0] > tab_a[1])
	{
		if (tab_b[0] > tab_a[0] )
			return (0);
	}
	return (1);
}

int	push_swap(int *tab_a, int *tab_b, int size_a, int size_b)
{
	int cmp;
	int var;

	cmp = 0;
	var = 0;
	(void)size_b;
	(void)size_a;
	while (check_order(tab_a) != 1)
	{
		if (g_size_b(0,1) != 0 && var == 1)
		{
			var = 0;
			while (!(tab_a[g_size_a(0,1) - 1] > tab_b[0] && tab_a[g_size_a(0,1) - 1] < tab_a[0]) && g_size_b(0,1) != 0)
				pa(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
			//if (tab_a[g_size_a(0,1) - 1] < tab_a[0])
			//	rra(tab_a, g_size_a(0,1));
			if (g_size_b(0,1) == 0)
				g_tmp(2147483647,0);
		}
		if (check_order(tab_a) == 1)
			return (1);
		if (g_size_a(0,1) > 2 || g_size_b(0,1) == 0)
			cmp = ft_strcmp_plus(tab_a, tab_b);
		else if (g_size_a(0,1) == 2)
			cmp = -1;
		if (cmp == 0)
		{
			pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
		}
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
		if (g_size_a(0,1) == 2 && check_orderb(tab_a,tab_b) == 1)
				var = 1;
		if (g_sign(0,1) == 1)
			rb(tab_b, g_size_b(0,1));
		else if (cmp == -1)
		{
			if (g_size_a(0,1) == 2 && tab_a[0] > tab_a[1])
				sa(tab_a);
			else if (tab_a[0] < tab_a[g_size_a(0,1) - 1] && tab_a[0] < tab_a[1] && g_size_a(0,1) > 2)
				ra(tab_a, g_size_a(0,1));
			else if (tab_a[1] < tab_a[g_size_a(0,1) - 1] && tab_a[1] < tab_a[0] && g_size_a(0,1) > 2)
			{
				sa(tab_a);
				ra(tab_a, g_size_a(0,1));
			}
			var = 1;
		}
		g_sign(0,0);
	}
	return (1);
}
