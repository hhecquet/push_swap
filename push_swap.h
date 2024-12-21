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
void	pa(int *tab_a, int *tab_b);
void	pb(int *tab_a, int *tab_b);
void	ra(int *tab_a, int rr);
void	rb(int *tab_b, int rr);
//instruc_2.c
void	rr(int *tab_a, int *tab_b);
void	rra(int *tab_a, int rrr);
void	rrb(int *tab_b, int rrr);
void	rrr(int *tab_a, int *tab_b);
//instruc_3.c
int		s_a(int i, int read_only);
int		s_b(int i, int read_only);
int		ft_atoi(const char *nptr);
//ft_split.c
char	**ft_split(char const *s, char c);
//push_swap.c
int		min(int *tab, int size);
int		max(int *tab, int size);
int		push_swap(int *tab_a, int *tab_b);
int		chr(int *a, int b0);
//sort_tab.c
void	ft_sort_int_tab(int *tab_sort, int size);

#endif