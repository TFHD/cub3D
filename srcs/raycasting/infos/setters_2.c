/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:58:53 by sabartho          #+#    #+#             */
/*   Updated: 2025/04/01 20:01:38 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	set_infos(t_data *data, t_infos infos)
{
	if (set_win_player_textures_infos(data, infos))
		return (1);
	set_utils(&data->utils, infos);
	load_image(data, &data->test);
	load_image(data, &data->no);
	load_image(data, &data->so);
	load_image(data, &data->we);
	load_image(data, &data->ea);
	data->sky.texture_path = ft_strdup("./textures/planks_jungle.png");
	data->floor.texture_path = ft_strdup("./textures/clay.png");
	data->door.texture_path = ft_strdup("./textures/door.jpeg");
	load_image(data, &data->sky);
	load_image(data, &data->door);
	load_image(data, &data->floor);
	if (!data->test.img || !data->no.img || !data->so.img || !data->we.img
		|| !data->ea.img || !data->sky.img || !data->door.img
		|| !data->floor.img)
		return (1);
	if (set_sprites(data))
		return (1);
	mlx_mouse_move(data->mlx, data->win.win, data->utils.mid_width,
		data->utils.mid_height);
	return (0);
}
