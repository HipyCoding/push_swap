# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: christian <christian@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 18:11:58 by candrese          #+#    #+#              #
#    Updated: 2024/10/09 16:04:55 by christian        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
BONUS_NAME	:= checker
CFLAGS		:= -Wall -Wextra -Werror -g3 #-fsanitize=address

SRCS	:= main.c utils.c split.c parse_args.c\
	operator_push.c operator_rotate.c operator_rev_rotate.c\
	free_exit.c checks.c sort.c sorting_utils.c operator_swap.c

BONUS_SRC	:= bonus_checker.c \
		utils.c \
		split.c \
		parse_args.c\
		operator_push.c \
		operator_swap.c \
		operator_rotate.c \
		operator_rev_rotate.c \
		checks.c \
		sorting_utils.c \
		free_exit.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

OBJS	:= ${SRCS:.c=.o}

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ)  
	@$(CC) $(BONUS_OBJ) $(HEADERS) -o $(BONUS_NAME)
	@echo "bonus compiled"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "\nCompiling: $(notdir $<)"

clean:
	@echo "cleaning..."
	@rm -rf $(OBJS) $(BONUS_OBJ)

fclean: clean
	@echo "full clean..."
	@rm -rf $(NAME) $(BONUS_NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
