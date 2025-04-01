/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:36:16 by sabartho          #+#    #+#             */
/*   Updated: 2025/04/01 20:01:43 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D_bonus.h"

void	load_image(t_data *data, t_texture *tex)
{
	tex->img = mlx_new_image_from_file(data->mlx,
			tex->texture_path, &tex->width, &tex->height);
	tex->colors = malloc(sizeof(mlx_color)
			* (tex->width + 1) * (tex->height + 1));
	mlx_get_image_region(data->mlx, tex->img, 0, 0,
		tex->width, tex->height, tex->colors);
	data->imgs[data->imgs_nb++] = &tex->img;
}

void	init_mlx_core(t_data *data, t_infos infos)
{
	data->mlx = mlx_init();
	if (set_infos(data, infos))
	{
		data->error = 1;
		return ;
	}
	data->keys[255] = 1;
	mlx_add_loop_hook(data->mlx, update_pos, data);
	mlx_add_loop_hook(data->mlx, raycaster, data);
	event_manager(data);
	mlx_loop(data->mlx);
}

void	destroy_mlx_image_core(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->imgs_nb)
		if (*data->imgs[i])
			mlx_destroy_image(data->mlx, *data->imgs[i]);
}

void	free_sprites(t_data *data)
{
	int	i;

	i = 0;
	while (i < NB_SPRITES && !data->error)
	{
		free(data->sprites[i].tex[0].colors);
		free(data->sprites[i].tex[1].colors);
		i++;
	}
	free(data->sprites);
}

void	destroy_mlx_core(t_data *data)
{
	free(data->textures);
	free(data->no.colors);
	free(data->ea.colors);
	free(data->we.colors);
	free(data->so.colors);
	free(data->floor.colors);
	free(data->sky.colors);
	free(data->test.colors);
	free(data->test.texture_path);
	free(data->sky.texture_path);
	free(data->floor.texture_path);
	free(data->door.texture_path);
	free(data->door.colors);
	destroy_mlx_image_core(data);
	free(data->ray.zbuffer);
	free_sprites(data);
	mlx_destroy_window(data->mlx, data->win.win);
	mlx_destroy_context(data->mlx);
}
