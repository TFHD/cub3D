NAME		:= 	cub3D

SRCS		:= 	main.c \
				parsing/file/parsing.c \
				parsing/file/parsing_color_textures.c \
				parsing/file/parsing_color_textures_utils.c \
				parsing/file/parsing_utils.c \
				parsing/file/parsing_utils2.c \
				parsing/floodfill/floodfill.c \
				parsing/floodfill/parse_init.c \
				parsing/floodfill/floodfill_utils.c \
				screen/mlx_manager.c \
				screen/movements.c \
				screen/events.c \
				screen/utils/print_infos.c \
				raycasting/infos/setters_1.c \
				raycasting/infos/setters_2.c \
				raycasting/raycasting.c \
				raycasting/raycasting_maths.c

DIR			:=	srcs/

OBJS		:=	$(patsubst %.c, $(DIR)%.o, $(SRCS))

CC			:= cc

FLAGS 		:= -Wall -Werror -Wextra -I ./includes -g

LIB			:= libs/MacroLibX/libmlx.so libs/libft/libft.a

TPUT 					= tput -T xterm-256color
_RESET 					:= $(shell $(TPUT) sgr0)
_BOLD 					:= $(shell $(TPUT) bold)
_ITALIC 				:= $(shell $(TPUT) sitm)
_UNDER 					:= $(shell $(TPUT) smul)
_GREEN 					:= $(shell $(TPUT) setaf 2)
_YELLOW 				:= $(shell $(TPUT) setaf 3)
_RED 					:= $(shell $(TPUT) setaf 1)
_GRAY 					:= $(shell $(TPUT) setaf 8)
_PURPLE 				:= $(shell $(TPUT) setaf 5)

OBJS_TOTAL	= $(words $(OBJS))
N_OBJS		:= $(shell find $(DIR) -type f -name $(OBJS) 2>/dev/null | wc -l)
OBJS_TOTAL	:= $(shell echo $$(( $(OBJS_TOTAL) - $(N_OBJS) )))
CURR_OBJ	= 0

all: ${NAME}

${NAME}: ${OBJS} ${LIB}
	@${CC} ${FLAGS} -o ${NAME} ${OBJS} ${LIB} -lSDL2 -lm

${LIB}:
	@make --no-print-directory -C libs/MacroLibX -j16
	@printf "$(_BOLD)$(_UNDER)$(_YELLOW)                            LIBFT                           $(_RESET)\n"
	@make --no-print-directory -C libs/libft
                                                                                                  
${DIR}%.o: ${DIR}%.c
	@${CC} ${FLAGS} -o $@ -c $<
	@$(eval CURR_OBJ=$(shell echo $$(( $(CURR_OBJ) + 1 ))))
	@$(eval PERCENT=$(shell echo $$(( $(CURR_OBJ) * 100 / $(OBJS_TOTAL) ))))
	@printf "$(_GREEN)($(_BOLD)%3s%%$(_RESET)$(_GREEN)) $(_RESET)Compiling $(_BOLD)$(_PURPLE)$<$(_RESET)\n" "$(PERCENT)"
	
clean:
	@rm -rf ${OBJS}
	@make --no-print-directory -C libs/libft clean
	@make --no-print-directory -C libs/MacroLibX clean
	@printf "\n$(_BOLD)All objects are $(_GREEN)cleaned $(_RESET)! 🎉\n\n"

fclean: clean
	@rm -f ${NAME}
	@make --no-print-directory -C libs/libft fclean
	@make --no-print-directory -C libs/MacroLibX fclean
	@printf "Cleaned $(_BOLD)$(NAME)$(_RESET) !\n\n"

re: fclean all

.PHONY: clean fclean re all
