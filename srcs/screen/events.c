/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:54:28 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/18 21:53:02 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manager.h"
#include "structs.h"

void	key_event(int key, void *params)
{
	t_data	*data;

	data = (t_data *)params;
	if (key == CUB_ESCAPE)
		mlx_loop_end(data->mlx);
	data->keys[key] = 1;
	if (key == 9 && !data->flash_light)
	{
		data->flash_light = 1;
		return ;
	}
	if (key == 9 && data->flash_light)
		data->flash_light = 0;
}

void	key_release_event(int key, void *params)
{
	t_data	*data;

	data = (t_data *)params;
	data->keys[key] = 0;
}

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

void	event_manager(t_data *data)
{
	mlx_on_event(data->mlx, data->win.win,
		MLX_WINDOW_EVENT, window_event, data->mlx);
	mlx_on_event(data->mlx, data->win.win, MLX_KEYDOWN, key_event, data);
	mlx_on_event(data->mlx, data->win.win, MLX_KEYUP, key_release_event, data);
}
