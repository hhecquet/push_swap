# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/14 14:36:03 by marvin            #+#    #+#              #
#    Updated: 2024/12/14 14:36:03 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS =	parser/check_error.c	\
		push/push_swap.c 	\
		instructions/instruc_1.c		\
		instructions/instruc_2.c		\
		instructions/instruc_3.c	

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(NAME) has been compiled successfully ! ✨"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)
	@echo "$(NAME)'s object files have been deleted ! 🔥"

fclean: clean
	rm -f $(NAME)
	@echo "$(NAME) itself has been deleted ! 💥"

re: fclean all

.PHONY : all clean fclean re
