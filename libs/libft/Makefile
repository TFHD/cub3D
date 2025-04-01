# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrouves <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 18:27:35 by mrouves           #+#    #+#              #
#    Updated: 2025/02/27 18:44:22 by mrouves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include sources/sources.mk

NAME 			:= libft.a

DIR_OBJS		:= .objs
DIR_SOURCES		:= sources
DIR_HEADERS		:= headers
OBJS			:= $(addprefix $(DIR_OBJS)/, $(SRCS:%.c=%.o))

CC				:= cc
CACHE_MODE		?= 0
CACHE_DEBUG		?= 0
CFLAGS			:= -Wall -Wextra -Werror -g -D CACHE_MODE=$(CACHE_MODE) -D CACHE_DEBUG=$(CACHE_DEBUG)
IFLAGS			:= -I $(DIR_HEADERS)

GREEN			= \033[0;32m
BOLD			= \033[1m
END				= \033[0m
DIR_DUP			= mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $@ $^
	@printf "$(BOLD)$(NAME)$(END) compiled $(GREEN)successfully$(END)\n"

$(DIR_OBJS)/%.o: $(DIR_SOURCES)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -rf $(DIR_OBJS)
	@printf "Cleaned $(BOLD)$(DIR_OBJS)$(END)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "Cleaned $(BOLD)$(NAME)$(END)\n"

re: fclean all

.PHONY: clean fclean re all
