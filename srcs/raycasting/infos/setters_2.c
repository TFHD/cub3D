/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:58:53 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/08 03:33:54 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <stdlib.h>
#include "parsing.h"

void	set_directions(t_data *data, double fov)
{
	if (data->direction == 'N')
	{
		data->ray.dir_x = -1;
		data->ray.plane_y = fov;
	}
	if (data->direction == 'S')
	{
		data->ray.dir_x = 1;
		data->ray.plane_y = -fov;
	}
	if (data->direction == 'W')
	{
		data->ray.dir_y = -1;
		data->ray.plane_x = -fov;
	}
	if (data->direction == 'E')
	{
		data->ray.dir_y = 1;
		data->ray.plane_x = fov;
	}
}

void	load_image(t_data *data, t_texture *tex)
{
	tex->img = mlx_new_image_from_file(data->mlx,
			tex->texture_path, &tex->width, &tex->height);
	tex->colors = malloc(sizeof(mlx_color)
			* (tex->width + 1) * (tex->height + 1));
	mlx_get_image_region(data->mlx, tex->img, 0, 0,
		tex->width, tex->height, tex->colors);
}

void	set_infos(t_data *data, t_infos infos)
{
	data->win.info.title = "cub3D";
	data->win.info.width = infos.width;
	data->win.info.height = infos.height;
	set_directions(data, infos.fov);
	data->ray.speed_mov = infos.speed_mov;
	data->ray.speed_rot = infos.speed_rot;
	data->win.win = mlx_new_window(data->mlx, &data->win.info);
	mlx_set_fps_goal(data->mlx, infos.fps);
	find_player_location(&data->ray.pos_y, &data->ray.pos_x, data);
	data->ray.pos_y += 0.5;
	data->ray.pos_x += 0.5;
	data->ray.width = infos.width;
	data->ray.height = infos.height;
	data->textures = malloc(sizeof(mlx_color) * infos.width * infos.height);
	load_image(data, &data->no);
	load_image(data, &data->so);
	load_image(data, &data->we);
	load_image(data, &data->ea);
}

void	set_width(t_infos *infos, int width)
{
	infos->width = width;
}
