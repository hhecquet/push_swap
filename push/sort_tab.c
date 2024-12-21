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

#include "../push_swap.h"

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

int ft_compare_int_tab(int *tab_b)
{
	int i;
	int *tab_cmp;

	i = 0;
	tab_cmp = malloc(g_size_b(0,1) * sizeof(int));
	if (!tab_cmp)
		return (0);
	while (i < g_size_b(0,1))
	{
		tab_cmp[i] = tab_b[i];
		i++;
	}
	ft_sort_int_tab(tab_cmp, g_size_b(0,1));
	while (i < g_size_b(0,1) - 1)
	{
		if ((tab_cmp[i + 1] - tab_cmp[i]) > 50)
			return (1);
		i++;
	}
	return (0);
}
