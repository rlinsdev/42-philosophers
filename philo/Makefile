# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 08:04:25 by rlins             #+#    #+#              #
#    Updated: 2023/02/07 15:59:46 by rlins            ###   ########.fr        #
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
CC = gcc -lpthread

# Compilation flags
# CFLAGS = -g -fsanitize=thread # Warning datarace. Don't work with valgrind
# CFLAGS = -g -Wall -Werror -Wextra -D PRETTY=1 #PRETTY debug info
CFLAGS = -g -Wall -Werror -Wextra #Normal Execution

#Check Leak memory
LEAK = valgrind --leak-check=full --show-leak-kinds=all \
	--trace-children=yes --track-origins=yes -s

# Thread error detections:
HEL_GRIND = valgrind --tool=helgrind

RM		= rm -rf

SRCS 	= main.c ft_ato_long.c validation.c init.c error.c time.c \
			output.c garbage_collector.c mutex.c \
			routine_finish.c routine_dinning.c

OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)

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

run: $(NAME)
#	@./$(NAME) 1 800 200 200
#	@./$(NAME) 5 800 200 200
#	@./$(NAME) 5 800 200 200 7
#	@./$(NAME) 5 800 200 200 7 | grep 'is eating'
#	@./$(NAME) 4 410 200 200
#	@./$(NAME) 4 310 200 100
#	@./$(NAME) 2 310 200 100

#	@./$(NAME) 3 8100 2000 2000 2
#	@./$(NAME) 2 4100 2000 2000 2
#	@./$(NAME) 4 410 200 200 5
#	@./$(NAME) 4 410 200 200
#	@./$(NAME) 2 800 200 200 2
	@./$(NAME) 2 60 60 60 

valgrind:
	$(LEAK) ./$(NAME) 1 800 200 200

helgrind:
	$(HEL_GRIND) ./$(NAME) 2 8100 2000 2000 1
#	$(HEL_GRIND) ./$(NAME) 1 800 200 200

.PHONY: all run re clean fclean
