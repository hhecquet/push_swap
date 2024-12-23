/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:15:43 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/23 17:40:29 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

int	check_order(int *a)
{
	int	i;

	i = 0;
	while (i < s_a(0, 1) - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if ((!dest && !src) || (!dest && !src && !n))
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(const char *)(src + i);
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
		{
			*(unsigned char *)(dest + i) = *(const char *)(src + i);
		}
	}
	return (dest);
}

static char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

int	check_read_if(int *tab_a, int *tab_b, char *buffer, char *newline)
{
	*newline = '\0';
	if (!strcmp(buffer, "sa"))
		return (sa(tab_a), 1);
	else if (!strcmp(buffer, "sb"))
		return (sb(tab_b), 1);
	else if (!strcmp(buffer, "ss"))
		return (ss(tab_a, tab_b), 1);
	else if (!strcmp(buffer, "pa"))
		return (pa(tab_a, tab_b), 1);
	else if (!strcmp(buffer, "pb"))
		return (pb(tab_a, tab_b), 1);
	else if (!strcmp(buffer, "ra"))
		return (ra(tab_a), 1);
	else if (!strcmp(buffer, "rb"))
		return (rb(tab_b), 1);
	else if (!strcmp(buffer, "rr"))
		return (rr(tab_a, tab_b), 1);
	else if (!strcmp(buffer, "rra"))
		return (rra(tab_a), 1);
	else if (!strcmp(buffer, "rrb"))
		return (rrb(tab_b), 1);
	else if (!strcmp(buffer, "rrr"))
		return (rrr(tab_a, tab_b), 1);
	else
		return (0);
}

int	check_read(int *tab_a, int *tab_b, int tot)
{
	char	buffer[100];
	ssize_t	bytes_read;
	char	*newline;

	tot = 0;
	bytes_read = read(0, buffer + tot, sizeof(buffer) - 1 - tot);
	while (bytes_read > 0)
	{
		tot += bytes_read;
		buffer[tot] = '\0';
		newline = ft_strchr(buffer, '\n');
		while (newline != NULL)
		{
			if (check_read_if(tab_a, tab_b, buffer, newline) == 0)
				return (write(1, "Error\n", 6), 0);
			tot -= (newline - buffer + 1);
			ft_memmove(buffer, newline + 1, tot);
			newline = ft_strchr(buffer, '\n');
		}
		bytes_read = read(0, buffer + tot, sizeof(buffer) - 1 - tot);
	}
	if (check_order(tab_a) == 1 && s_b(0, 1) == 0)
		return (write(1, "OK\n", 3), 0);
	else
		return (write(1, "KO\n", 3), 0);
}
