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


void	init_tab(int tab_a[500], int tab_b[500], int size_a, char **av)
{
	int	i;

	i = 0;
	while (i < size_a)
	{
		tab_a[i] = malloc(sizeof(int) * 1);
		tab_b[i] = malloc(sizeof(int) * 1);
		tab_a[i] = ft_atoi(av[i + 1]);
		i++;
	}
}

int ft_strcmp_plus(int tab0, int tab1, int tablst)
{
	static int tmp = 2147483647;
	if( tmp < tab0 && tmp < tab1 && tmp < tablst)
		return (-1);
	if (ft_strcmp(tab0, tab1) > 0 && ft_strcmp(tab0, tablst) > 0 && ft_strcmp(tab0, tmp) <= 0)
	{
		tmp = tab0;
		return (0);
	}
	else if (ft_strcmp(tab1, tab0) > 0 && ft_strcmp(tab1, tablst) > 0 && ft_strcmp(tab1, tmp) <= 0)
	{
		tmp = tab1;
		return (1);
	}
	else if (ft_strcmp(tablst, tab0) > 0 && ft_strcmp(tablst, tab1) > 0 && ft_strcmp(tablst, tmp) <= 0)
	{
		tmp = tablst;
		return (2);
	}
	return (-1);
}

int	ft_strcmp_tmp(int tab0)
{
	static int tmp = 2147483647;
	if (tmp < tab0)
		return (-1);
	if (ft_strcmp(tab0, tmp) <= 0)
	{
		tmp = tab0;
		return (0);
	}
	return (-1);
}

int	push_swap(int tab_a[500], int tab_b[500], int size_a, int size_b)
{
	int i;
	int cmp;

	i = size_b;
	cmp = 0;
	while (g_size_a(0,1) != 0)
	{
		if (g_size_b(0,1) != 0)
		{
			while (i > 0)
			{
				pb(tab_a, tab_b, size_a, size_b);
				i--;
			}
		}
		if (g_size_a(0,1) != 0)
			cmp = ft_strcmp_plus(tab_a[0], tab_a[1], tab_a[size_a]);
		else if (size_a == 1)
			cmp = ft_strcmp_tmp(tab_a[0]);
		else if (size_a == 0)
			return(1);
		if (cmp == 0)
			pa(tab_a, tab_b, size_a, size_b);
		else if (cmp == 1)
			sa(tab_a[0], tab_a[1]);
			pa(tab_a, tab_b, size_a, size_b);
		else if (cmp == 2)
			rra(tab_a, size_a);
			pa(tab_a, tab_b, size_a, size_b);
		else if (cmp == -1)
			if (tab_a[0] < tab_a[size_a])
				ra(tab_a, size_a);
	}
	return (1);
}
