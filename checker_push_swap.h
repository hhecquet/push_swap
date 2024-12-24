/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_swap.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:35:51 by marvin            #+#    #+#             */
/*   Updated: 2024/12/24 10:30:15 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_PUSH_SWAP_H
# define CHECKER_PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

//checker_check_error.c
int		check_num(char c);
int		check_int(char *av);
int		check_double(int ac, char **av);
void	init_tab(int *tab_a, int *tab_b, char **av, char **split_argv);
//checker_ft_split.c
char	**ft_split(char const *s, char c);
void	ft_free(char **tab, int size);
//checker_instruc_1.c
void	sa(int *tab_a);
void	pa(int *tab_a, int *tab_b);
void	pb(int *tab_a, int *tab_b);
void	ra(int *tab_a);
void	rb(int *tab_b);
//checker_instruc_2.c
void	rr(int *tab_a, int *tab_b);
void	rra(int *tab_a);
void	rrb(int *tab_b);
void	rrr(int *tab_a, int *tab_b);
void	pb_rb(int *a, int *b);
//checker_instruc_3.c
void	sb(int *tab_b);
void	ss(int *tab_a, int *tab_b);
//checker_instruc_utils.c
int		s_a(int i, int read_only);
int		s_b(int i, int read_only);
int		g_ac(int i, int read_only);
int		ft_atoi(const char *nptr);
int		ft_strcmp(char *s1, char *s2);
//checker.c
int		check_order(int *a);
int		check_read(int *tab_a, int *tab_b, int tot);
//checker_ft_split.c
char	**ft_split(char const *s, char c);
void	ft_free(char **tab, int size);

#endif