/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:42:58 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/08 04:44:27 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manager.h"
#include "structs.h"
#include <math.h>

void	move_forward_back(t_data *data, t_ray *ray)
{
	if (data->keys[CUB_DOWN])
	{
		ray->pos_x -= ray->dir_x * ray->movespeed;
		ray->pos_y -= ray->dir_y * ray->movespeed;
	}
	if (data->keys[CUB_UP])
	{
		ray->pos_x += ray->dir_x * ray->movespeed;
		ray->pos_y += ray->dir_y * ray->movespeed;
	}
}

void	move_left_right(t_data *data, t_ray *ray)
{
	if (data->keys[CUB_LEFT])
	{
		ray->pos_x = ray->pos_x - ray->dir_y * ray->movespeed;
		ray->pos_y = ray->pos_y + ray->dir_x * ray->movespeed;
	}
	if (data->keys[CUB_RIGHT])
	{
		ray->pos_x = ray->pos_x + ray->dir_y * ray->movespeed;
		ray->pos_y = ray->pos_y - ray->dir_x * ray->movespeed;
	}
}

void	turn_left(t_data *data, t_ray *ray)
{
	if (data->keys[CUB_ARROW_LEFT])
	{
		ray->olddir_x = ray->dir_x;
		ray->dir_x = ray->dir_x * cos(ray->rotspeed)
			- ray->dir_y * sin(ray->rotspeed);
		ray->dir_y = ray->olddir_x * sin(ray->rotspeed)
			+ ray->dir_y * cos(ray->rotspeed);
		ray->oldplane_x = ray->plane_x;
		ray->plane_x = ray->plane_x * cos(ray->rotspeed)
			- ray->plane_y * sin(ray->rotspeed);
		ray->plane_y = ray->oldplane_x * sin(ray->rotspeed)
			+ ray->plane_y * cos(ray->rotspeed);
	}
}

void	turn_right(t_data *data, t_ray *ray)
{
	if (data->keys[CUB_ARROW_RIGHT])
	{
		ray->olddir_x = ray->dir_x;
		ray->dir_x = ray->dir_x * cos(-ray->rotspeed)
			- ray->dir_y * sin(-ray->rotspeed);
		ray->dir_y = ray->olddir_x * sin(-ray->rotspeed)
			+ ray->dir_y * cos(-ray->rotspeed);
		ray->oldplane_x = ray->plane_x;
		ray->plane_x = ray->plane_x * cos(-ray->rotspeed)
			- ray->plane_y * sin(-ray->rotspeed);
		ray->plane_y = ray->oldplane_x * sin(-ray->rotspeed)
			+ ray->plane_y * cos(-ray->rotspeed);
	}
}
