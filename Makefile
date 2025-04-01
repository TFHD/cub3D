# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrouves <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 18:27:35 by mrouves           #+#    #+#              #
#    Updated: 2025/03/31 23:13:00 by sabartho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include srcs/sources.mk
include srcs/pretty_compile.mk

NAME 			:= cub3D

DIR_HEADERS		:= includes
DIR_SOURCES		:= srcs
DIR_OBJS		:= .objs
DIR_LIB			:= libs

DIR_MLX			:= $(DIR_LIB)/MacroLibX
MLX_INCLUDES	:= $(DIR_MLX)/includes
MLX				:= $(DIR_MLX)/libmlx.so

DIR_LIBFT		:= $(DIR_LIB)/libft
LIBFT_INCLUDES	:= $(DIR_LIBFT)/headers
LIBFT			:= $(DIR_LIBFT)/libft.a

OBJS			:= $(addprefix $(DIR_OBJS)/, $(SOURCES:%.c=%.o))

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -g
IFLAGS			:= -I $(DIR_HEADERS) -I $(MLX_INCLUDES) -I $(LIBFT_INCLUDES)
DIR_DUP			= mkdir -p $(@D)

all: $(NAME) $(OBJS)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
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
	@printf "Cleaned $(BOLD)$(DIR_OBJS)$(NO_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@printf "Cleaned $(BOLD)$(NAME)/$(NAME_BONUS)$(NO_COLOR)\n"

re: fclean all

.PHONY: clean fclean re all
