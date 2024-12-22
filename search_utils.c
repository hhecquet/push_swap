/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:12:28 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/18 15:15:25 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab_sort, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < size - 1)
	{
		j = 1;
		while (i + j != size)
		{
			if (tab_sort[i + j] < tab_sort[i])
			{
				tmp = tab_sort[i];
				tab_sort[i] = tab_sort[i + j];
				tab_sort[i + j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	min(int *tab, int size)
{
	int	i;
	int	min;

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

int	max(int *tab, int size)
{
	int	i;
	int	max;

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

int	chr(int *a, int b0)
{
	int	i;
	int	j;
	int	k;

	k = 1;
	j = 0;
	if (a[0] > b0 && a[s_a(0, 1) - 1] < b0)
		k = 0;
	i = 1;
	while (i < s_a(0, 1))
	{
		if (a[i] > b0 && a[i - 1] < b0)
		{
			if (j != 0 || (j == 0 && k == 0) || (j == 0 && k == 1))
				if (a[i] < a[j] || (j == 0 && k == 1))
					j = i;
		}
		i++;
	}
	if (j == 0 && k == 1)
		return (min(a, s_a(0, 1)));
	if (k == 0 && j == 0)
		return (k);
	return (j);
}

int	init_tbs(int *tbs, int s, int *tab)
{
	int	i;

	i = 0;
	while (i < s)
	{
		tbs[i] = tab[i];
		i++;
	}
	ft_sort_int_tab(tbs, s);
	return (s);
}
