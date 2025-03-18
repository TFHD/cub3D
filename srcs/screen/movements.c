/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:42:58 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/18 22:13:07 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manager.h"
#include <math.h>

void	move_forward_back(t_data *data, t_ray *ray)
{
	if (data->keys[CUB_DOWN])
	{
		if (ray->pos_x < 0 || ray->pos_y < 0
			|| data->map[(int)(ray->pos_x - ray->dir_x * ray->movespeed)][(int)ray->pos_y] != '1' || data->keys[CUB_NO_CLIP])
			ray->pos_x -= ray->dir_x * ray->movespeed;
		if (ray->pos_x < 0 || ray->pos_y < 0
			|| data->map[(int)ray->pos_x][(int)(ray->pos_y - ray->dir_y * ray->movespeed)] != '1' || data->keys[CUB_NO_CLIP])
			ray->pos_y -= ray->dir_y * ray->movespeed;
	}
	if (data->keys[CUB_UP])
	{
		if (ray->pos_x < 0 || ray->pos_y < 0
			|| data->map[(int)(ray->pos_x + ray->dir_x * ray->movespeed)][(int)ray->pos_y] != '1' || data->keys[CUB_NO_CLIP])
			ray->pos_x += ray->dir_x * ray->movespeed;
		if (ray->pos_x < 0 || ray->pos_y < 0
			|| data->map[(int)ray->pos_x][(int)(ray->pos_y + ray->dir_y * ray->movespeed)] != '1' || data->keys[CUB_NO_CLIP])
			ray->pos_y += ray->dir_y * ray->movespeed;
	}
}

void	move_left_right(t_data *data, t_ray *ray)
{
	if (data->keys[CUB_LEFT])
	{
		if (ray->pos_x < 0 || ray->pos_y < 0
			|| data->map[(int)(ray->pos_x - ray->dir_y * ray->movespeed)][(int)ray->pos_y] != '1' || data->keys[CUB_NO_CLIP])
			ray->pos_x -= ray->dir_y * ray->movespeed;
		if (ray->pos_x < 0 || ray->pos_y < 0
			|| data->map[(int)ray->pos_x][(int)(ray->pos_y + ray->dir_x * ray->movespeed)] != '1' || data->keys[CUB_NO_CLIP])
		ray->pos_y += ray->dir_x * ray->movespeed;
	}
	if (data->keys[CUB_RIGHT])
	{
		if (ray->pos_x < 0 || ray->pos_y < 0
			|| data->map[(int)(ray->pos_x + ray->dir_y * ray->movespeed)][(int)ray->pos_y] != '1' || data->keys[CUB_NO_CLIP])
			ray->pos_x += ray->dir_y * ray->movespeed;
		if (ray->pos_x < 0 || ray->pos_y < 0
			|| data->map[(int)ray->pos_x][(int)(ray->pos_y - ray->dir_x * ray->movespeed)] != '1' || data->keys[CUB_NO_CLIP])
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
