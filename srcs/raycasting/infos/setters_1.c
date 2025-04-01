/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:54:05 by sabartho          #+#    #+#             */
/*   Updated: 2025/04/01 19:51:45 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"
#include <fcntl.h>

void	set_directions(t_data *data, double fov)
{
	if (data->direction == 'N')
	{
		data->ray.dir.x = -1;
		data->ray.plane.y = fov;
	}
	if (data->direction == 'S')
	{
		data->ray.dir.x = 1;
		data->ray.plane.y = -fov;
	}
	if (data->direction == 'W')
	{
		data->ray.dir.y = -1;
		data->ray.plane.x = -fov;
	}
	if (data->direction == 'E')
	{
		data->ray.dir.y = 1;
		data->ray.plane.x = fov;
	}
}

void	set_utils(t_utils *utils, t_infos infos)
{
	utils->radius_light = RADIUS_LIGHT;
	utils->darkness = DARKNESS;
	utils->circle_x = infos.width * 0.5;
	utils->circle_y = infos.height * 0.5;
	utils->pitch_max = PITCH_MAX;
	utils->pitch_min = PITCH_MIN;
	utils->mid_height = infos.height * 0.5;
	utils->mid_width = infos.width * 0.5;
	utils->flash_light = 0;
}

int	set_sprite(t_data *data, t_vecf pos, char *file, char *file2)
{
	static int	i;

	data->sprites[i].pos = pos;
	data->sprites[i].tex[0].texture_path = file;
	data->sprites[i].tex[1].texture_path = file2;
	load_image(data, &data->sprites[i].tex[0]);
	load_image(data, &data->sprites[i].tex[1]);
	if (!data->sprites[i].tex[0].img || !data->sprites[i].tex[1].img)
	{
		data->error = 2;
		return (1);
	}
	i++;
	return (0);
}

int	set_win_player_textures_infos(t_data *data, t_infos infos)
{
	data->win.info.title = "cub3D";
	data->win.info.width = infos.width;
	data->win.info.height = infos.height;
	set_directions(data, infos.fov);
	data->ray.speed_mov = infos.speed_mov;
	data->ray.speed_rot = infos.speed_rot;
	data->win.win = mlx_new_window(data->mlx, &data->win.info);
	mlx_set_fps_goal(data->mlx, infos.fps);
	find_player_location(&data->ray.pos.y, &data->ray.pos.x, data);
	mlx_mouse_hide(data->mlx);
	data->ray.pos.y += 0.5;
	data->ray.pos.x += 0.5;
	data->ray.width = infos.width;
	data->ray.height = infos.height;
	data->ray.zbuffer = malloc(sizeof(double) * infos.width);
	data->textures = malloc(sizeof(mlx_color) * infos.width * infos.height);
	if (!data->textures || !data->ray.zbuffer)
		return (1);
	data->test.texture_path = ft_strdup("./textures/lamptorch.png");
	data->sky_colors.rgba = data->sky_color[0] << 24 | data->sky_color[1] << 16
		| data->sky_color[2] << 8 | 0xFF;
	data->floor_colors.rgba = data->floor_color[0] << 24
		| data->floor_color[1] << 16 | data->floor_color[2] << 8 | 0xFF;
	data->imgs_nb = 0;
	return (0);
}

int	set_sprites(t_data *data)
{
	char	*tex;
	char	*tex2;
	int		i;

	i = -1;
	data->sprites = malloc(sizeof(t_sprite) * NB_SPRITES);
	if (!data->sprites)
		return (1);
	tex = ft_strdup("./textures/lebron.jpg");
	tex2 = ft_strdup("./textures/lebron1.png");
	set_sprite(data, (t_vecf){2, 21}, tex, tex2);
	set_sprite(data, (t_vecf){4.5, 21}, tex, tex2);
	free(tex);
	free(tex2);
	while (++i < NB_SPRITES)
		data->sprite_ord[i] = i;
	return (0);
}
