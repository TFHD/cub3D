/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:01:59 by sabartho          #+#    #+#             */
/*   Updated: 2025/04/01 20:05:59 by mrouves          ###   ########.fr       */
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
	static t_data	data = {0, .floor_color = {-1}, .sky_color = {-1}};
	static t_infos	infos = {0};

	if (parsing(ac, av, &data))
		return (1);
	set_fov(&infos, 0.90);
	set_speed_mov(&infos, 7.0f);
	set_speed_rot(&infos, 5.0f);
	set_fps(&infos, 240);
	set_width(&infos, 1920);
	set_height(&infos, 1080);
	init_mlx_core(&data, infos);
	destroy_mlx_core(&data);
	free_all_end(&data);
}
