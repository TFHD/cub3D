CC			=	cc
FLAGS		=	-Wall -Wextra -Werror -g

OBJS_DIR	=	.objs/

SRCS		=	./srcs/maths/ft_abs.c \
				./srcs/maths/ft_llabs.c \
				./srcs/maths/ft_sqrt.c \
				./srcs/memory/alloc/ft_calloc.c \
				./srcs/memory/comparators/ft_memchr.c \
				./srcs/memory/comparators/ft_memcmp.c \
				./srcs/memory/free/ft_free1d.c \
				./srcs/memory/free/ft_free2d.c \
				./srcs/memory/modifiers/ft_bzero.c \
				./srcs/memory/modifiers/ft_memcpy.c \
				./srcs/memory/modifiers/ft_memmove.c \
				./srcs/memory/modifiers/ft_memset.c \
				./srcs/print/printf/integers/handle_dec.c \
				./srcs/print/printf/integers/handle_hex.c \
				./srcs/print/printf/integers/handle_oct.c \
				./srcs/print/printf/integers/handle_ptr.c \
				./srcs/print/printf/parsing/flags_manage.c \
				./srcs/print/printf/parsing/flags_parsing.c \
				./srcs/print/printf/strings/handle_char.c \
				./srcs/print/printf/strings/handle_string.c \
				./srcs/print/printf/ft_printf_bonus.c \
				./srcs/print/ft_putchar_fd.c \
				./srcs/print/ft_putendl_fd.c \
				./srcs/print/ft_putnbr_fd.c \
				./srcs/print/ft_putnchar_fd.c \
				./srcs/print/ft_putnstr_fd.c \
				./srcs/print/ft_putstr_fd.c \
				./srcs/strings/atox/ft_atoi.c \
				./srcs/strings/atox/ft_atoll.c \
				./srcs/strings/atox/ft_atoui.c \
				./srcs/strings/comparators/ft_isalnum.c \
				./srcs/strings/comparators/ft_isalpha.c \
				./srcs/strings/comparators/ft_isascii.c \
				./srcs/strings/comparators/ft_isdigit.c \
				./srcs/strings/comparators/ft_islower.c \
				./srcs/strings/comparators/ft_isprint.c \
				./srcs/strings/comparators/ft_isspace.c \
				./srcs/strings/comparators/ft_isupper.c \
				./srcs/strings/comparators/ft_iswhitespace.c \
				./srcs/strings/comparators/ft_strcmp.c \
				./srcs/strings/comparators/ft_strncmp.c \
				./srcs/strings/create/ft_split.c \
				./srcs/strings/create/ft_strdup.c \
				./srcs/strings/create/ft_strjoin.c \
				./srcs/strings/create/ft_strsjoin.c \
				./srcs/strings/create/ft_strtrim.c \
				./srcs/strings/create/ft_substr.c \
				./srcs/strings/modifiers/ft_strcat.c \
				./srcs/strings/modifiers/ft_strcpy.c \
				./srcs/strings/modifiers/ft_strlcat.c \
				./srcs/strings/modifiers/ft_strlcpy.c \
				./srcs/strings/modifiers/ft_strncat.c \
				./srcs/strings/modifiers/ft_strncpy.c \
				./srcs/strings/modifiers/ft_strrev.c \
				./srcs/strings/modifiers/ft_strtolower.c \
				./srcs/strings/modifiers/ft_strtoupper.c \
				./srcs/strings/modifiers/ft_tolower.c \
				./srcs/strings/modifiers/ft_toupper.c \
				./srcs/strings/queries/ft_strchr.c \
				./srcs/strings/queries/ft_strlen.c \
				./srcs/strings/queries/ft_strnstr.c \
				./srcs/strings/queries/ft_strrchr.c \
				./srcs/strings/queries/ft_strstr.c \
				./srcs/strings/xtoa/buffer/ft_itoa_buffer.c \
				./srcs/strings/xtoa/buffer/ft_lltoa_base_buffer.c \
				./srcs/strings/xtoa/buffer/ft_uitoa_buffer.c \
				./srcs/strings/xtoa/malloc/ft_itoa_malloc.c \
				./srcs/strings/xtoa/malloc/ft_lltoa_base_malloc.c \
				./srcs/strings/xtoa/malloc/ft_uitoa_malloc.c \
				./srcs/strings/modifiers/get_next_line.c

OBJS		=	$(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))
NAME		=	libft.a

TPUT		=	tput -T xterm-256color
_RESET 		=	$(shell $(TPUT) sgr0)
_BOLD 		=	$(shell $(TPUT) bold)
_ITALIC 	=	$(shell $(TPUT) sitm)
_UNDER 		=	$(shell $(TPUT) smul)
_GREEN 		=	$(shell $(TPUT) setaf 2)
_YELLOW 	=	$(shell $(TPUT) setaf 3)
_RED 		=	$(shell $(TPUT) setaf 1)
_GRAY 		=	$(shell $(TPUT) setaf 8)
_PURPLE 	=	$(shell $(TPUT) setaf 5)

OBJS_TOTAL	=	$(words $(OBJS))
N_OBJS		=	$(shell find ./ -type f -name $(OBJS) 2>/dev/null | wc -l)
OBJS_TOTAL	:=	$(shell echo $$(( $(OBJS_TOTAL) - $(N_OBJS) )))
CURR_OBJ	=	0

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(addprefix $(OBJS_DIR), $(dir $(SRCS)))

$(NAME) : $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@printf "\n$(_BOLD)$(NAME)$(_RESET) compiled $(_GREEN)$(_BOLD)successfully$(_RESET)\n"

$(OBJS_DIR)%.o: %.c
	@$(CC) $(FLAGS) -I./includes -o $@ -c $<
	@$(eval CURR_OBJ=$(shell echo $$(( $(CURR_OBJ) + 1 ))))
	@$(eval PERCENT=$(shell echo $$(( $(CURR_OBJ) * 100 / $(OBJS_TOTAL) ))))
	@printf "$(_GREEN)($(_BOLD)%3s%%$(_RESET)$(_GREEN)) $(_RESET)Compiling $(_BOLD)$(_YELLOW)$<$(_RESET)\n" "$(PERCENT)"

clean :
	@rm -rf $(OBJS_DIR)
	@printf "\n$(_BOLD)All objects are $(_GREEN)cleaned $(_RESET)! 🎉\n\n"

fclean : clean
	@rm -f $(NAME)
	@printf "Cleaned $(_BOLD)$(NAME)$(_RESET) !\n"

re : fclean all
.PHONY: all clean fclean re
