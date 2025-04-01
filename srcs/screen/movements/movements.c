/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:42:58 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/31 22:32:50 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	move_forward_back(t_data *data, t_ray *ray)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = ray->dir.x * ray->movespeed;
	new_pos_y = ray->dir.y * ray->movespeed;
	if (data->keys[CUB_DOWN])
		down(data, ray, &(t_vecf){.x = new_pos_x, .y = new_pos_y});
	if (data->keys[CUB_UP])
		up(data, ray, &(t_vecf){.x = new_pos_x, .y = new_pos_y});
}

void	move_left_right(t_data *data, t_ray *ray)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = ray->dir.x * ray->movespeed;
	new_pos_y = ray->dir.y * ray->movespeed;
	if (data->keys[CUB_LEFT])
		left(data, ray, &(t_vecf){.x = new_pos_x, .y = new_pos_y});
	if (data->keys[CUB_RIGHT])
		right(data, ray, &(t_vecf){.x = new_pos_x, .y = new_pos_y});
}

void	turn_mouse(t_data *data, t_ray *ray, t_vec *mouse, t_vecf offset)
{
	if ((data->keys[CUB_ARROW_LEFT] && !mouse->x) || (mouse->x < 0)
		|| (data->keys[CUB_ARROW_RIGHT] && !mouse->x) || (mouse->x > 0))
	{
		offset.x = -ray->rotspeed * (mouse->x == 0) + -ray->rotspeed
			* mouse->x * (mouse->x != 0) * 0.075;
		offset.y = -ray->rotspeed * (mouse->x == 0) + -ray->rotspeed
			* mouse->x * (mouse->x != 0) * 0.075;
		if (data->keys[CUB_ARROW_LEFT])
			offset.x = -offset.x;
		if (data->keys[CUB_ARROW_LEFT])
			offset.y = -offset.y;
		ray->olddir_x = ray->dir.x;
		ray->dir.x = ray->dir.x * cos(offset.x) - ray->dir.y * sin(offset.y);
		ray->dir.y = ray->olddir_x * sin(offset.x) + ray->dir.y * cos(offset.y);
		ray->oldplane_x = ray->plane.x;
		ray->plane.x = ray->plane.x * cos(offset.x)
			- ray->plane.y * sin(offset.y);
		ray->plane.y = ray->oldplane_x * sin(offset.x)
			+ ray->plane.y * cos(offset.y);
	}
}

void	turn_around(t_data *data, t_ray *ray, t_vec *mouse, t_vecf offset)
{
	if (!data->keys[CUB_ARROW_LEFT] && !data->keys[CUB_ARROW_RIGHT])
	{
		mlx_mouse_get_pos(data->mlx, &mouse->x, &mouse->y);
		mouse->x -= data->utils.mid_width;
		mouse->y -= data->utils.mid_height;
		data->keys[255] = 1;
	}
	turn_mouse(data, ray, mouse, offset);
	if (data->keys[CUB_ARROW_DOWN]
		|| (mouse->y - 1 > data->utils.mid_height && mouse->y))
		if (ray->pitch > data->utils.pitch_min)
			ray->pitch -= 5 * (mouse->y == 0) + mouse->y * (mouse->y != 0);
	if (data->keys[CUB_ARROW_UP]
		|| (mouse->y + 1 < data->utils.mid_height && mouse->y))
		if (ray->pitch < data->utils.pitch_max)
			ray->pitch += 5 * (mouse->y == 0) - mouse->y * (mouse->y != 0);
	mlx_mouse_move(data->mlx, data->win.win, data->utils.mid_width,
		data->utils.mid_height);
	if (ray->pitch >= data->utils.pitch_max)
		ray->pitch = data->utils.pitch_max - 1;
	if (ray->pitch <= data->utils.pitch_min)
		ray->pitch = data->utils.pitch_min + 1;
}

void	speed_handler(t_data *data, t_ray *ray)
{
	if (data->keys[CUB_RUN])
		ray->speed_mov = data->infos.speed_mov * 2.5;
	else
		ray->speed_mov = data->infos.speed_mov;
}
