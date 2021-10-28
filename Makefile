# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 14:42:54 by cjang             #+#    #+#              #
#    Updated: 2021/10/28 22:34:24 by cjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit -lz
MLX_DIR = -L./mlx_opengl

MLX_OPENGL = mlx_opengl

LIBFT = libft
LIBFT_A = libft/libft.a

SRCS = so_long.c map_checker.c mlx_test.c error_function.c init_function.c

OBJS = $(SRCS:.c=.o)

NAME_SO_LONG = so_long

all: $(LIBFT) $(MLX_OPENGL) $(NAME_SO_LONG)

$(LIBFT):
	@make -C $(LIBFT)

$(MLX_OPENGL):
	@make -C $(MLX_OPENGL)

$(NAME_SO_LONG): $(LIBFT_A) $(OBJS)
	$(CC) $(MLX_DIR) $(MLX) $(LIBFT_A) $(OBJS) -o $(NAME_SO_LONG)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	make clean -C $(LIBFT)
	make clean -C $(MLX_OPENGL)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME_SO_LONG)

re: fclean all

.PHONY: all bonus clean fclean re $(LIBFT) $(MLX_OPENGL)
