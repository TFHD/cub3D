/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:08:42 by sabartho          #+#    #+#             */
/*   Updated: 2025/04/01 18:20:55 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D_bonus.h"
#include <pthread.h>

void	clear_window(t_data *data, t_ray *ray)
{
	int				i;

	i = 0;
	if (PRINT_SKY_TEXTURES)
	{
		mlx_clear_window(data->mlx, data->win.win, (mlx_color){.rgba = 0});
		ft_memset(data->textures, 0, sizeof(mlx_color)
			* ray->width * ray->height);
		return ;
	}
	i = 0;
	mlx_clear_window(data->mlx, data->win.win, data->sky_colors);
	i = 0;
	ft_memset(data->textures, 0, sizeof(mlx_color) * ray->width * ray->height);
	while (i < (ray->width * ray->height / 2) + ray->pitch * ray->width
		&& i < ray->width * ray->height)
		data->textures[i++] = data->sky_colors;
	i = (ray->width * ray->height / 2) + ray->pitch * ray->width;
	if (i < 0)
		i = 0;
	while (i < ray->width * ray->height)
		data->textures[i++] = data->floor_colors;
}

void	*raycast_thread(void *param)
{
	t_thread_data	*thread_data;
	t_data			data;
	t_ray			ray;
	int				x;

	thread_data = (t_thread_data *)param;
	data = thread_data->data;
	ray = thread_data->ray;
	x = thread_data->start_x;
	while (x < thread_data->end_x)
	{
		init_value_raycasting(&ray, x);
		dda(&ray);
		send_ray(&data, &ray);
		trace_line(&data, &ray);
		update_textures(&data, &ray, x);
		ray.zbuffer[x] = ray.perpwalldist;
		x++;
	}
	return (NULL);
}

void	threading_raycast(t_data *data, t_ray *ray)
{
	pthread_t		threads[NUM_THREADS];
	t_thread_data	thread_data[NUM_THREADS];
	int				step;
	int				i;

	step = ray->width / NUM_THREADS;
	i = -1;
	while (++i < NUM_THREADS)
	{
		thread_data[i].data = *data;
		thread_data[i].ray = *ray;
		thread_data[i].start_x = i * step;
		thread_data[i].end_x = (i + 1) * step;
		if (i == NUM_THREADS - 1)
			thread_data[i].end_x = ray->width;
		pthread_create(&threads[i], NULL, raycast_thread, &thread_data[i]);
		usleep(1);
	}
	i = -1;
	while (++i < NUM_THREADS)
		pthread_join(threads[i], NULL);
}

void	bot(t_data *data, t_ray *ray, t_sprite *sprite)
{
	if (ray->pos.x > sprite->pos.x && sprite->pos.x + SPEEDBOT < ray->pos.x
		&& !is_wall(sprite->pos.x + SPEEDBOT, sprite->pos.y, data->map))
		sprite->pos.x += SPEEDBOT;
	else if (ray->pos.x < sprite->pos.x && sprite->pos.x - SPEEDBOT > ray->pos.x
		&& !is_wall(sprite->pos.x - SPEEDBOT, sprite->pos.y, data->map))
		sprite->pos.x -= SPEEDBOT;
	if (ray->pos.y > sprite->pos.y && sprite->pos.y + SPEEDBOT < ray->pos.y
		&& !is_wall(sprite->pos.x, sprite->pos.y + SPEEDBOT, data->map))
		sprite->pos.y += SPEEDBOT;
	else if (ray->pos.y < sprite->pos.y && sprite->pos.y - SPEEDBOT > ray->pos.y
		&& !is_wall(sprite->pos.x, sprite->pos.y - SPEEDBOT, data->map))
		sprite->pos.y -= SPEEDBOT ;
	if (fabs(sprite->pos.x - ray->pos.x) < 0.5
		&& fabs(sprite->pos.y - ray->pos.y) < 0.5)
		mlx_loop_end(data->mlx);
}

void	raycaster(void *params)
{
	t_data			*data;
	t_ray			*ray;

	data = (t_data *)params;
	ray = &data->ray;
	clear_window(data, ray);
	if (PRINT_SKY_TEXTURES)
		threading_raycast_sky_floor(data, ray);
	if (has_moove(data))
		threading_raycast(data, ray);
	raycasting_sprites(data, ray);
	create_minimap(data, (t_vec){.x = 15, .y = ray->width - 360},
		(t_vec){.x = 200, .y = 340});
	mlx_pixel_put_region(data->mlx, data->win.win, 0, 0, ray->width,
		ray->height, data->textures);
	mlx_put_image_to_window(data->mlx, data->win.win, data->test.img, ray->width
		- data->test.width, ray->height - data->test.height);
	print_fps(data, 0);
	data->keys[255] = 0;
	print_coords(data);
	if (BOT && NB_SPRITES > 0)
		bot(data, ray, &data->sprites[0]);
}
