/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:08:42 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/25 19:17:11 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycasting.h>

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
	if (ray->side)
	{
		if (ray->raydir_y > 0)
			return (&data->we);
		return (&data->ea);
	}
	if (ray->raydir_x > 0)
		return (&data->so);
	return (&data->no);
}

int has_moove(t_data *data)
{
	int i;

	i = 0;
	while (i < 256)
		if (data->keys[i++])
			return (1);
	return (0);
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
	mlx_clear_window(data->mlx, data->win.win, (mlx_color){.rgba = 0});
	if (has_moove(data))
	{
		render_sky_floor(data, ray);
		while (x < ray->width)
		{
			init_value_raycasting(ray, x);
			dda(ray);
			send_ray(data, ray);
			trace_line(ray);
			update_textures(data, ray, x);
			x++;
		}
		create_minimap(data, (t_vec){.x = 0, .y = ray->width - 350}, (t_vec){.x = 340, .y = 340});
	}
	mlx_pixel_put_region(data->mlx, data->win.win, 0, 0, ray->width, ray->height, data->textures);
	mlx_put_image_to_window(data->mlx, data->win.win, data->test.img, ray->width - data->test.width, ray->height - data->test.height);
	print_fps(data, 0);
	data->keys[255] = 0;
	print_coords(data);
}
