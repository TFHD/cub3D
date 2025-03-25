/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_floor_sky.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:50:19 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/25 16:09:39 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <math.h>

void render_sky_floor(t_data *data, t_ray *ray)
{
	for(int y = 0; y < ray->height; ++y)
	{
		float	rayDirX0 = ray->dir_x - ray->plane_x;
		float	rayDirY0 = ray->dir_y - ray->plane_y;
		float	rayDirX1 = ray->dir_x + ray->plane_x;
		float	rayDirY1 = ray->dir_y + ray->plane_y;
		int		p = ray->height * 0.5 + ray->pitch;
		float	posZ = 0.5 * ray->height + ray->pitch;
		float	rowDistance;
		if (y > posZ)
			rowDistance = posZ / (y - p);
		else
			rowDistance = posZ / (p - y);
		float	floorStepX = rowDistance * (rayDirX1 - rayDirX0) / ray->width;
		float	floorStepY = rowDistance * (rayDirY1 - rayDirY0) / ray->width;

		float	floorX = ray->pos_x + rowDistance * rayDirX0;
		float	floorY = ray->pos_y + rowDistance * rayDirY0;

		for(int x = 0; x < ray->width; ++x)
		{
			int	cellX = (int)(floorX);
			int	cellY = (int)(floorY);

			int tx = (int)(data->floor.width * (floorX - cellX)) & (data->sky.width - 1);
			int ty = (int)(data->floor.height * (floorY - cellY)) & (data->sky.height - 1);
			floorX += floorStepX;
			floorY += floorStepY;
			mlx_color color;
			if (y > ray->height * 0.5 + ray->pitch)
				color = data->floor.colors[data->floor.width * ty + tx];
			else
				color = data->sky.colors[data->sky.width * ty + tx];
			data->textures[y * ray->width + x] = color;
		}
	}
}
