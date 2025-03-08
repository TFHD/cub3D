/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:36:16 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/08 04:48:07 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manager.h"
#include "structs.h"
#include <stdlib.h>

void	init_mlx_core(t_data *data, t_infos infos)
{
	data->mlx = mlx_init();
	set_infos(data, infos);
	event_manager(data);
	mlx_add_loop_hook(data->mlx, update_pos, data);
	mlx_add_loop_hook(data->mlx, raycaster, data);
	mlx_loop(data->mlx);
}

void	destroy_mlx_core(t_data *data)
{
	free(data->textures);
	free(data->no.colors);
	free(data->ea.colors);
	free(data->we.colors);
	free(data->so.colors);
	mlx_destroy_image(data->mlx, data->no.img);
	mlx_destroy_image(data->mlx, data->so.img);
	mlx_destroy_image(data->mlx, data->ea.img);
	mlx_destroy_image(data->mlx, data->we.img);
	mlx_destroy_window(data->mlx, data->win.win);
	mlx_destroy_context(data->mlx);
}
