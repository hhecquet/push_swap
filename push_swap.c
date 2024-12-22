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

#include "push_swap.h"

int	sort_short(int *a, int *b)
{
	if (s_a(0, 1) == 2)
		return(sa(a), 1);
	while (s_a(0, 1) != 3)
	{
		if (min(a, s_a(0, 1)) == 0)
			pb(a, b);
		else if (min(a, s_a(0, 1)) >= s_a(0, 1) / 2)
			rra(a, 0);
		else
			ra(a, 0);
	}
	sa(a);
	if (a[2] < a[1] && a[0] < a[1])
		rra(a, 0);
	else if (a[0] > a[1] && a[1] < a[2])
		ra(a, 0);
	while (s_b(0, 1) != 0)
		pa(a, b);
	return (1);
}

void	sort_right(int *tbs, int s, int *a, int *b)
{
	int	i;

	i = 7;
	while (s_a(0, 1) != 0)
	{
		if (a[0] < tbs[s / 2] && a[0] >= tbs[((12 - i) * s) / 12])
			pb_rb(a, b);
		else if (a[s_a(0, 1) - 1] < tbs[s / 2] && a[s_a(0, 1) - 1]
			>= tbs[((12 - i) * s) / 12])
		{
			rra(a, 0);
			pb_rb(a, b);
		}
		else if (a[0] >= tbs[s / 2] && a[0] <= tbs[(i * s) / 12 - 1])
			pb(a, b);
		else if (a[s_a(0, 1) - 1] >= tbs[s / 2] && a[s_a(0, 1) - 1]
			<= tbs[(i * s) / 12 -1])
		{
			rra(a, 0);
			pb(a, b);
		}
		else
			i = chunk_size(tbs, s, a, i);
	}
}

int	sort_left(int *a, int *b, int *tbs, int mx)
{
	int	i;

	while (s_b(0, 1) != 0)
	{
		i = 0;
		free(tbs);
		tbs = malloc(s_b(0, 1) * sizeof(int));
		if (!tbs)
			return (0);
		while (i < s_b(0, 1))
		{
			tbs[i] = b[i];
			i++;
		}
		ft_sort_int_tab(tbs, s_b(0, 1));
		while (i < s_b(0, 1) - 1 && tbs[i + 1] - tbs[i] < 50)
			i++;
		if (i == s_b(0, 1) && tbs[i] - tbs[i - 1] < 50)
			mx = 0;
		else
			mx = 1;
		condi_total(a, b, mx);
	}
	return (1);
}

void	final_sort(int *a)
{
	if (max(a, s_a(0, 1)) < s_a(0, 1) / 2 && max(a, s_a(0, 1)) != 0)
	{
		while (max(a, s_a(0, 1)) != 0)
			ra(a, 0);
	}
	else if (max(a, s_a(0, 1)) >= s_a(0, 1) / 2 && max(a, s_a(0, 1)) != 0)
	{
		while (max(a, s_a(0, 1)) != (s_a(0, 1) - 1))
			rra(a, 0);
	}
}

int	push_swap(int *a, int *b)
{
	int	*tbs;
	int	s;
	int	mx;

	mx = 0;
	s = 0;
	if (check_order(a) == 1)
		return (1);
	if (s_a(0, 1) <= 5)
		return (sort_short(a, b), 1);
	tbs = malloc(s_a(0, 1) * sizeof(int));
	if (!tbs)
		return (0);
	s = init_tbs(tbs, s_a(0, 1), a);
	sort_right(tbs, s, a, b);
	pa(a, b);
	pa(a, b);
	if (a[1] < a[0] && !(a[max(a, s_a(0, 1))] > b[max(b, s_b(0, 1))]
			&& max(a, s_a(0, 1)) != 0))
		sa(a);
	sort_left(a, b, tbs, mx);
	final_sort(a);
	return (free(tbs), 1);
}
