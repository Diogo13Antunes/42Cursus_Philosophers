# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 14:53:11 by dcandeia          #+#    #+#              #
#    Updated: 2022/10/20 18:23:00 by dcandeia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
EXTRA_FLAGS = -fsanitize=thread -pthread
RM = rm -f

$(VERBOSE).SILENT:

HEADER = philo.h

INC = -I ./includes

SRC_PATH = ./sources

OBJ_PATH = ./objects

SRC_NAME =	check_arguments.c			\
			error_handler.c				\
			start_philosophers.c		\
			str_to_int_converters.c		\
			philos_routine.c			\
			set_arguments.c				\
			utils.c						\
			time_utils.c				\
			actions_utils.c				\
			forks_handler.c				\
			main.c

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

all: $(NAME)

$(NAME) : $(OBJS)
	clear
	@./norm.sh
	$(CC) $(CFLAGS) $(OBJS) $(INC) $(EXTRA_FLAGS) -o $(NAME)
	@echo "\033[1;36m[PHILOSOPHERS COMPILED]\033[0m"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	mkdir -p objects
	$(CC) -c $(CFLAGS) $(EXTRA_FLAGS) $(INCLUDES) $< -o $@

norminette:
	clear
	@./norm.sh

clean:
	rm -rf $(OBJ_PATH)
	@echo "\033[1;33mAll $(NAME).o files are removed\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[1;31m$(NAME) is deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re force norminette
