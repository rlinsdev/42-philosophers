# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 08:04:25 by rlins             #+#    #+#              #
#    Updated: 2023/01/24 09:22:15 by rlins            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

# Collors
RESET 	= \033[0m
GREEN 	= \033[0;32m
RED 	= \033[0;31m

OBJ_DIR	=	obj
OBJS	=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

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

SRCS =	main.c \
		ft_ato_long.c \

OBJS	=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Build Successful$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@echo "$(RED)Cleaning objects...$(RESET)"
	@$(RM) obj
	@echo "$(GREEN)Done!$(RESET)"

fclean: clean
	@echo  "$(RED)Cleaning all...$(RESET)"
	@$(RM) $(NAME)
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