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
