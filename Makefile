# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 14:42:54 by cjang             #+#    #+#              #
#    Updated: 2021/10/28 18:25:45 by cjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit -lz

LIBFT = libft
LIBFT_A = libft/libft.a

SRCS = so_long.c map_checker.c mlx_test.c error_function.c init_function.c

OBJS = $(SRCS:.c=.o)

NAME_SO_LONG = so_long

all: $(LIBFT) $(NAME_SO_LONG)

$(LIBFT):
	@make -C $(LIBFT)

$(NAME_SO_LONG): $(LIBFT_A) $(OBJS)
	$(CC) $(MLX) $(LIBFT_A) $(OBJS) -o $(NAME_SO_LONG)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME_SO_LONG)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all bonus clean fclean re $(LIBFT)
