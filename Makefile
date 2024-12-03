# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiensal <jpiensal@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 14:42:28 by jpiensal          #+#    #+#              #
#    Updated: 2024/11/29 15:04:01 by jpiensal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c ft_printf_utils.c ft_putchar_n.c ft_putstr_n.c \
	   ft_printnbr_n.c ft_printptr_n.c ft_printhex_n.c

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

.PHONY: all clean fclean re
