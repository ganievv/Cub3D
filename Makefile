# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 11:32:04 by sganiev           #+#    #+#              #
#    Updated: 2024/08/28 16:07:11 by sganiev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= cub3D

INCDIRS		:= -I./include/ -I./mlx42/include

CC			:= gcc
CFLAGS		:= -g -Wall -Wextra -Werror $(INCDIRS)

VPATH		:=  ./src/main

SRC_MAIN	:= main.c
SRC_PARSER	:= 

SRC			:= $(SRC_MAIN) $(SRC_PARSER)

ODIR		:= ./obj
DDIR		:= $(ODIR)/.deps
OBJ			:= $(patsubst %.c,$(ODIR)/%.o,$(SRC))
DEPFILES	:= $(patsubst %.c,$(DDIR)/%.d,$(SRC))
DEPFLAGS	=  -MMD -MP -MF $(DDIR)/$*.d

#****************************************************************************#
#                                   MLX42                                    #
#****************************************************************************#
MLXBUILDDIR	:= ./mlx42/build
MLX42LIB	:= $(MLXBUILDDIR)/libmlx42.a
MLX42FLAGS	:= -lglfw -framework Cocoa -framework OpenGL -framework IOKit

#****************************************************************************#
#                                   COLORS                                   #
#****************************************************************************#
RED			:= \033[0;31m
GREEN		:= \033[0;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[0;34m
RESET		:= \033[0m

#****************************************************************************#
#                                   RULES                                    #
#****************************************************************************#
all: $(NAME)

$(NAME): $(MLX42LIB) $(OBJ)
	@echo "$(BLUE)Linking $@...$(RESET)"
	@$(CC) $(CFLAGS) $(MLX42FLAGS) $^ -o $@
	@echo "$(GREEN)Executable $(NAME) created successfully!$(RESET)"

$(ODIR)/%.o: %.c | $(ODIR) $(DDIR)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c -o $@ $<

$(ODIR) $(DDIR):
	@mkdir -p $(ODIR) $(DDIR)

$(MLX42LIB):
	@echo "$(BLUE)Building MLX42 library...$(RESET)"
	@cmake -S ./mlx42 -B $(MLXBUILDDIR)
	@cmake --build $(MLXBUILDDIR) -j4
	@echo "$(GREEN)MLX42 library created successfully!$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning object and dependency files...$(RESET)"
	@rm -f $(OBJ) $(DEPFILES)
	@echo "$(YELLOW)Cleaned up object files and temporary files.$(RESET)"

fclean: clean
	@echo "$(RED)Cleaning all build files...$(RESET)"
	@rm -rf $(ODIR)
	@rm -f $(NAME)
	@rm -rf $(MLXBUILDDIR)
	@echo "$(RED)Fully cleaned including executable and libraries.$(RESET)"

re: fclean all

-include $(DEPFILES)

.PHONY: all clean fclean re