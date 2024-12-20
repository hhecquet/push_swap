/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:35:21 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/20 15:15:54 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

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

int	ft_strchr(int *tab_a, int tabb0)
{
	int	i;
	int	j;
	int k;
	
	k = 1;
	j = 0;
	if (tab_a[0] > tabb0 && tab_a[g_size_a(0,1)-1] < tabb0)
		k = 0;
	i = 1;
	while (i < g_size_a(0,1))
	{
		if (tab_a[i] > tabb0 && tab_a[i - 1] < tabb0)
		{
			if (j != 0 || (j == 0 && k == 0)||(j == 0 && k == 1))
				if (tab_a[i] < tab_a[j]||(j == 0 && k == 1))
					j = i;
		}
		i++;
	}
	if (j == 0 && k == 1)
		return (chr_min(tab_a, g_size_a(0,1)));
	if (k == 0 && j == 0)
		return (k);
	return (j);
}

int	push_swap(int *tab_a, int *tab_b)
{
	int	i;
	int	j;
	int *tab_sort;
	int size_a;
	
	i = 0;
	j = 0;
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
	i = 5;
	while (g_size_a(0,1) != 0)
	{
		if (tab_a[0] < tab_sort[size_a/2] && tab_a[0] >= tab_sort[((8-i)*size_a)/8])
		{
			pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
			rb(tab_b, g_size_b(0,1));
		}
		else if (tab_a[g_size_a(0,1)-1] < tab_sort[size_a/2] && tab_a[g_size_a(0,1)-1] >= tab_sort[((8-i)*size_a)/8])
		{
			rra(tab_a, g_size_a(0,1));
			pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
			rb(tab_b, g_size_b(0,1));
		}
		else if (tab_a[0] >= tab_sort[size_a/2] && tab_a[0] <= tab_sort[(i*size_a)/8 -1])
			pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
		else if (tab_a[g_size_a(0,1)-1] >= tab_sort[size_a/2] && tab_a[g_size_a(0,1)-1] <= tab_sort[(i*size_a)/8 -1])
		{
			rra(tab_a, g_size_a(0,1));
			pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
		}
		else
		{
			j = 0;
			while (j < g_size_a(0,1) && (tab_a[j] < tab_sort[((8-i)*size_a)/8] || tab_a[j] >= tab_sort[(i*size_a)/8]))
				j++;
			if (j == g_size_a(0,1))
				i++;
			else
			{
				if (j < g_size_a(0,1)/2)
				{
					while (j != 0)
					{
						ra(tab_a, g_size_a(0,1));
						j--;
					}
				}
				else
				{
					j = g_size_a(0,1) - j;
					while (j != 0)
					{
						rra(tab_a, g_size_a(0,1));
						j--;
					}
				}
			}
		}
	}
	pa(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
	pa(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
	if (tab_a[1] < tab_a[0] && !(tab_a[chr_max(tab_a, g_size_a(0,1))] > tab_b[chr_max(tab_b, g_size_b(0,1))] && chr_max(tab_a, g_size_a(0,1)) != 0))
		sa(tab_a);//////stop ici
	while (g_size_b(0,1) != 0)
	{
		if (((ft_strchr(tab_a, tab_b[chr_max(tab_b,g_size_b(0,1))])) == 0 && chr_max(tab_b,g_size_b(0,1)) == 0)|| ft_strchr(tab_a, tab_b[0]) == 0)
			pa(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
		if (tab_a[g_size_a(0,1)-1] > tab_b[0] && tab_a[g_size_a(0,1)-1] < tab_a[0] && tab_a[g_size_a(0,1)-1] > tab_b[chr_max(tab_b, g_size_b(0,1))])//?
			rra(tab_a, g_size_a(0,1));
		if (chr_max(tab_b, g_size_b(0,1)) < g_size_b(0,1)/2)
		{
			if (ft_strchr(tab_a, tab_b[0]) >= g_size_a(0,1)/2)
			{
				if (ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]) < g_size_a(0,1)/2)
				{
					if((g_size_a(0,1) - ft_strchr(tab_a, tab_b[0])) < (chr_max(tab_b, g_size_b(0,1)) + ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))])))
						while (ft_strchr(tab_a, tab_b[0]) != 0)
							rra(tab_a, g_size_a(0,1));
					else
					{
						while (ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]) != 0)
							rra(tab_a, g_size_a(0,1));
						while (chr_max(tab_b, g_size_b(0,1)) != 0)
							rb(tab_b, g_size_b(0,1));
					}
				}
				else
				{
					if((g_size_a(0,1) - ft_strchr(tab_a, tab_b[0]) ) < (chr_max(tab_b, g_size_b(0,1)) + (g_size_a(0,1) - ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]))))
						while (ft_strchr(tab_a, tab_b[0]) != 0)
							rra(tab_a, g_size_a(0,1));
					else
					{
						while (ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]) != 0)
							rra(tab_a, g_size_a(0,1));
						while (chr_max(tab_b, g_size_b(0,1)) != 0)
							rb(tab_b, g_size_b(0,1));
					}
				}
			}
			else if (ft_strchr(tab_a, tab_b[0]) < g_size_a(0,1)/2)
			{
				if (ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]) < g_size_a(0,1)/2)
				{
					if((ft_strchr(tab_a, tab_b[0]) ) < (chr_max(tab_a, g_size_a(0,1)) + ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))])))
						while (ft_strchr(tab_a, tab_b[0]) != 0)
							ra(tab_a, g_size_a(0,1));
					else
					{
						while (ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]) != 0)
							ra(tab_a, g_size_a(0,1));
						while (chr_max(tab_b, g_size_b(0,1)) != 0)
							rb(tab_b, g_size_b(0,1));
					}
				}
				else
				{
					if((ft_strchr(tab_a, tab_b[0]) ) < (chr_max(tab_a, g_size_a(0,1)) + (g_size_a(0,1) - ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]))))
						while (ft_strchr(tab_a, tab_b[0]) != 0)
							ra(tab_a, g_size_a(0,1));
					else
					{
						while (ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]) != 0)
							ra(tab_a, g_size_a(0,1));
						while (chr_max(tab_b, g_size_b(0,1)) != 0)
							rb(tab_b, g_size_b(0,1));
					}
				}
			}
		}
		else
		{
			if (ft_strchr(tab_a, tab_b[0]) >= g_size_a(0,1)/2)
			{
				if (ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]) < g_size_a(0,1)/2)
				{
					if((g_size_a(0,1) - ft_strchr(tab_a, tab_b[0])) < (g_size_b(0,1) - (chr_max(tab_b, g_size_b(0,1)) + ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]))))
						while (ft_strchr(tab_a, tab_b[0]) != 0)
							rra(tab_a, g_size_a(0,1));
					else
					{
						while (ft_strchr(tab_a, tab_b[0]) != 0)
							rra(tab_a, g_size_a(0,1));
						while (chr_max(tab_b, g_size_b(0,1)) != 0)
							rb(tab_b, g_size_b(0,1));
					}
				}
				else
				{
					if((g_size_a(0,1) - ft_strchr(tab_a, tab_b[0]) ) < (g_size_b(0,1) - (chr_max(tab_b, g_size_b(0,1)) + ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]))))
						while (ft_strchr(tab_a, tab_b[0]) != 0)
							rra(tab_a, g_size_a(0,1));
					else
					{
						while (ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]) != 0)
							rra(tab_a, g_size_a(0,1));
						while (chr_max(tab_b, g_size_b(0,1)) != 0)
							rrb(tab_b, g_size_b(0,1));
					}
				}
			}
			else if (ft_strchr(tab_a, tab_b[0]) < g_size_a(0,1)/2)
			{
				if (ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]) < g_size_a(0,1)/2)
				{
					if((ft_strchr(tab_a, tab_b[0]) ) < (g_size_b(0,1) - (chr_max(tab_a, g_size_a(0,1)) + ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]))))
						while (ft_strchr(tab_a, tab_b[0]) != 0)
							ra(tab_a, g_size_a(0,1));
					else
					{
						while (ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]) != 0)
							ra(tab_a, g_size_a(0,1));
						while (chr_max(tab_b, g_size_b(0,1)) != 0)
							rb(tab_b, g_size_b(0,1));
					}
				}
				else
				{
					if((ft_strchr(tab_a, tab_b[0]) ) < (g_size_b(0,1) - (chr_max(tab_a, g_size_a(0,1)) + ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]))))
						while (ft_strchr(tab_a, tab_b[0]) != 0)
							ra(tab_a, g_size_a(0,1));
					else
					{
						while (ft_strchr(tab_a, tab_b[chr_max(tab_b, g_size_b(0,1))]) != 0)
							ra(tab_a, g_size_a(0,1));
						while (chr_max(tab_b, g_size_b(0,1)) != 0)
							rrb(tab_b, g_size_b(0,1));
					}
				}
			}
		}//CHECK ORDER PLUS
	}
	if (chr_max(tab_a, g_size_a(0,1)) <= g_size_a(0,1)/2 && chr_max(tab_a, g_size_a(0,1)) != 0)
	{
		while (chr_max(tab_a, g_size_a(0,1)) != 0)
			ra(tab_a, g_size_a(0,1));
	}
	else if (chr_max(tab_a, g_size_a(0,1)) > g_size_a(0,1)/2 && chr_max(tab_a, g_size_a(0,1)) != 0)
	{
		while (chr_max(tab_a, g_size_a(0,1)) != (g_size_a(0,1) - 1))
			rra(tab_a, g_size_a(0,1));
	}
	return (free(tab_sort), 1);
}
/*
	pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
	while (g_size_a(0,1) != 0)
	{
		if (tab_a[0] < tab_sort[size_a/2])
		{
			pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
			rb(tab_b, g_size_b(0,1));
		}	
		else
			pb(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
	}
	i = 3;
	while (g_size_b(0,1) != 0)
	{
		if (tab_b[0] >= tab_sort[size_a/2] && tab_b[0] <= tab_sort[(i*size_a)/4 - 1])
		{
			pa(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
			ra(tab_a, g_size_a(0,1));
		}
		else if (tab_b[0] < tab_sort[size_a/2] && tab_b[0] >= tab_sort[((4-i)*size_a)/4])
			pa(tab_a, tab_b, g_size_a(0,1), g_size_b(0,1));
		else
		{
			j = 0;
			while (j < g_size_b(0,1) && (tab_b[j] > tab_sort[(i*size_a)/4 -1] || tab_b[j] < tab_sort[((4-i)*size_a)/4]))
				j++;
			if (j == g_size_b(0,1))
				i = 4;
			else
				rb(tab_b, g_size_b(0,1));
		}
	} */