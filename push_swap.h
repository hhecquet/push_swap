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
int		check_num(char c);
int		check_int(char *av);
int		check_double(int ac, char **av);
void	init_tab(int *tab_a, int *tab_b, char **av);
//condition_1.c
void	condi1(int *a, int *b, int mx);
void	condi2(int *a, int *b, int mx);
void	condi3(int *a, int *b, int mx);
void	condi4(int *a, int *b, int mx);
void	condi5(int *a, int *b, int mx);
//condition_2.c
void	condi6(int *a, int *b, int mx);
void	condi7(int *a, int *b, int mx);
void	condi8(int *a, int *b, int mx);
void	condi1_to_4(int *a, int *b, int mx);
void	condi5_to_8(int *a, int *b, int mx);
//ft_split.c
char	**ft_split(char const *s, char c);
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
void	pb_rb(int *a, int *b);
//instruc_utils.c
int		s_a(int i, int read_only);
int		s_b(int i, int read_only);
int		g_ac(int i, int read_only);
int		ft_atoi(const char *nptr);
int		ft_strcmp(char *s1, char *s2);
//push_swap_utils.c
void	condi_total(int *a, int *b, int mx);
int		chunk_size(int *tbs, int s, int *a, int i);
int		check_order(int *a);
//push_swap.c
void    short_sort(int *a, int *b);
void	sort_right(int *tbs, int s, int *a, int *b);
int		sort_left(int *a, int *b, int *tbs, int mx);
void	final_sort(int *a);
int		push_swap(int *tab_a, int *tab_b);
//search_utils.c
void	ft_sort_int_tab(int *tab_sort, int size);
int		min(int *tab, int size);
int		max(int *tab, int size);
int		chr(int *a, int b0);
int		init_tbs(int *tbs, int s, int *tab);

#endif