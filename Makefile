# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiensal <jpiensal@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 14:42:28 by jpiensal          #+#    #+#              #
#    Updated: 2024/11/20 10:39:56 by jpiensal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_putchar_n.c ft_putstr_n.c ft_putnbr_base_n.c ft_putptr_n.c
OBJS = $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
				@ar -rcs $(NAME) $^

%.o: %.c
				$(CC) -c $< $(CFLAGS)

clean:
				@rm -f $(OBJS)

fclean:
				@rm -f $(OBJS) $(NAME)

re:			fclean all
