# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 16:50:46 by cjang             #+#    #+#              #
#    Updated: 2021/11/20 17:04:23 by cjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =			get_next_line.c\
				get_next_line_utils.c
SRCS_BONUS =	get_next_line_bonus.c\
				get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef BONUS_INCLUDE
	OBJS_FILE = $(OBJS_BONUS)
else
	OBJS_FILE = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS_FILE)
	ar rc $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

bonus:
	@make BONUS_INCLUDE=1 all

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
