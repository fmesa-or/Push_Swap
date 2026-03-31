# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 14:42:25 by fmesa-or          #+#    #+#              #
#    Updated: 2024/01/29 18:37:47 by fmesa-or         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -Wall -Werror -Wextra
CC		= gcc
CLEAN	= rm -Rf
SRC		= ft_printf.c ft_printf_utils.c ft_printf_utils2.c

OBJS	= $(SRC:.c=.o)
all: $(NAME)
$(NAME):$(OBJS)
	@ar rcs $(NAME) $(OBJS)
%.o	: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@$(CLEAN) $(OBJS)
fclean:
	@$(CLEAN) $(OBJS)
	@$(CLEAN) $(NAME)
re: fclean all
.PHONY	:	all bonus clean fclean re
