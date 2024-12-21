/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:35:51 by marvin            #+#    #+#             */
/*   Updated: 2024/12/18 15:17:23 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>


//check_error.c
int		ft_strcmp(char *s1, char *s2);
int		check_num(char c);
int		check_int(char *av);
int		check_double(int ac, char **av);
void	init_tab(int *tab_a, int *tab_b, char **av);
int		g_ac(int i, int read_only);
//instruc_1.c
void	sa(int *tab_a);
void	sb(int *tab_b);
void	ss(int *tab_a, int *tab_b);
void	pa(int *tab_a, int *tab_b, int size_a, int size_b);
void	pb(int *tab_a, int *tab_b, int size_a, int size_b);
//instruc_2.c
void	ra(int *tab_a, int size_a, int rr);
void	rb(int *tab_b, int size_b, int rr);
void	rr(int *tab_a, int *tab_b, int size_a, int size_b);
void	rra(int *tab_a, int size_a, int rrr);
void	rrb(int *tab_b, int size_b, int rrr);
//instruc_3.c
void	rrr(int *tab_a, int *tab_b, int size_a, int size_b);
int		g_size_a(int i, int read_only);
int		g_size_b(int i, int read_only);
int		g_tmp(int i, int read_only);
int		g_sign(int i, int read_only);
int		g_min(int i, int read_only);
int		g_max(int i, int read_only);
int		ft_atoi(const char *nptr);
//ft_split.c
char	**ft_split(char const *s, char c);
//push_swap.c
int		chr_min(int *tab, int size);
int		chr_max(int *tab, int size);
int		*take_min(int *tab_a);
int		ft_strcmp_plus(int *tab_a, int *tab_b);
int		check_order(int *tab, int size);
int		check_order_plus(int *tab_a, int *tab_b);
int		push_swap(int *tab_a, int *tab_b);
//sort_tab.c
void	ft_sort_int_tab(int *tab_sort, int size);
int     ft_compare_int_tab(int *tab_b);

#endif