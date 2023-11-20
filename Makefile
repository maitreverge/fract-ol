# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flverge <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 09:04:59 by flverge           #+#    #+#              #
#    Updated: 2023/11/20 09:36:38 by flverge          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
SRC_DIR := src
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ = ${SRC:.c=.o}
LIBFT = libft/libmaster.a

# Colors
RESET = \033[0m
BOLD = \033[1m
RED = \033[91m
GREEN = \033[92m
YELLOW = \033[33m
ORANGE = \033[93m


all: minilibx libft compile

minilibx:
	@echo "$(BOLD)$(RED)🛠️      Compiling MiniLibX      🛠️$(RESET)"
	@make -C minilibx_linux/
	@echo "$(BOLD)$(GREEN)😎      MiniLibX Compiled       😎$(RESET)"
	
libft:
	@make -C libft/

compile:
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)
	$(CC) $(CFLAGS) -I $(LIBFT) $(OBJ) 

clean:
	@make clean -C libft/
	@rm -f $(OBJ)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o fractol's files     🌀$(RESET)"
	@make clean -C minilibx_linux/
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o MiniLibX's files     🌀$(RESET)"


fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned fractol.out exec       🌀$(RESET)"

bonus:
	make all

re: fclean all