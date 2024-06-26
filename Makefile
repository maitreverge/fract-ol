# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flverge <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 09:04:59 by flverge           #+#    #+#              #
#    Updated: 2024/06/26 10:04:36 by flverge          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = fractol

# Compiler options
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3

# libft
LIBFT_NAME = libmaster.a
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

# MiniLibX
MLX_NAME = libmlx.a  
MLX_PATH = minilibx-linux/
MLX = $(MLX_PATH)$(MLX_NAME)

# Fractols files
SRC_DIR := src
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := ${SRC:.c=.o}

# Includes
INC =	-I ./includes/\
		-I ./minilibx-linux/

# Colors
RESET = \033[0m
BOLD = \033[1m
RED = \033[91m
GREEN = \033[92m
YELLOW = \033[33m
ORANGE = \033[93m
BLUE = \033[94m


all: $(MLX) $(LIBFT) $(NAME)

# remettre flags
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -sC $(LIBFT_PATH)
	@echo "\n"
	@echo "$(BOLD)$(BLUE)-----------------------$(RESET)"
	@echo "\n"	

$(MLX):
	@echo "$(BOLD)$(RED)🛠️      Compiling MiniLibX      🛠️$(RESET)"
	@echo "\n"	
	@make all -sC $(MLX_PATH)
	@echo "\n"	
	@echo "$(BOLD)$(GREEN)😎     MiniLibX Compiled    😎$(RESET)"
	@echo "\n"
	@echo "$(BOLD)$(BLUE)-----------------------$(RESET)"
	@echo "\n"	

# remettre flags
$(NAME): $(OBJ)
	@echo "$(BOLD)$(RED)🛠️      Compiling Fractol    🛠️$(RESET)"
	@echo "\n"
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm -lz -o $(NAME) -g
	@echo "$(BOLD)$(GREEN)✅✅      Fractol fully compiled, ready to use       ✅✅$(RESET)"
	@echo "\n"

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJ)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o fractol's files   🌀$(RESET)"
	@make clean -sC $(MLX_PATH)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o MiniLibX's files  🌀$(RESET)"


fclean: clean
	@make fclean -sC libft/
	@rm -f $(NAME)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned fractol exec       🌀$(RESET)"

bonus: all

re: fclean all
