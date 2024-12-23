/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instruc_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:33:20 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/23 14:35:30 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

void	sb(int *tab_b)
{
	int	tmp;

	tmp = tab_b[0];
	tab_b[0] = tab_b[1];
	tab_b[1] = tmp;
}

void	ss(int *tab_a, int *tab_b)
{
	sa(tab_a);
	sb(tab_b);
}
