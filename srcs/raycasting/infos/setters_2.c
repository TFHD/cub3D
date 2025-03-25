/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:58:53 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/25 13:02:57 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	realloc_imgs(t_data *data, const int i)
{
	mlx_image	**imgs;
	int			tmp;

	tmp = i - 1;
	imgs = malloc(sizeof(mlx_image *) * i + 1);
	ft_memset(imgs, 0, sizeof(mlx_image *) * i + 1);
	while (tmp >= 0)
	{
		imgs[tmp] = data->imgs[tmp];
		tmp--;
	}
	tmp++;
	free(data->imgs);
	data->imgs = malloc(sizeof(mlx_image *) * i + 11);
	ft_memset(data->imgs, 0, sizeof(mlx_image *) * i + 11);
	while (tmp < i)
	{
		data->imgs[tmp] = imgs[tmp];
		tmp++;
	}
	free(imgs);
}

void	load_image(t_data *data, t_texture *tex)
{
	static int	i;

	tex->img = mlx_new_image_from_file(data->mlx,
			tex->texture_path, &tex->width, &tex->height);
	tex->colors = malloc(sizeof(mlx_color)
			* (tex->width + 1) * (tex->height + 1));
	mlx_get_image_region(data->mlx, tex->img, 0, 0,
		tex->width, tex->height, tex->colors);
	if (i == 0)
	{
		data->imgs = malloc(sizeof(mlx_image *) * 10 + 1);
		ft_memset(data->imgs, 0, sizeof(mlx_image *) * 10);
		data->imgs[i] = &tex->img;
	}
	else
	{
		if (i % 10 == 0)
			realloc_imgs(data, i);
		else
			data->imgs[i] = &tex->img;
	}
	i++;
}

void	set_utils(t_utils *utils, t_infos infos)
{
	utils->radius_light = 300;
	utils->darkness = 3;
	utils->circle_x = infos.width * 0.5;
	utils->circle_y = infos.height * 0.5;
	utils->pitch_max = 1200;
	utils->pitch_min = -1200;
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
	mlx_mouse_hide(data->mlx);
	data->ray.pos_y += 0.5;
	data->ray.pos_x += 0.5;
	data->ray.width = infos.width;
	data->ray.height = infos.height;
	data->textures = malloc(sizeof(mlx_color) * infos.width * infos.height);
	data->test.texture_path = ft_strdup("./textures/lamptorch.png");
	data->sky_colors.rgba = data->sky_color[0] << 24 | data->sky_color[1] << 16
		| data->sky_color[2] << 8 | 0xFF;
	data->floor_colors.rgba = data->floor_color[0] << 24
		| data->floor_color[1] << 16 | data->floor_color[2] << 8 | 0xFF;
	set_utils(&data->utils, infos);
	load_image(data, &data->test);
	load_image(data, &data->no);
	load_image(data, &data->so);
	load_image(data, &data->we);
	load_image(data, &data->ea);
	data->sky.texture_path = ft_strdup("./textures/planks_jungle.png");
	data->floor.texture_path = ft_strdup("./textures/clay.png");
	load_image(data, &data->sky);
	load_image(data, &data->floor);
}

void	set_width(t_infos *infos, int width)
{
	infos->width = width;
}
