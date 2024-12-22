/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 10:21:52 by marvin            #+#    #+#             */
/*   Updated: 2024/12/22 10:21:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	condi6(int *a, int *b, int mx)
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

void	condi7(int *a, int *b, int mx)
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

void	condi8(int *a, int *b, int mx)
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

void	condi1_to_4(int *a, int *b, int mx)
{
	if (chr(a, b[0]) >= s_a(0, 1) / 2)
	{
		if (chr(a, b[max(b, s_b(0, 1))]) < s_a(0, 1) / 2)
			condi1(a, b, mx);
		else
			condi2(a, b, mx);
	}
	else
	{
		if (chr(a, b[max(b, s_b(0, 1))]) < s_a(0, 1) / 2)
			condi3(a, b, mx);
		else
			condi4(a, b, mx);
	}
}

void	condi5_to_8(int *a, int *b, int mx)
{
	if (chr(a, b[0]) >= s_a(0, 1) / 2)
	{
		if (chr(a, b[max(b, s_b(0, 1))]) < s_a(0, 1) / 2)
			condi5(a, b, mx);
		else
			condi6(a, b, mx);
	}
	else
	{
		if (chr(a, b[max(b, s_b(0, 1))]) < s_a(0, 1) / 2)
			condi7(a, b, mx);
		else
			condi8(a, b, mx);
	}
}
