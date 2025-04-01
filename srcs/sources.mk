# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrouves <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 16:59:36 by mrouves           #+#    #+#              #
#    Updated: 2025/04/01 20:35:28 by mrouves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SOURCES		:= main.c \
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
