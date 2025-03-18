/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:08:42 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/18 22:07:12 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include <sys/time.h>

double	get_fps(void)
{
	double					fps;
	static struct timeval	val_cur;
	static struct timeval	val_last;

	if (val_last.tv_sec == 0 && val_last.tv_usec == 0)
		gettimeofday(&val_last, 0);
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
	int	i;

	i = ray->width * ray->height * 0.5 + ray->pitch * ray->width;
	if (i < 0)
		i = 0;
	ft_memset(data->textures, 0, sizeof(mlx_color) * ray->width * ray->height);
	while (i < ray->width * ray->height)
		data->textures[i++] = data->floor_colors;
	mlx_clear_window(data->mlx, data->win.win,
		data->sky_colors);
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
	create_minimap(data,
		(t_vec){.x = 10, .y = 10},
		(t_vec){.x = 300, .y = 300});
	mlx_pixel_put_region(data->mlx, data->win.win, 0,
		0, ray->width, ray->height, data->textures);
	mlx_put_image_to_window(data->mlx, data->win.win, data->test.img, ray->width
		- data->test.width, ray->height - data->test.height);
	print_fps(data, 0);
	print_coords(data);
}
