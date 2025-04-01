/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_directions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:11:14 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/31 23:16:06 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D_bonus.h"

void	up(t_data *data, t_ray *ray, t_vecf *vec)
{
	if (!in_map(ray->pos.x + vec->x, ray->pos.y, data->map)
		|| !is_wall(ray->pos.x + vec->x, ray->pos.y, data->map)
		|| data->keys[CUB_NO_CLIP])
		ray->pos.x += ray->dir.x * ray->movespeed;
	if (!in_map(ray->pos.x, ray->pos.y + vec->y, data->map)
		|| !is_wall(ray->pos.x, ray->pos.y + vec->y, data->map)
		|| data->keys[CUB_NO_CLIP])
		ray->pos.y += ray->dir.y * ray->movespeed;
}

void	down(t_data *data, t_ray *ray, t_vecf *vec)
{
	if (!in_map(ray->pos.x - vec->x, ray->pos.y, data->map)
		|| !is_wall(ray->pos.x - vec->x, ray->pos.y, data->map)
		|| data->keys[CUB_NO_CLIP])
		ray->pos.x -= ray->dir.x * ray->movespeed;
	if (!in_map(ray->pos.x, ray->pos.y - vec->y, data->map)
		|| !is_wall(ray->pos.x, ray->pos.y - vec->y, data->map)
		|| data->keys[CUB_NO_CLIP])
		ray->pos.y -= ray->dir.y * ray->movespeed;
}

void	left(t_data *data, t_ray *ray, t_vecf *vec)
{
	if (!in_map(ray->pos.x - vec->y, ray->pos.y, data->map)
		|| !is_wall(ray->pos.x - vec->y, ray->pos.y, data->map)
		|| data->keys[CUB_NO_CLIP])
		ray->pos.x -= ray->dir.y * ray->movespeed;
	if (!in_map(ray->pos.x, ray->pos.y + vec->x, data->map)
		|| !is_wall(ray->pos.x, ray->pos.y + vec->x, data->map)
		|| data->keys[CUB_NO_CLIP])
		ray->pos.y += ray->dir.x * ray->movespeed;
}

void	right(t_data *data, t_ray *ray, t_vecf *vec)
{
	if (!in_map(ray->pos.x + vec->y, ray->pos.y, data->map)
		|| !is_wall(ray->pos.x + vec->y, ray->pos.y, data->map)
		|| data->keys[CUB_NO_CLIP])
		ray->pos.x += ray->dir.y * ray->movespeed;
	if (!in_map(ray->pos.x, ray->pos.y - vec->x, data->map)
		|| !is_wall(ray->pos.x, ray->pos.y - vec->x, data->map)
		|| data->keys[CUB_NO_CLIP])
		ray->pos.y -= ray->dir.x * ray->movespeed;
}
