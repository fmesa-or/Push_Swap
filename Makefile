# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 19:41:56 by fmesa-or          #+#    #+#              #
#    Updated: 2024/08/05 14:26:26 by fmesa-or         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME			:= push_swap

#Compile
CC				:= cc

#Flags
CFLAGS			:= -Wextra -Wall -Werror -g

#Clean
CLEAN			:= rm -Rf

#LIBFT
LIBFT_DIR		:= ./lib/libft
LIBFT			:= $(LIBFT_DIR)/libft.a

#Sources
SRCS_DIR		:= ./src
SRCS			:= ./src/algorithm.c ./src/checkers.c ./src/errors.c \
				   ./src/ft_free.c ./src/ft_sortbig.c ./src/main.c \
				   ./src/push.c ./src/reverse.c ./src/rotate.c \
				   ./src/sort_3.c ./src/sort_utils.c ./src/stck_utils.c \
				   ./src/swap.c ./src/utils.c

#Objects
OBJS_DIR		:= ./obj
OBJS			:= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

#Headers
HEADERS			:= -I ./include -I $(LIBFT_DIR)

#COLORS
COLOR_INFO = \033[1;36m
COLOR_SUCCESS = \033[1;32m
COLOR_RESET = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) && printf "$(COLOR_INFO)Compiling: $(notdir $<)$(COLOR_RESET)\t\t"
	@sleep 0.25
	@printf "✅\n"

$(LIBFT):
	@printf "$(COLOR_INFO)Building libft...$(COLOR_RESET)\t\t"
	@make -s -C $(LIBFT_DIR)
	@sleep 0.25
	@printf "✅\n"

clean:
	@printf "$(COLOR_INFO)Cleaning as fast as I can$(COLOR_RESET)\t"
	@$(CLEAN) $(OBJS_DIR)
	@make -s clean -C $(LIBFT_DIR)
	@sleep 0.25
	@printf "✅\n"

fclean: clean
	@printf "$(COLOR_INFO)Deleting push_swap$(COLOR_RESET)\t\t"
	@$(CLEAN) $(NAME)
	@make -s fclean -C $(LIBFT_DIR)
	@sleep 0.25
	@printf "✅\n"

re: fclean clean all

.PHONY: all, clean, fclean, re
