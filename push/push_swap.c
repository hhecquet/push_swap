/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:35:21 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/19 12:11:22 by hhecquet         ###   ########.fr       */
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

	i = chr_max(tab_b, g_size_b(0,1));
	while (i < g_size_b(0,1) - 1)
	{
		if (tab_b[i] < tab_b[i + 1])
			return (0);
		i++;
	}
	i = 0;
	if (tab_b[g_size_b(0,1)-1] < tab_b[0] && tab_b[0] != tab_b[chr_max(tab_b, g_size_b(0,1))])
		return (0);
	while (i < chr_max(tab_b, g_size_b(0,1)) - 1)
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
	if (tab_a[g_size_b(0,1)-1] > tab_a[0] && tab_a[g_size_b(0,1)-1] != tab_a[chr_max(tab_a, g_size_a(0,1))])
		return (0);
	while (i > chr_max(tab_a, g_size_a(0,1)) + 1)
	{
		if (tab_a[i] < tab_a[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	push_swap(int *tab_a, int *tab_b)
{
	int	i;
	int *tab_sort;
	int size_a;
	
	i = 0;
	size_a = 0;
	tab_sort = malloc(g_size_a(0,1) * sizeof(int));
	if (!tab_sort)
		return (0);
	while (i < g_size_a(0,1))
	{
		tab_sort[i] = tab_a[i];
		i++;
	}
	//////////////cas particulier 1 2 et 3 voir 4 a 5 + " " segfault
	ft_sort_int_tab(tab_sort, g_size_a(0,1));
	size_a = g_size_a(0,1);
	pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
	while (g_size_a(0,1) != 0)
	{
		if (tab_a[0] >= tab_sort[size_a/2])
			pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
		else
		{
			pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
			rb(tab_b, g_size_b(0,1));
		}
	}
	pa(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
	pa(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
	if (tab_a[1] < tab_a[0] && !(tab_a[chr_max(tab_a, g_size_a(0,1))] > tab_b[chr_max(tab_b, g_size_b(0,1))] && chr_max(tab_a, g_size_a(0,1)) != 0))
		sa(tab_a);
	//tri par mediane a droite
	while (g_size_b(0,1) != 0)
	{
		
		if (chr_max(tab_b, g_size_b(0,1)) == 0)
			pa(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
		if (tab_a[g_size_a(0,1)-1] > tab_b[0] && tab_a[g_size_a(0,1)-1] < tab_a[0])
			rra(tab_a, g_size_a(0,1));
		else if (chr_max(tab_b, g_size_b(0,1)) < g_size_b(0,1)/2)
		{
			while (chr_max(tab_b, g_size_b(0,1)) != 0 && g_size_b(0,1) != 0)
				rb(tab_b, g_size_b(0,1));
		}
		else
		{
			while (chr_max(tab_b, g_size_b(0,1)) != 0 && g_size_b(0,1) != 0)
				rrb(tab_b, g_size_b(0,1));
		}
	}
	return (1);
}
// marche pas totalement voir a la comparaison dinsertion, + gagner plus de temps, tourner a pour mieux ranger faire pleins de if