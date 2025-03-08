/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:08:42 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/08 05:59:00 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "../../libs/MacroLibX/includes/mlx_extended.h"

double	get_fps(void)
{
	double					fps;
	static struct timeval	val_cur;
	static struct timeval	val_last;

	gettimeofday(&val_cur, 0);
	fps = (val_cur.tv_sec - val_last.tv_sec)
		+ (val_cur.tv_usec - val_last.tv_usec) / 1000000.0;
	val_last = val_cur;
	return (fps);
}

t_texture	*get_texture(t_ray *ray, t_data *data)
{
	if (ray->side == 1)
	{
		if (ray->raydir_y > 0)
			return (&data->we);
		else
			return (&data->ea);
	}
	else
	{
		if (ray->raydir_x > 0)
			return (&data->so);
		else
			return (&data->no);
	}
}

void	clear_window(t_data *data, t_ray *ray)
{
	int				i;
	unsigned int	sky_color;
	unsigned int	floor_color;

	i = 0;
	sky_color = data->sky_color[0] << 24 | data->sky_color[1] << 16
		| data->sky_color[2] << 8 | 0xFF;
	floor_color = data->floor_color[0] << 24 | data->floor_color[1] << 16
		| data->floor_color[2] << 8 | 0xFF;
	while (i < ray->width * ray->height / 2)
	{
		data->textures[i].rgba = sky_color;
		data->textures[i++ + ray->width * ray->height / 2].rgba = floor_color;
	}
	mlx_clear_window(data->mlx, data->win.win,
		(mlx_color){.rgba = 0xFFFFFFFF});
}

void	raycaster(void *params)
{
	t_data	*data;
	t_ray	*ray;
	double	fps;
	int		x;

	data = (t_data *)params;
	ray = &data->ray;
	fps = get_fps();
	ray->movespeed = fps * ray->speed_mov;
	ray->rotspeed = fps * ray->speed_rot;
	x = 0;
	clear_window(data, ray);
	while (x < ray->width)
	{
		init_value_raycasting(ray, x);
		dda(ray);
		send_ray(data, ray);
		trace_line(ray);
		update_textures(data, ray, x);
		x++;
	}
	mlx_pixel_put_region(data->mlx, data->win.win, 0,
		0, ray->width, ray->height, data->textures);
	print_fps(data, 0);
	print_coords(data);
}
