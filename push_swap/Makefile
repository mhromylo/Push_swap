# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 17:46:09 by mhromylo          #+#    #+#              #
#    Updated: 2024/01/23 17:03:26 by mhromylo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = \
atoi_long.c \
errors.c \
fill_node.c \
fill_stack_a.c \
pa.c \
ra.c \
rra.c \
push_swap.c \
sa.c \
sort_tree.c \
sort.c \
split_static.c \
stack_sorted.c

OBJECTS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap



all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

clean :
		rm -f *.o
		$(MAKE) -C $(LIBFT_DIR) clean
fclean: clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		rm -f $(NAME)
re: fclean all

