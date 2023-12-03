# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 01:50:28 by pamone            #+#    #+#              #
#    Updated: 2023/11/29 01:50:28 by pamone           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap.a
FLAGS	=	-Wall -Wextra -Werror -I. -c 
CC		= 	cc
SRC		=	operation_a.c operations_helper.c push_swap.c push_swap_utils.c \
			b_operation.c operations_helper_one.c parse_args.c split_operation.c \
			sorting_algorithms.c main.c


OBJ = $(SRC:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
%.o: %.c
	$(CC) $(FLAGS) $< -o $@
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) 

re: fclean all

.PHONY: all clean fclean re

