/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 10:21:23 by marvin            #+#    #+#             */
/*   Updated: 2024/12/22 10:21:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	condi1(int *a, int *b, int mx)
{
	if ((1 + (s_a(0, 1) - chr(a, b[0]))) < (max(b, s_b(0, 1))
			+ chr(a, b[max(b, s_b(0, 1))])) && mx == 0)
		while (chr(a, b[0]) != 0)
			rra(a, 0);
	else if (((max(b, s_b(0, 1)) + chr(a, b[max(b, s_b(0, 1))]))
			<= (1 + (s_a(0, 1) - chr(a, b[0]))) && ((s_a(0, 1) - chr(a, b[0]))
				+ 1) > 0) || mx == 1)
	{
		while (chr(a, b[max(b, s_b(0, 1))]) != 0 && (max(b, s_b(0, 1)) != 0))
			rr(a, b);
		while (chr(a, b[max(b, s_b(0, 1))]) != 0)
			ra(a, 0);
		while (max(b, s_b(0, 1)) != 0)
			rb(b, 0);
	}
}

void	condi2(int *a, int *b, int mx)
{
	if ((1 + (s_a(0, 1) - chr(a, b[0]))) < (max(b, s_b(0, 1))
			+ (s_a(0, 1) - chr(a, b[max(b, s_b(0, 1))]))) && mx == 0)
		while (chr(a, b[0]) != 0)
			rra(a, 0);
	else if (((1 + (s_a(0, 1) - chr(a, b[0])))
			>= (max(b, s_b(0, 1)) + (s_a(0, 1) - chr(a, b[max(b, s_b(0, 1))])))
			&& ((s_a(0, 1) - chr(a, b[0])) + 1) > 0) || mx == 1)
	{
		while (chr(a, b[max(b, s_b(0, 1))]) != 0)
			rra(a, 0);
		while (max(b, s_b(0, 1)) != 0)
			rb(b, 0);
	}
}

void	condi3(int *a, int *b, int mx)
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

void	condi4(int *a, int *b, int mx)
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

void	condi5(int *a, int *b, int mx)
{
	if ((1 + (s_a(0, 1) - chr(a, b[0]))) < ((s_b(0, 1)
				- (max(b, s_b(0, 1))))
			+ chr(a, b[max(b, s_b(0, 1))])) && mx == 0)
		while (chr(a, b[0]) != 0)
			rra(a, 0);
	else if (((1 + (s_a(0, 1) - chr(a, b[0]))) >= ((s_b(0, 1)
					- (max(b, s_b(0, 1)))) + chr(a, b[max(b, s_b(0, 1))]))
			&& ((s_a(0, 1) - chr(a, b[0])) + 1) > 0) || mx == 1)
	{
		while (chr(a, b[max(b, s_b(0, 1))]) != 0)
			ra(a, 0);
		while (max(b, s_b(0, 1)) != 0)
			rrb(b, 0);
	}
}
