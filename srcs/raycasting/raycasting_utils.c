/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 10:43:25 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/31 19:42:18 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

double	get_fps(void)
{
	double					fps;
	static struct timeval	val_cur;
	static struct timeval	val_last;

	if (val_last.tv_sec == 0 && val_last.tv_usec == 0)
		gettimeofday(&val_last, 0);
	gettimeofday(&val_cur, 0);
	fps = (val_cur.tv_sec - val_last.tv_sec)
		+ (val_cur.tv_usec - val_last.tv_usec) * 0.000001;
	val_last = val_cur;
	return (fps);
}

t_texture	*get_texture(t_ray *ray, t_data *data)
{
	if (in_map(ray->map.x, ray->map.y, data->map)
		&& data->map[ray->map.x][ray->map.y] == '2')
		return (&data->door);
	if (ray->side)
	{
		if (ray->raydir.y > 0)
			return (&data->we);
		return (&data->ea);
	}
	if (ray->raydir.x > 0)
		return (&data->so);
	return (&data->no);
}

int	has_moove(t_data *data)
{
	int	i;

	i = 0;
	while (i < 256)
		if (data->keys[i++])
			return (1);
	return (0);
}

void	door_handler_ray(char **map, t_ray *ray)
{
	if (map[ray->map.x][ray->map.y] == 'O')
	{
		ray->touch_door_open = 1;
		ray->door_open.x = ray->map.x;
		ray->door_open.y = ray->map.y;
	}
}

void	sort_sprites(t_sprite *sprite, t_vecf *pos, int *arr, t_vec i)
{
	double	dist;
	double	dist_min;
	int		min;
	int		tmp;

	dist_min = (pos->x - sprite[0].pos.x) * (pos->x - sprite[0].pos.x)
		+ (pos->y - sprite[0].pos.y) * (pos->y - sprite[0].pos.y);
	while (++i.x < NB_SPRITES)
	{
		min = i.x;
		i.y = i.x;
		while (++i.y < NB_SPRITES)
		{
			dist = (pos->x - sprite[i.y].pos.x) * (pos->x - sprite[i.y].pos.x)
				+ (pos->y - sprite[i.y].pos.y) * (pos->y - sprite[i.y].pos.y);
			if (dist < dist_min)
			{
				dist_min = dist;
				min = i.y;
			}
		}
		tmp = arr[i.x];
		arr[i.x] = arr[min];
		arr[min] = tmp;
	}
}
