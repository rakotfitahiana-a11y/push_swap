# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfitahin <nfitahin@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/26 13:32:03 by henirako          #+#    #+#              #
#    Updated: 2026/03/27 08:39:13 by nfitahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC         = apply_sort.c \
            bench.c \
            compute_disorder.c \
            fonction_utils_1.c \
            fonction_utils_2.c \
            fonction_utils_3.c \
            fonction_utils_4.c \
            ft_split.c \
            get_max_pos.c \
            get_min_pos.c \
            get_stack_size.c \
            indexing.c \
            main.c \
            parsing.c \
            push.c \
            reverse_rotate.c \
            rotate.c \
            sort_3.c \
            sort_4.c \
            sort_5.c \
            sort_adaptive.c \
            sort_complex.c \
            sort_medium.c \
            sort_simple.c \
            swap.c \
            init_context.c

OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
