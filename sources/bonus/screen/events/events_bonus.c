/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:54:28 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/31 22:49:14 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D_bonus.h"

void	window_event(int event, void *mlx)
{
	if (event == 0)
		mlx_loop_end(mlx);
}

void	update_pos(void *params)
{
	t_data	*data;
	t_ray	*ray;
	double	fps;

	fps = get_fps();
	data = (t_data *)params;
	ray = &data->ray;
	ray->movespeed = fps * ray->speed_mov;
	ray->rotspeed = fps * ray->speed_rot;
	move_forward_back(data, ray);
	move_left_right(data, ray);
	turn_around(data, ray, &(t_vec){0}, (t_vecf){0});
	speed_handler(data, ray);
}

void	open_door(t_data *data, t_ray *ray)
{
	init_value_raycasting(ray, ray->width * 0.5);
	dda(ray);
	send_ray(data, ray);
	if (in_map(ray->map.x, ray->map.y, data->map))
	{
		data->keys[255] = 1;
		if (ray->side == 0)
			ray->perpwalldist = (ray->sidedist.x - ray->deltadist.x);
		else
			ray->perpwalldist = (ray->sidedist.y - ray->deltadist.y);
		if (ray->touch_door_open)
			ray->perpwalldist = (ray->door_open.x - ray->pos.x)
				* (ray->door_open.x - ray->pos.x)
				+ (ray->door_open.y - ray->pos.y)
				* (ray->door_open.y - ray->pos.y);
		if (ray->perpwalldist < 5 && ray->touch_door_open == 1)
			data->map[ray->door_open.x][ray->door_open.y] = '2';
		else if (ray->perpwalldist < 2
			&& data->map[ray->map.x][ray->map.y] == '2')
			data->map[ray->map.x][ray->map.y] = 'O';
		ray->touch_door_open = 0;
	}
}

void	mouse_event(int key, void *params)
{
	t_data	*data;
	t_ray	*ray;

	data = (t_data *)params;
	ray = &data->ray;
	if (key == 1)
		open_door(data, ray);
}

void	event_manager(t_data *data)
{
	mlx_on_event(data->mlx, data->win.win,
		MLX_WINDOW_EVENT, window_event, data->mlx);
	mlx_on_event(data->mlx, data->win.win, MLX_KEYDOWN, key_event, data);
	mlx_on_event(data->mlx, data->win.win, MLX_KEYUP, key_release_event, data);
	mlx_on_event(data->mlx, data->win.win, MLX_MOUSEDOWN, mouse_event, data);
}
