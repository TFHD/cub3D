/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_maths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 04:53:37 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/08 05:04:28 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "raycasting.h"
#include "structs.h"

void	dda(t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (ray->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (ray->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->deltadist_y;
	}
}

void	send_ray(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if ((ray->map_x >= 0 && ray->map_x < ft_str_arr_len(data->map))
			&& (ray->map_y >= 0
				&& ray->map_y < (int)ft_strlen(data->map[ray->map_x])))
		{
			if (data->map[ray->map_x][ray->map_y] == '1')
				ray->hit = 1;
		}
		else if (fabs(ray->map_x - ray->pos_x) > 50
			|| fabs(ray->map_y - ray->pos_y) > 50)
			ray->hit = 1;
	}
}

void	update_textures(t_data *data, t_ray *ray, int x)
{
	t_texture		*tex;
	mlx_color		color;

	tex = get_texture(ray, data);
	ray->tex_x = (int)(ray->wall_x * (double)tex->width);
	if ((ray->side == 0 && ray->raydir_x > 0)
		|| (ray->side == 1 && ray->raydir_y < 0))
		ray->tex_x = tex->width - ray->tex_x - 1;
	ray->step = 1.0 * tex->height / ray->lineheight;
	ray->texpos = (ray->drawstart - (double)ray->height / 2
			+ (double)ray->lineheight / 2) * ray->step;
	if ((ray->map_x >= 0 && ray->map_x < ft_str_arr_len(data->map))
		&& (ray->map_y >= 0
			&& ray->map_y < (int)ft_strlen(data->map[ray->map_x])))
	{
		while (ray->drawstart < ray->drawend)
		{
			ray->tex_y = (int)ray->texpos;
			ray->texpos += ray->step;
			color = tex->colors[tex->width * ray->tex_y + ray->tex_x];
			data->textures[data->ray.width
				* ray->drawstart++ + x].rgba = color.rgba;
		}
	}
}

void	trace_line(t_ray *ray)
{
	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->perpwalldist = (ray->sidedist_y - ray->deltadist_y);
	ray->lineheight = (int)(ray->height / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + ray->height / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + ray->height / 2;
	if (ray->drawend >= ray->height)
		ray->drawend = ray->height - 1;
	if (ray->side == 0)
		ray->wall_x = ray->pos_y + ray->perpwalldist * ray->raydir_y;
	else
		ray->wall_x = ray->pos_x + ray->perpwalldist * ray->raydir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	init_value_raycasting(t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)ray->width - 1;
	ray->raydir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->raydir_y = ray->dir_y + ray->plane_y * ray->camera_x;
	ray->map_x = (int)floor(ray->pos_x);
	ray->map_y = (int)floor(ray->pos_y);
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
	ray->hit = 0;
}
