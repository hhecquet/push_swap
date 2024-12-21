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

//cas particulier 1 2 et 3 voir 4 a 5 + " " segfault
int	push_swap(int *a, int *b)
{
	int	i;
	int	j;
	int	*tbs;
	int	s;
	int	mx;

	i = 0;
	j = 0;
	mx = 0;
	s = 0;
	tbs = malloc(s_a(0, 1) * sizeof(int));
	if (!tbs)
		return (0);
	while (i < s_a(0, 1))
	{
		tbs[i] = a[i];
		i++;
	}
	ft_sort_int_tab(tbs, s_a(0, 1));
	s = s_a(0, 1);
	i = 7;
	while (s_a(0, 1) != 0)
	{
		if (a[0] < tbs[s / 2] && a[0] >= tbs[((12 - i) * s) / 12])
		{
			pb(a, b);
			rb(b, 0);
		}
		else if (a[s_a(0, 1) - 1] < tbs[s / 2] && a[s_a(0, 1) - 1]
			>= tbs[((12 - i) * s) / 12])
		{
			rra(a, 0);
			pb(a, b);
			rb(b, 0);
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
		{
			j = 0;
			while (j < s_a(0, 1) && (a[j] < tbs[((12 - i) * s) / 12] || a[j]
					>= tbs[(i * s) / 12]))
				j++;
			if (j == s_a(0, 1))
				i++;
			else
			{
				if (j < s_a(0, 1) / 2)
				{
					while (j != 0)
					{
						ra(a, 0);
						j--;
					}
				}
				else
				{
					j = s_a(0, 1) - j;
					while (j != 0)
					{
						rra(a, 0);
						j--;
					}
				}
			}
		}
	}
	pa(a, b);
	pa(a, b);
	if (a[1] < a[0] && !(a[max(a, s_a(0, 1))] > b[max(b, s_b(0, 1))]
			&& max(a, s_a(0, 1)) != 0))
		sa(a);
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
		if (((chr(a, b[max(b, s_b(0, 1))])) == 0 && max(b, s_b(0, 1)) == 0)
			|| chr(a, b[0]) == 0)
			pa(a, b);
		else if (a[s_a(0, 1) - 1] > b[0] && a[s_a(0, 1) - 1] < a[0]
			&& a[s_a(0, 1) - 1] > b[max(b, s_b(0, 1))])
			rra(a, 0);
		if (max(b, s_b(0, 1)) < s_b(0, 1) / 2)
		{
			if (chr(a, b[0]) >= s_a(0, 1) / 2)
			{
				if (chr(a, b[max(b, s_b(0, 1))]) < s_a(0, 1) / 2)
				{
					if ((1 + (s_a(0, 1) - chr(a, b[0]))) < (max(b, s_b(0, 1))
							+ chr(a, b[max(b, s_b(0, 1))])) && mx == 0)
						while (chr(a, b[0]) != 0)
							rra(a, 0);
					else if (((max(b, s_b(0, 1)) + chr(a, b[max(b, s_b(0, 1))]))
							<= (1 + (s_a(0, 1) - chr(a, b[0]))) && ((s_a(0, 1)
									- chr(a, b[0])) + 1) > 0) || mx == 1)
					{
						while (chr(a, b[max(b, s_b(0, 1))]) != 0
							&& (max(b, s_b(0, 1)) != 0))
							rr(a, b);
						while (chr(a, b[max(b, s_b(0, 1))]) != 0)
							ra(a, 0);
						while (max(b, s_b(0, 1)) != 0)
							rb(b, 0);
					}
				}
				else
				{
					if ((1 + (s_a(0, 1) - chr(a, b[0]))) < (max(b, s_b(0, 1))
							+ (s_a(0, 1) - chr(a, b[max(b, s_b(0, 1))])))
						&& mx == 0)
						while (chr(a, b[0]) != 0)
							rra(a, 0);
					else if (((1 + (s_a(0, 1) - chr(a, b[0])))
							>= (max(b, s_b(0, 1)) + (s_a(0, 1)
									- chr(a, b[max(b, s_b(0, 1))])))
							&& ((s_a(0, 1) - chr(a, b[0])) + 1) > 0)
						|| mx == 1)
					{
						while (chr(a, b[max(b, s_b(0, 1))]) != 0)
							rra(a, 0);
						while (max(b, s_b(0, 1)) != 0)
							rb(b, 0);
					}
				}
			}
			else if (chr(a, b[0]) < s_a(0, 1) / 2)
			{
				if (chr(a, b[max(b, s_b(0, 1))]) < s_a(0, 1) / 2)
				{
					if (1 + (chr(a, b[0])) < (max(b, s_b(0, 1))
							+ chr(a, b[max(b, s_b(0, 1))])) && mx == 0)
						while (chr(a, b[0]) != 0)
							ra(a, 0);
					else if ((1 + (chr(a, b[0])) >= (max(b, s_b(0, 1))
								+ chr(a, b[max(b, s_b(0, 1))]))
							&& (chr(a, b[0]) + 1) > 0) || mx == 1)
					{
						while (chr(a, b[max(b, s_b(0, 1))]) != 0
							&& (max(b, s_b(0, 1)) != 0))
							rr(a, b);
						while (chr(a, b[max(b, s_b(0, 1))]) != 0)
							ra(a, 0);
						while (max(b, s_b(0, 1)) != 0)
							rb(b, 0);
					}
				}
				else
				{
					if (1 + (chr(a, b[0])) < (max(b, s_b(0, 1)) + (s_a(0, 1)
								- chr(a, b[max(b, s_b(0, 1))]))) && mx == 0)
						while (chr(a, b[0]) != 0)
							ra(a, 0);
					else if ((1 + (chr(a, b[0])) >= (max(b, s_b(0, 1))
								+ (s_a(0, 1) - chr(a, b[max(b, s_b(0, 1))])))
							&& (chr(a, b[0]) + 1) > 0) || mx == 1)
					{
						while (chr(a, b[max(b, s_b(0, 1))]) != 0)
							rra(a, 0);
						while (max(b, s_b(0, 1)) != 0)
							rb(b, 0);
					}
				}
			}
		}
		else
		{
			if (chr(a, b[0]) >= s_a(0, 1) / 2)
			{
				if (chr(a, b[max(b, s_b(0, 1))]) < s_a(0, 1) / 2)
				{
					if ((1 + (s_a(0, 1) - chr(a, b[0]))) < ((s_b(0, 1)
								- (max(b, s_b(0, 1))))
							+ chr(a, b[max(b, s_b(0, 1))])) && mx == 0)
						while (chr(a, b[0]) != 0)
							rra(a, 0);
					else if (((1 + (s_a(0, 1) - chr(a, b[0]))) >= ((s_b(0, 1)
									- (max(b, s_b(0, 1))))
								+ chr(a, b[max(b, s_b(0, 1))]))
							&& ((s_a(0, 1) - chr(a, b[0])) + 1) > 0) || mx == 1)
					{
						while (chr(a, b[max(b, s_b(0, 1))]) != 0)
							ra(a, 0);
						while (max(b, s_b(0, 1)) != 0)
							rrb(b, 0);
					}
				}
				else
				{
					if ((1 + (s_a(0, 1) - chr(a, b[0]))) < ((s_b(0, 1)
								- (max(b, s_b(0, 1)))) + (s_a(0, 1)
								- chr(a, b[max(b, s_b(0, 1))]))) && mx == 0)
						while (chr(a, b[0]) != 0)
							rra(a, 0);
					else if (((1 + (s_a(0, 1) - chr(a, b[0]))) >= ((s_b(0, 1)
									- (max(b, s_b(0, 1)))) + (s_a(0, 1)
									- chr(a, b[max(b, s_b(0, 1))])))
							&& ((s_a(0, 1) - chr(a, b[0])) + 1) > 0) || mx == 1)
					{
						while (chr(a, b[max(b, s_b(0, 1))]) != 0
							&& (max(b, s_b(0, 1)) != 0))
							rrr(a, b);
						while (chr(a, b[max(b, s_b(0, 1))]) != 0)
							rra(a, 0);
						while (max(b, s_b(0, 1)) != 0)
							rrb(b, 0);
					}
				}
			}
			else if (chr(a, b[0]) < s_a(0, 1) / 2)
			{
				if (chr(a, b[max(b, s_b(0, 1))]) < s_a(0, 1) / 2)
				{
					if (1 + (chr(a, b[0])) < ((s_b(0, 1) - (max(b, s_b(0, 1))))
							+ chr(a, b[max(b, s_b(0, 1))])) && mx == 0)
						while (chr(a, b[0]) != 0)
							ra(a, 0);
					else if ((1 + (chr(a, b[0])) >= ((s_b(0, 1)
									- (max(b, s_b(0, 1))))
								+ chr(a, b[max(b, s_b(0, 1))])) && (chr(a, b[0])
								+ 1) > 0) || mx == 1)
					{
						while (chr(a, b[max(b, s_b(0, 1))]) != 0)
							ra(a, 0);
						while (max(b, s_b(0, 1)) != 0)
							rrb(b, 0);
					}
				}
				else
				{
					if (1 + (chr(a, b[0])) < ((s_b(0, 1) - (max(b, s_b(0, 1))))
							+ (s_a(0, 1) - chr(a, b[max(b, s_b(0, 1))])))
						&& mx == 0)
						while (chr(a, b[0]) != 0)
							ra(a, 0);
					else if ((1 + (chr(a, b[0])) >= ((s_b(0, 1)
									- (max(b, s_b(0, 1)))) + (s_a(0, 1)
									- chr(a, b[max(b, s_b(0, 1))])))
							&& (chr(a, b[0]) + 1) > 0) || mx == 1)
					{
						while (chr(a, b[max(b, s_b(0, 1))]) != 0
							&& (max(b, s_b(0, 1)) != 0))
							rrr(a, b);
						while (chr(a, b[max(b, s_b(0, 1))]) != 0)
							rra(a, 0);
						while (max(b, s_b(0, 1)) != 0)
							rrb(b, 0);
					}
				}
			}
		}
	}
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
	return (free(tbs), 1);
}
