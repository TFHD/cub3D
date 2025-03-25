/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:42:58 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/25 16:30:51 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manager.h"
#include "parsing.h"
#include <math.h>

int	in_map(int x, int y, char **map)
{
	if (x >= 0 && y >= 0 && x < ft_str_arr_len(map)
		&& y < (int)ft_strlen(map[x]))
		return (1);
	return (0);
}

int	is_wall(int x, int y, char **map)
{
	if (map[x][y] == '1')
		return (1);
	return (0);
}

void	move_forward_back(t_data *data, t_ray *ray)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = ray->dir_x * ray->movespeed;
	new_pos_y = ray->dir_y * ray->movespeed;
	if (data->keys[CUB_DOWN])
	{
		if (!in_map(ray->pos_x - new_pos_x, ray->pos_y, data->map)
			|| !is_wall(ray->pos_x - new_pos_x, ray->pos_y, data->map)
			|| data->keys[CUB_NO_CLIP])
			ray->pos_x -= ray->dir_x * ray->movespeed;
		if (!in_map(ray->pos_x, ray->pos_y - new_pos_y, data->map)
			|| !is_wall(ray->pos_x, ray->pos_y - new_pos_y, data->map)
			|| data->keys[CUB_NO_CLIP])
			ray->pos_y -= ray->dir_y * ray->movespeed;
	}
	if (data->keys[CUB_UP])
	{
		if (!in_map(ray->pos_x + new_pos_x, ray->pos_y, data->map)
			|| !is_wall(ray->pos_x + new_pos_x, ray->pos_y, data->map)
			|| data->keys[CUB_NO_CLIP])
			ray->pos_x += ray->dir_x * ray->movespeed;
		if (!in_map(ray->pos_x, ray->pos_y + new_pos_y, data->map)
			|| !is_wall(ray->pos_x, ray->pos_y + new_pos_y, data->map)
			|| data->keys[CUB_NO_CLIP])
			ray->pos_y += ray->dir_y * ray->movespeed;
	}
}

void	move_left_right(t_data *data, t_ray *ray)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = ray->dir_x * ray->movespeed;
	new_pos_y = ray->dir_y * ray->movespeed;
	if (data->keys[CUB_LEFT])
	{
		if (!in_map(ray->pos_x - new_pos_y, ray->pos_y, data->map)
			|| !is_wall(ray->pos_x - new_pos_y, ray->pos_y, data->map)
			|| data->keys[CUB_NO_CLIP])
			ray->pos_x -= ray->dir_y * ray->movespeed;
		if (!in_map(ray->pos_x, ray->pos_y + new_pos_x, data->map)
			|| !is_wall(ray->pos_x, ray->pos_y + new_pos_x, data->map)
			|| data->keys[CUB_NO_CLIP])
			ray->pos_y += ray->dir_x * ray->movespeed;
	}
	if (data->keys[CUB_RIGHT])
	{
		if (!in_map(ray->pos_x + new_pos_y, ray->pos_y, data->map)
			|| !is_wall(ray->pos_x + new_pos_y, ray->pos_y, data->map)
			|| data->keys[CUB_NO_CLIP])
			ray->pos_x += ray->dir_y * ray->movespeed;
		if (!in_map(ray->pos_x, ray->pos_y - new_pos_x, data->map)
			|| !is_wall(ray->pos_x, ray->pos_y - new_pos_x, data->map)
			|| data->keys[CUB_NO_CLIP])
			ray->pos_y -= ray->dir_x * ray->movespeed;
	}
}

void	turn_around(t_data *data, t_ray *ray, t_vec *mouse, t_vecf offset)
{
	if (!data->keys[CUB_ARROW_LEFT] && !data->keys[CUB_ARROW_RIGHT])
		mlx_mouse_get_pos(data->mlx, &mouse->x, &mouse->y);
	if ((data->keys[CUB_ARROW_LEFT] && !mouse->x)
		|| (mouse->x < ray->width * 0.5 && mouse->x)
		|| (data->keys[CUB_ARROW_RIGHT] && !mouse->x)
		|| (mouse->x > ray->width * 0.5 && mouse->x))
	{
		offset.x = -ray->rotspeed * (mouse->x == 0) + -ray->rotspeed
			* (mouse->x - (ray->width * 1.0 / 2)) * (mouse->x != 0);
		offset.y = -ray->rotspeed * (mouse->x == 0) + -ray->rotspeed
			* (mouse->x - (ray->width * 1.0 / 2)) * (mouse->x != 0);
		if (data->keys[CUB_ARROW_LEFT])
			offset.x = -offset.x;
		if (data->keys[CUB_ARROW_LEFT])
			offset.y = -offset.y;
		ray->olddir_x = ray->dir_x;
		ray->dir_x = ray->dir_x * cos(offset.x) - ray->dir_y * sin(offset.y);
		ray->dir_y = ray->olddir_x * sin(offset.x) + ray->dir_y * cos(offset.y);
		ray->oldplane_x = ray->plane_x;
		ray->plane_x = ray->plane_x * cos(offset.x)
			- ray->plane_y * sin(offset.y);
		ray->plane_y = ray->oldplane_x * sin(offset.x)
			+ ray->plane_y * cos(offset.y);
	}
	if ((data->keys[CUB_ARROW_DOWN]
			|| mouse->y - 1 > ray->height * 0.5) && mouse->y)
		if (ray->pitch > data->utils.pitch_min)
			ray->pitch += -(5 + mouse->y * 0.05);
	if ((data->keys[CUB_ARROW_UP]
			|| mouse->y + 1 < ray->height * 0.5) && mouse->y)
		if (ray->pitch < data->utils.pitch_max)
			ray->pitch += 5 + mouse->y * 0.05;
	mlx_mouse_move(data->mlx, data->win.win, ray->width * 0.5, ray->height / 2);
}

void	speed_handler(t_data *data, t_ray *ray)
{
	if (data->keys[CUB_RUN])
		ray->speed_mov = data->infos.speed_mov * 2.5;
	else
		ray->speed_mov = data->infos.speed_mov;
}
