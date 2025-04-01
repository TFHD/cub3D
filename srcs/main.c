/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:01:59 by sabartho          #+#    #+#             */
/*   Updated: 2025/04/01 17:16:04 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	free_all_end(t_data *data)
{
	free_textures(data, 0, 0, 0);
	free_arrays(data->map, 0);
}

int	main(int ac, char **av)
{
	static t_data	data = {0, .sky_color = {-1}, .floor_color = {-1}};
	t_infos			infos;

	if (parsing(ac, av, &data))
		return (1);
	system("paplay ./sound.wav &");
	infos.fov = FOV;
	infos.height = HEIGHT;
	infos.fps = FPS;
	infos.width = WIDTH;
	infos.speed_mov = SPEED_MOVEMENT;
	infos.speed_rot = SPEED_RORATE;
	data.infos = infos;
	init_mlx_core(&data, infos);
	destroy_mlx_core(&data);
	free_all_end(&data);
}
