# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 14:53:11 by dcandeia          #+#    #+#              #
#    Updated: 2022/04/21 11:31:07 by dcandeia         ###   ########.fr        #
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

SRC_NAME =	check_args.c				\
			get_arguments.c				\
			errors.c					\
			utils.c						\
			main.c

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

all: $(NAME)

$(NAME) : $(OBJS)
	make norminette
	$(CC) $(CFLAGS) $(OBJS) $(INC) $(EXTRA_FLAGS) -o $(NAME)
	echo "\x1b[36m[PHILOSOPHERS COMPILED]\x1b[0m"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	mkdir -p objects
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

norminette:
	clear
	echo "\x1b[31m[NORMINETTE]\x1b[0m"
	norminette | egrep -B1 'Error|Warning' | sed ''/Error/s//$(printf "\033[31m\033[4mError\033[0m")/'' | sed ''/Warning/s//$(printf "\033[33m\033[4mWarning\033[0m")/''

clean:
	rm -rf $(OBJ_PATH)
	echo "\033[33mall $(NAME).o files are removed\033[0m"

fclean: clean
	rm -f $(NAME)
	echo "\033[31m$(NAME) is deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re force norminette
