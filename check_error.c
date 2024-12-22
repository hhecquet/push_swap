/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:04:50 by marvin            #+#    #+#             */
/*   Updated: 2024/12/19 12:51:18 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_int(char *av)
{
	int		i;
	long	n;
	int		sign;

	i = 0;
	sign = 1;
	n = 0;
	if (av[i] == '-')
	{
		i++;
		sign *= -1;
	}
	while (check_num(av[i]) == 1 && av[i])
	{
		n = n * 10 + av[i] - '0';
		if (n * sign < -2147483648 || n * sign > 2147483647)
			return (0);
		i++;
	}
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	check_double(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	if (ac == 1)
		return (0);
	while (j < ac && check_int(av[j]) != 0)
		j++;
	if (j < ac)
		return (0);
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	init_tab(int *tab_a, int *tab_b, char **av)
{
	int	i;

	i = 0;
	while (i < s_a(0, 1))
	{
		tab_a[i] = ft_atoi(av[i + 1]);
		tab_b[i] = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		*tab_a;
	int		*tab_b;

	g_ac(argc, 0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	s_a(g_ac(0, 1) - 1, 0);
	s_b(0, 0);
	if (check_double(g_ac(0, 1), argv) == 0)
		return (write(1, "Error\n", 6), 0);
	tab_a = malloc(sizeof(int *) * s_a(0, 1));
	tab_b = malloc(sizeof(int *) * s_a(0, 1));
	if (!tab_a || !tab_b)
		return (free(tab_a), free(tab_b), 0);
	init_tab(tab_a, tab_b, argv);
	push_swap(tab_a, tab_b);
	return (free(tab_a), free(tab_b), 0);
}
