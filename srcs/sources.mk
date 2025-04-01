# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrouves <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 16:59:36 by mrouves           #+#    #+#              #
#    Updated: 2025/04/01 17:59:43 by sabartho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES		:= 	main.c \
				parsing/file/parsing.c \
				parsing/file/parsing_color_textures.c \
				parsing/file/parsing_color_textures_utils.c \
				parsing/file/parsing_utils.c \
				parsing/file/parsing_utils2.c \
				parsing/floodfill/floodfill.c \
				parsing/floodfill/parse_init.c \
				parsing/floodfill/floodfill_utils.c \
				screen/mlx_manager.c \
				screen/movements/movements.c \
				screen/movements/movements_directions.c \
				screen/minimap/minimap.c \
				screen/events/events.c \
				screen/events/events_keys.c \
				screen/utils/print_infos.c \
				screen/torch/torch.c \
				raycasting/infos/setters_1.c \
				raycasting/infos/setters_2.c \
				raycasting/raycasting.c \
				raycasting/raycasting_maths.c \
				raycasting/raycasting_floor_sky.c \
				raycasting/raycasting_utils.c \
				raycasting/raycasting_sprites.c \
				raycasting/bonus_utils.c
