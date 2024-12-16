/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:35:51 by marvin            #+#    #+#             */
/*   Updated: 2024/12/16 12:47:09 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strcmp(char *s1, char *s2);
int		check_num(char c);
int		check_int(char *av);
int		check_double(int ac, char **av);
void	sa(int *tab_a);
void	sb(int *tab_b);
void	ss(int *tab_a, int *tab_b);
void	pa(int *tab_a, int *tab_b, int size_a, int size_b);
void	pb(int *tab_a, int *tab_b, int size_a, int size_b);
void	ra(int *tab_a, int size_a);
void	rb(int *tab_b, int size_b);
void	rr(int *tab_a, int *tab_b, int size_a, int size_b);
void	rra(int *tab_a, int size_a);
void	rrb(int *tab_b, int size_b);
void	rrr(int *tab_a, int *tab_b, int size_a, int size_b);
int		g_size_a(int i, int read_only);
int		g_size_b(int i, int read_only);
int		g_sign(int i, int read_only);
int		check_orderb(int *tab_a, int *tab_b);
int		ft_atoi(const char *nptr);
int		*take_min(int *tab_a);
int		ft_strcmp_plus(int *tab_a, int *tab_b);
int		g_tmp(int i, int read_only);
int		push_swap(int *tab_a, int *tab_b, int size_a, int size_b);

#endif