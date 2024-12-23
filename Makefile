# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/14 14:36:03 by marvin            #+#    #+#              #
#    Updated: 2024/12/23 17:17:15 by hhecquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS =	check_error.c		\
		condition_1.c		\
		condition_2.c		\
		ft_split.c			\
		instruc_1.c			\
		instruc_2.c			\
		instruc_utils.c		\
		push_swap_utils.c	\
		push_swap.c			\
		search_utils.c

BONUS = checker_check_error.c		\
		checker_instruc_1.c			\
		checker_instruc_2.c			\
		checker_instruc_3.c			\
		instruc_utils.c				\
		ft_split.c					\
		checker.c		

OBJ = $(SRCS:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME) bonus

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(NAME) has been compiled successfully ! ✨"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o checker
	@echo "checker has been compiled successfully ! 🌟"

clean: 
	rm -f $(OBJ) $(BONUS_OBJ)
	@echo "$(NAME)'s object files have been deleted ! 🔥"

fclean: clean
	rm -f checker
	rm -f $(NAME)
	@echo "$(NAME) itself has been deleted ! 💥"

re: fclean all

.PHONY : all clean fclean re
