/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:50:11 by marvin            #+#    #+#             */
/*   Updated: 2024/12/22 11:50:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	condi_total(int *a, int *b, int mx)
{
	if (((chr(a, b[max(b, s_b(0, 1))])) == 0 && max(b, s_b(0, 1)) == 0)
		|| chr(a, b[0]) == 0)
		pa(a, b);
	else if (a[s_a(0, 1) - 1] > b[0] && a[s_a(0, 1) - 1] < a[0]
		&& a[s_a(0, 1) - 1] > b[max(b, s_b(0, 1))])
		rra(a, 0);
	if (max(b, s_b(0, 1)) < s_b(0, 1) / 2)
		condi1_to_4(a, b, mx);
	else
		condi5_to_8(a, b, mx);
}

int	chunk_size(int *tbs, int s, int *a, int i)
{
	int	j;

	j = 0;
	while (j < s_a(0, 1) && (a[j] < tbs[((12 - i) * s) / 12] || a[j]
			>= tbs[(i * s) / 12]))
		j++;
	if (j == s_a(0, 1))
		i++;
	else
	{
		if (j < s_a(0, 1) / 2)
			while (j-- != 0)
				ra(a, 0);
		else
		{
			j = s_a(0, 1) - j;
			while (j-- != 0)
				rra(a, 0);
		}
	}
	return (i);
}

int	check_order(int *a)
{
	int i;

	i = 0;
	while (i < s_a(0, 1) - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}