/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_floor_sky.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:50:19 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/31 22:05:55 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"
#include "structs.h"
#include <pthread.h>

void	calc_distance(t_ray *ray, int y, t_vecf *floor_step, t_vecf *floor)
{
	float	pos_z;
	float	row_distance;
	int		p;

	p = ray->height * 0.5 + ray->pitch;
	pos_z = ray->height * 0.5 + ray->pitch;
	if (y > pos_z)
		row_distance = pos_z / (y - p);
	else
		row_distance = pos_z / (p - y);
	floor_step->x = row_distance * ((ray->dir.x + ray->plane.x)
			- (ray->dir.x - ray->plane.x)) / ray->width;
	floor_step->y = row_distance * ((ray->dir.y + ray->plane.y)
			- (ray->dir.y - ray->plane.y)) / ray->width;
	floor->x = ray->pos.x + row_distance * (ray->dir.x - ray->plane.x);
	floor->y = ray->pos.y + row_distance * (ray->dir.y - ray->plane.y);
}

void	get_texture_sky_floor(t_data *data, t_ray *ray, t_vec *tex, t_vec *vec)
{
	mlx_color	color;

	if (vec->y > data->utils.mid_height + ray->pitch)
		color = data->floor.colors[data->floor.width * tex->y + tex->x];
	else
		color = data->sky.colors[data->sky.width * tex->y + tex->x];
	data->textures[vec->y * ray->width + vec->x] = color;
}

void	*render_sky_floor(void *param)
{
	t_thread_data	*tdata;
	t_skyfloor_draw	draw;

	tdata = (t_thread_data *)param;
	draw.index.x = tdata->start_x;
	draw.index.y = -1;
	while (draw.index.x++ < tdata->end_x)
	{
		calc_distance(&tdata->ray, draw.index.x, &draw.floor_step, &draw.floor);
		while (++draw.index.y < tdata->ray.width)
		{
			draw.cell.x = (int)(draw.floor.x);
			draw.cell.y = (int)(draw.floor.y);
			draw.tex.x = (int)(tdata->data.floor.width * (draw.floor.x
						- draw.cell.x)) & (tdata->data.sky.width - 1);
			draw.tex.y = (int)(tdata->data.floor.height * (draw.floor.y
						- draw.cell.y)) & (tdata->data.sky.height - 1);
			draw.floor.x += draw.floor_step.x;
			draw.floor.y += draw.floor_step.y;
			get_texture_sky_floor(&tdata->data, &tdata->ray, &draw.tex,
				&(t_vec){draw.index.y, draw.index.x});
		}
		draw.index.y = -1;
	}
	return (NULL);
}

void	threading_raycast_sky_floor(t_data *data, t_ray *ray)
{
	pthread_t		threads[NUM_THREADS];
	t_thread_data	thread_data[NUM_THREADS];
	int				step;
	int				i;

	step = ray->height / NUM_THREADS;
	i = -1;
	while (++i < NUM_THREADS)
	{
		thread_data[i].data = *data;
		thread_data[i].ray = *ray;
		thread_data[i].start_x = i * step;
		thread_data[i].end_x = (i + 1) * step;
		if (i == NUM_THREADS - 1)
			thread_data[i].end_x = ray->height;
		pthread_create(&threads[i], NULL, render_sky_floor, &thread_data[i]);
		usleep(1);
	}
	i = -1;
	while (++i < NUM_THREADS)
		pthread_join(threads[i], NULL);
}
