/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:44:56 by sabartho          #+#    #+#             */
/*   Updated: 2025/04/01 19:22:42 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"
#include "mlx_manager.h"

static inline __attribute__((always_inline)) void	matricial_transform(
	t_ray *ray, t_sp_draw *sp_draw, t_sprite *sprite)
{
	double	inv_det;

	sp_draw->sprite.x = sprite->pos.x - ray->pos.x;
	sp_draw->sprite.y = sprite->pos.y - ray->pos.y;
	inv_det = 1.0 / (ray->plane.x * ray->dir.y - ray->dir.x * ray->plane.y);
	sp_draw->transform.x = inv_det
		* (ray->dir.y * sp_draw->sprite.x - ray->dir.x * sp_draw->sprite.y);
	sp_draw->transform.y = inv_det * (-ray->plane.y * sp_draw->sprite.x
			+ ray->plane.x * sp_draw->sprite.y);
	sp_draw->sprite_screen.x = (int)((ray->width >> 1)
			* (1 + sp_draw->transform.x / sp_draw->transform.y));
	sp_draw->sprite_size.y = abs((int)(ray->height / (sp_draw->transform.y)));
}

static inline __attribute__((always_inline)) void	search_where_draw(
	t_ray *ray, t_sp_draw *sp_draw)
{
	int	half_height;
	int	half_sizey;
	int	half_sizex;

	half_height = ray->height >> 1;
	half_sizey = sp_draw->sprite_size.y >> 1;
	sp_draw->draw_y.x = half_height - half_sizey;
	if (sp_draw->draw_y.x < 0)
		sp_draw->draw_y.x = -ray->pitch;
	sp_draw->draw_y.y = half_height + half_sizey;
	if (sp_draw->draw_y.y >= ray->height - ray->pitch - 1)
		sp_draw->draw_y.y = ray->height - 1 - ray->pitch;
	sp_draw->sprite_size.x = abs((int)(ray->height / (sp_draw->transform.y)));
	half_sizex = sp_draw->sprite_size.x >> 1;
	sp_draw->draw_x.x = sp_draw->sprite_screen.x - half_sizex;
	if (sp_draw->draw_x.x < 0)
		sp_draw->draw_x.x = 0;
	sp_draw->draw_x.y = sp_draw->sprite_screen.x + half_sizex;
	if (sp_draw->draw_x.y > ray->width)
		sp_draw->draw_x.y = ray->width;
}

static inline __attribute__((always_inline)) void	draw_sprite_line(
	t_data *data, t_sp_draw *sp_draw, t_sprite *sp, t_vec i)
{
	int			dimension;
	mlx_color	color;
	t_ray		*ray;
	int			type;

	ray = &data->ray;
	type = give_type_texture(1);
	dimension = (i.y << 8) - (ray->height << 7)
		+ (sp_draw->sprite_size.y << 7);
	sp_draw->tex.y = ((dimension * sp->tex[type].height)
			/ sp_draw->sprite_size.y) >> 8;
	if (sp_draw->tex.y == sp->tex[type].height - 1 || sp_draw->tex.y < 0)
		color.rgba = 0x0;
	else if (sp->tex[type].width * sp_draw->tex.y
		+ sp_draw->tex.x < sp->tex[type].width * sp->tex[type].height)
		color = sp->tex[type].colors
		[sp->tex[type].width * sp_draw->tex.y + sp_draw->tex.x];
	if ((color.rgba & 0xFFFFFF00) != 0 && ((i.y + ray->pitch)
			* ray->width + i.x > 0 && (i.y + ray->pitch)
			* ray->width + i.x < ray->width * ray->height))
		data->textures[(i.y + ray->pitch) * ray->width + i.x] = color;
}

static inline __attribute__((always_inline)) void	draw_sprite(
	t_data *data, t_ray *ray, t_sp_draw *sp_draw, t_sprite *sp)
{
	int			x;
	int			y;
	int			type;

	type = give_type_texture(0);
	x = sp_draw->draw_x.x - 1;
	y = sp_draw->draw_y.x - 1;
	sp_draw->tex.y = 0;
	while (++x < sp_draw->draw_x.y)
	{
		sp_draw->tex.x = (int)
			((x - (-(sp_draw->sprite_size.x >> 1) + sp_draw->sprite_screen.x))
				* sp->tex[type].width / sp_draw->sprite_size.x);
		if (sp_draw->transform.y > 0 && sp_draw->transform.y < ray->zbuffer[x])
		{
			while (++y < sp_draw->draw_y.y)
				draw_sprite_line(data, sp_draw, sp, (t_vec){x, y});
			y = sp_draw->draw_y.x - 1;
		}
	}
}

void	raycasting_sprites(t_data *data, t_ray *ray)
{
	t_sp_draw	sp_draw;
	int			i;
	int			nb;

	i = -1;
	while (++i < NB_SPRITES)
		data->sprite_ord[i] = i;
	i = -1;
	sort_sprites(data->sprites, &ray->pos, data->sprite_ord, (t_vec){-1, -1});
	while (++i < NB_SPRITES)
	{
		nb = data->sprite_ord[NB_SPRITES - i - 1];
		matricial_transform(ray, &sp_draw, &data->sprites[nb]);
		search_where_draw(ray, &sp_draw);
		draw_sprite(data, ray, &sp_draw, &data->sprites[nb]);
	}
}
