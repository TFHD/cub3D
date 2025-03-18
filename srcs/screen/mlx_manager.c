/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:36:16 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/16 18:34:19 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manager.h"
#include "structs.h"
#include <stdlib.h>

void	init_mlx_core(t_data *data, t_infos infos)
{
	data->mlx = mlx_init();
	set_infos(data, infos);
	mlx_add_loop_hook(data->mlx, update_pos, data);
	mlx_add_loop_hook(data->mlx, raycaster, data);
	event_manager(data);
	mlx_loop(data->mlx);
}

void	destroy_mlx_image_core(t_data *data)
{
	int	i;

	i = 0;
	while (data->imgs[i] != 0)
		mlx_destroy_image(data->mlx, *data->imgs[i++]);
	free(data->imgs);
}

void	destroy_mlx_core(t_data *data)
{
	free(data->textures);
	free(data->no.colors);
	free(data->ea.colors);
	free(data->we.colors);
	free(data->so.colors);
	free(data->test.colors);
	free(data->test.texture_path);
	destroy_mlx_image_core(data);
	mlx_destroy_window(data->mlx, data->win.win);
	mlx_destroy_context(data->mlx);
}
