/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_maths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 04:53:37 by sabartho          #+#    #+#             */
/*   Updated: 2025/04/01 19:21:34 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D_bonus.h"

void	dda(t_ray *ray)
{
	ray->steps.x = (ray->raydir.x >= 0) - (ray->raydir.x < 0);
	ray->steps.y = (ray->raydir.y >= 0) - (ray->raydir.y < 0);
	ray->sidedist.x = (ray->map.x + 1.0 - ray->pos.x) * ray->deltadist.x;
	ray->sidedist.y = (ray->map.y + 1.0 - ray->pos.y) * ray->deltadist.y;
	if (ray->raydir.x < 0)
		ray->sidedist.x = (ray->pos.x - ray->map.x) * ray->deltadist.x;
	if (ray->raydir.y < 0)
		ray->sidedist.y = (ray->pos.y - ray->map.y) * ray->deltadist.y;
}

void	send_ray(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->map.x += ray->steps.x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->map.y += ray->steps.y;
			ray->side = 1;
		}
		if (in_map(ray->map.x, ray->map.y, data->map))
		{
			door_handler_ray(data->map, ray);
			if (is_wall(ray->map.x, ray->map.y, data->map))
				ray->hit = 1;
		}
		else if (fabs(ray->map.x - ray->pos.x) > 50
			|| fabs(ray->map.y - ray->pos.y) > 50)
			ray->hit = 1;
	}
}

void	update_textures(t_data *data, t_ray *ray, int x)
{
	t_texture		*tex;
	mlx_color		color;
	int				index;

	tex = get_texture(ray, data);
	ray->tex.x = (int)(ray->wall_x * (double)tex->width);
	if ((ray->side == 0 && ray->raydir.x > 0)
		|| (ray->side == 1 && ray->raydir.y < 0))
		ray->tex.x = tex->width - ray->tex.x - 1;
	ray->step = (double)tex->height / ray->lineheight;
	ray->texpos = (ray->drawstart - ray->pitch - data->utils.mid_height
			+ (double)(ray->lineheight >> 1)) * ray->step;
	if (in_map(ray->map.x, ray->map.y, data->map))
	{
		while (ray->drawstart < ray->drawend)
		{
			ray->tex.y = (int)ray->texpos;
			ray->texpos += ray->step;
			color = tex->colors[tex->width * ray->tex.y + ray->tex.x];
			index = data->ray.width * ray->drawstart + x;
			data->textures[index] = color;
			ray->drawstart++;
		}
	}
}

void	trace_line(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedist.x - ray->deltadist.x);
	else
		ray->perpwalldist = (ray->sidedist.y - ray->deltadist.y);
	ray->lineheight = (int)(ray->height / ray->perpwalldist);
	ray->drawstart = -(ray->lineheight >> 1)
		+ data->utils.mid_height + ray->pitch;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = (ray->lineheight >> 1) + data->utils.mid_height + ray->pitch;
	if (ray->drawend >= ray->height)
		ray->drawend = ray->height;
	if (ray->side == 0)
		ray->wall_x = ray->pos.y + ray->perpwalldist * ray->raydir.y;
	else
		ray->wall_x = ray->pos.x + ray->perpwalldist * ray->raydir.x;
	ray->wall_x -= floor(ray->wall_x);
}

void	init_value_raycasting(t_ray *ray, int x)
{
	ray->camera_x = (x << 1) / (double)ray->width - 1;
	ray->raydir.x = ray->dir.x + ray->plane.x * ray->camera_x;
	ray->raydir.y = ray->dir.y + ray->plane.y * ray->camera_x;
	ray->map.x = (int)floor(ray->pos.x);
	ray->map.y = (int)floor(ray->pos.y);
	ray->deltadist.x = fabs(1 / ray->raydir.x);
	ray->deltadist.y = fabs(1 / ray->raydir.y);
	ray->hit = 0;
}
