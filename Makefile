# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrouves <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 18:27:35 by mrouves           #+#    #+#              #
#    Updated: 2025/04/01 20:56:41 by mrouves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include sources/sources.mk
include sources/pretty_compile.mk

NAME 			:= cub3D
NAME_BONUS		:= cub3D_bonus

DIR_HEADERS		:= includes
DIR_SOURCES		:= sources
DIR_OBJS		:= .objs
DIR_LIB			:= libs

DIR_MLX			:= $(DIR_LIB)/MacroLibX
MLX_INCLUDES	:= $(DIR_MLX)/includes
MLX				:= $(DIR_MLX)/libmlx.so

DIR_LIBFT		:= $(DIR_LIB)/libft
LIBFT_INCLUDES	:= $(DIR_LIBFT)/headers
LIBFT			:= $(DIR_LIBFT)/libft.a

OBJS			:= $(addprefix $(DIR_OBJS)/, $(SOURCES:%.c=%.o))
OBJS_BONUS		:= $(addprefix $(DIR_OBJS)/, $(SOURCES_BONUS:%.c=%.o))

CC				:= clang
CFLAGS			:= -Wall -Wextra -Werror
IFLAGS			:= -I $(DIR_HEADERS) -I $(MLX_INCLUDES) -I $(LIBFT_INCLUDES)
DIR_DUP			= mkdir -p $(@D)

all: $(NAME) $(OBJS)

bonus: $(NAME_BONUS) $(OBJS_BONUS)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	@$(call run_and_test, $(CC) $(CFLAGS) $(IFLAGS) $^ -o $@ -lm -lSDL2)
	@printf "$(BOLD)$@$(NO_COLOR) compiled $(OK_COLOR)successfully$(NO_COLOR)\n"

$(NAME_BONUS): $(OBJS_BONUS) $(MLX) $(LIBFT)
	@$(call run_and_test, $(CC) $(CFLAGS) $(IFLAGS) $^ -o $@ -lm -lSDL2)
	@printf "$(BOLD)$@$(NO_COLOR) compiled $(OK_COLOR)successfully$(NO_COLOR)\n"

$(LIBFT):
	@$(MAKE) -C $(DIR_LIBFT) --no-print-directory -j

$(MLX):
	@$(MAKE) -C $(DIR_MLX) --no-print-directory -j

$(DIR_OBJS)/%.o: $(DIR_SOURCES)/%.c
	@$(DIR_DUP)
	@$(call run_and_test,$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@)

clean:
	@rm -rf $(DIR_OBJS)
	@$(MAKE) -C $(DIR_LIBFT) clean --no-print-directory
	@$(MAKE) -C $(DIR_MLX) clean --no-print-directory
	@printf "Cleaned $(BOLD)$(DIR_OBJS)$(NO_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@$(MAKE) -C $(DIR_LIBFT) fclean --no-print-directory
	@$(MAKE) -C $(DIR_MLX) fclean --no-print-directory
	@printf "Cleaned $(BOLD)$(NAME)/$(NAME_BONUS)$(NO_COLOR)\n"

re: fclean all

.PHONY: clean fclean bonus re all
