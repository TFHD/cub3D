# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrouves <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 16:59:36 by mrouves           #+#    #+#              #
#    Updated: 2025/04/01 20:47:33 by mrouves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SOURCES		:= manda/main.c \
				manda/parsing/file/parsing.c \
				manda/parsing/file/parsing_color_textures.c \
				manda/parsing/file/parsing_color_textures_utils.c \
				manda/parsing/file/parsing_utils.c \
				manda/parsing/file/parsing_utils2.c \
				manda/parsing/floodfill/floodfill.c \
				manda/parsing/floodfill/parse_init.c \
				manda/parsing/floodfill/floodfill_utils.c \
				manda/screen/mlx_manager.c \
				manda/screen/movements.c \
				manda/screen/events.c \
				manda/screen/utils/print_infos.c \
				manda/raycasting/infos/setters_1.c \
				manda/raycasting/infos/setters_2.c \
				manda/raycasting/raycasting.c \
				manda/raycasting/raycasting_maths.c

SOURCES_BONUS	:= 	bonus/main_bonus.c \
				bonus/parsing/file/parsing_bonus.c \
				bonus/parsing/file/parsing_color_textures_bonus.c \
				bonus/parsing/file/parsing_color_textures_utils_bonus.c \
				bonus/parsing/file/parsing_utils_bonus.c \
				bonus/parsing/file/parsing_utils2_bonus.c \
				bonus/parsing/floodfill/floodfill_bonus.c \
				bonus/parsing/floodfill/parse_init_bonus.c \
				bonus/parsing/floodfill/floodfill_utils_bonus.c \
				bonus/screen/mlx_manager_bonus.c \
				bonus/screen/movements/movements_bonus.c \
				bonus/screen/movements/movements_directions_bonus.c \
				bonus/screen/minimap/minimap_bonus.c \
				bonus/screen/events/events_bonus.c \
				bonus/screen/events/events_keys_bonus.c \
				bonus/screen/utils/print_infos_bonus.c \
				bonus/screen/torch/torch_bonus.c \
				bonus/raycasting/infos/setters_1_bonus.c \
				bonus/raycasting/infos/setters_2_bonus.c \
				bonus/raycasting/raycasting_bonus.c \
				bonus/raycasting/raycasting_maths_bonus.c \
				bonus/raycasting/raycasting_floor_sky_bonus.c \
				bonus/raycasting/raycasting_utils_bonus.c \
				bonus/raycasting/raycasting_sprites_bonus.c \
				bonus/raycasting/bonus_utils_bonus.c
