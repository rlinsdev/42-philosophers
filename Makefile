# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 08:04:25 by rlins             #+#    #+#              #
#    Updated: 2023/01/24 08:39:37 by rlins            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

# Collors
RESET 	= \033[0m
GREEN 	= \033[0;32m
RED 	= \033[0;31m

# Paths
PATH_SRC 		= ./src/
PATH_UTIL 		= $(PATH_SRC)util/
PATH_OBJS 		= ./objs/

INC_PATH 		= ./include/

# Compilation
CC = gcc -pthread

# Compilation flags
# CFLAGS = -g -fsanitize=thread # -fsanitize=thread = Warning datarace. This don't work with valgrind
CFLAGS = -g # -fsanitize=thread = Warning datarace
# CFLAGS = -g -Wall -Werror -Wextra

#Chedk Leak memory
 LEAK = valgrind --leak-check=full --show-leak-kinds=all \
	--trace-children=yes --track-origins=yes -s
# Thread error detections:
# LEAK = --tool=helgrind
# LEAK = --tool=drd

RM			= rm -rf
NO_PRINT	= --no-print-directory
READ_LN		= -l readline

INCLUDE = -I $(INC_PATH)

SRCS =	$(PATH_SRC)main.c \
		$(PATH_UTIL)ft_ato_long.c \

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCLUDE) $(READ_LN)
	@echo "$(GREEN)Build Successful$(RESET)"

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)util/
	@$(CC) $(CFLAGS) $(INCLUDE) -I. -c $< -o $@

clean:
	@echo "$(RED)Cleaning objects...$(RESET)"
	@$(RM) $(PATH_OBJS)
# @make -C clean $(NO_PRINT)
	@echo "$(GREEN)Done!$(RESET)"

fclean: clean
	@echo  "$(RED)Cleaning all...$(RESET)"
	@$(RM) $(NAME)
# @make -C fclean $(NO_PRINT)
	@echo "$(RED)Cleaning binaries...$(RESET)"
	@echo "$(GREEN)Done!$(RESET)"

re: fclean all

bonus: all

rebonus: fclean all

run:
	make re && ./philo "5" "86400000" "3600000" "28800000" "2"

valgrind:
	$(LEAK) ./philo "5" "86400000" "3600000" "28800000" "2"

.PHONY: all run re clean fclean
