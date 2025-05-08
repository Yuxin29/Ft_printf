# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 09:58:20 by yuwu              #+#    #+#              #
#    Updated: 2025/05/08 10:07:31 by yuwu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERS := libftprintf.h
NAME := libftprintf.a
CFLAGS := -Wall -Wextra -Werror
CC := cc

SRCS := ft_printf.c \
		ft_putchar.c \
		ft_putstr.c	\
		xxx	\

OBJS := $(SRCS:%.c=%.o)

$ (NAME): $(OBJS)
		ar -rcs $@ $^

%.o: %.c &(HEADERS)
		cc -c $< -o $@ $(CFLAGS)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re			
