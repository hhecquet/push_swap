/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:04:50 by marvin            #+#    #+#             */
/*   Updated: 2024/12/14 11:04:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

int check_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return(0);
}

int check_int(char *av)
{
	int		i;
	long 	n;
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
		if (n*sign < -2147483648 || n*sign > 2147483647)
			return(0);
		i++;
	}
	if (av[i] != '\0')
		return(0);
	return(1);
}

int check_double(int ac, char **av)
{
	int		i;
	int 	j;

	i = 1;
	j = 1;
	if (ac == 1)
		return (0);
	while (j < ac && check_int(av[j]) != 0)
		j++;
	if (j < ac)
		return(0);
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i],av[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (check_double(argc, argv) == 0)
		return(write(1,"Error\n",6),0);
	write(1, "biennnn\n", 8);
	//el famoso push swap
	return(0);
}
