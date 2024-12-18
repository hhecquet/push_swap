/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:35:21 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/18 11:45:57 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	chr_min(int *tab, int size)
{
	int	i;
	int min;
	
	i = 1;
	min = 0;
	while (i <= size - 1)
	{
		if (tab[min] > tab[i])
			min = i;
		i++;
	}
	return (min);
}

int	chr_max(int *tab, int size)
{
	int	i;
	int max;
	
	i = 1;
	max = 0;
	while (i <= size - 1)
	{
		if (tab[max] < tab[i])
			max = i;
		i++;
	}
	return (max);
}

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

int	check_order(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_order_plus(int *tab_a, int *tab_b)
{
	int i;

	i = 0;
	while (i < g_size_b(0,1) - 1)
	{
		if (tab_b[i] < tab_b[i + 1])
			return (0);
		i++;
	}
	i = chr_max(tab_a, g_size_a(0,1));
	while (i > 0)
	{
		if (tab_a[i] < tab_a[i - 1])
			return (0);
		i--;
	}
	i = g_size_a(0,1) - 1;
	while (i > chr_max(tab_a, g_size_a(0,1)))
	{
		if (tab_a[i] < tab_a[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	push_swap(int *tab_a, int *tab_b)
{
	int cmp;
	int var;
	int min;
	int max;

	cmp = 0;
	var = 0;
	min = 0;
	max = 0;
	if (g_size_b(0,1) == 0 && g_size_a(0,1) != 0 && check_order(tab_a, g_size_a(0,1)) == 1)
		return (1);
	if (g_size_a(0,1) == 2 && tab_a[0] > tab_a[1])
	{
		sa(tab_a);
		return (1);
	}
	/* if (g_size_a(0,1) == 3)
	{
		int tmp;
		
		tmp = 0;
		while (!(tab_a[0] < tab_a[1] && tab_a[1] < tab_a[2]))
		{
		tmp = tab_a[1];
		tab_a[1] = tab_a[2];
		tab_a[2] = tmp;
		if (tab_a[0] < tab_a[1] && tab_a[1] < tab_a[2])
			return (1);
		tmp = tab_a[0];
		tab_a[0] = tab_a[2];
		tab_a[2] = tmp;
		}
		return (1);
	} */
	pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
	pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
	if (tab_b[0] < tab_b[1])
		sb(tab_b);
	min = chr_min(tab_b, g_size_b(0,1));
	max = chr_max(tab_b, g_size_b(0,1));
	while (check_order_plus(tab_a,tab_b) != 1)
	{
		var = tab_a[0];
		if (tab_a[0] < tab_b[(g_size_b(0,1) - 1)/2 + 1])//// a revoir
		{
			while (tab_b[0] != var)
			{
				if (tab_a[0] < tab_b[0] && tab_a[0] > tab_b[g_size_b(0,1) - 1])
					pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
				else
					rrb(tab_b, g_size_b(0,1));
			}
		}
		else
		{
			while (tab_b[0] != var)
			{
				if (tab_a[0] < tab_b[0] && tab_a[0] > tab_b[g_size_b(0,1) - 1])
					pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
				else
					rb(tab_b, g_size_b(0,1));
			}
		}
	}
	if (chr_max(tab_a, g_size_a(0,1)) > (g_size_a(0,1) - 1)/2)
	{
		while (chr_max(tab_a, g_size_a(0,1)) != g_size_a(0,1)-1)
			rra(tab_a, g_size_a(0,1));
	}
	else
	{
		while (chr_max(tab_a, g_size_a(0,1)) != g_size_a(0,1)-1)
			ra(tab_a, g_size_a(0,1));
	}
	if (chr_max(tab_a, g_size_a(0,1)) > chr_max(tab_b, g_size_b(0,1)))
		rra(tab_a, g_size_a(0,1));
	if (chr_max(tab_b, g_size_b(0,1)) > (g_size_b(0,1) - 1)/2)
	{
		while (chr_max(tab_b, g_size_b(0,1)) != 0)
			rra(tab_b, g_size_b(0,1));
	}
	else
	{
		while (chr_max(tab_b, g_size_b(0,1)) != 0)
			ra(tab_b, g_size_b(0,1));
	}
	while (g_size_b(0,1) != 0)
	{
		while (tab_a[g_size_a(0,1) - 1] < tab_a[0] && tab_a[g_size_a(0,1) - 1] > tab_b[0])
			rra(tab_a, g_size_a(0,1));
		pa(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
		while (tab_a[g_size_a(0,1) - 1] < tab_a[0] && tab_a[g_size_a(0,1) - 1] > tab_b[0])
			rra(tab_a, g_size_a(0,1));
	}
	return (1);
}
