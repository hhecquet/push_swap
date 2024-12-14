/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:35:51 by marvin            #+#    #+#             */
/*   Updated: 2024/12/14 14:35:51 by marvin           ###   ########.fr       */
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
void	sa(int tab_a1, int tab_a2);
void	sb(int tab_b1, int tab_b2);
void	ss(int tab_a1, int tab_a2, int tab_b1, int tab_b2);
void	pa(int tab_b, int *tab_a, int size_a);
void	pb(int tab_a, int *tab_b, int size_b);
void	ra(int *tab_a, int size_a);
void	rb(int *tab_b, int size_b);
void	rr(int *tab_a, int *tab_b, int size_a, int size_b);
void	rra(int *tab_a, int size_a);
void	rrb(int *tab_b, int size_b);
void	rrr(int *tab_a, int *tab_b, int size_a, int size_b);
int		g_size_a(int i, int read_only);
int		g_size_b(int i, int read_only);
int		ft_atoi(const char *nptr);
void	init_tab(int tab_a[500], int tab_b[500], int size_a, char **av);
int		ft_strcmp_plus(int tab0, int tab1, int tablst);
int		ft_strcmp_tmp(int tab0);
int     push_swap(int tab_a[500], int tab_b[500], int size_a, int size_b);

#endif