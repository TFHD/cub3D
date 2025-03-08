/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:01:59 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/08 05:48:40 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->line_read = 0;
	ft_memset(&data->ea, 0, sizeof(t_texture));
	ft_memset(&data->we, 0, sizeof(t_texture));
	ft_memset(&data->so, 0, sizeof(t_texture));
	ft_memset(&data->no, 0, sizeof(t_texture));
	ft_memset(&data->win, 0, sizeof(t_window));
	ft_memset(&data->ray, 0, sizeof(t_ray));
	while (i < 3)
	{
		data->floor_color[i] = -1;
		data->sky_color[i++] = -1;
	}
	ft_memset(&data->keys, 0, sizeof(data->keys));
}

void	free_all_end(t_data *data)
{
	free_textures(data, 0, 0, 0);
	free_arrays(data->map, 0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_infos	infos;

	init_data(&data);
	if (parsing(ac, av, &data))
		return (1);
	set_fov(&infos, 0.90);
	set_speed_mov(&infos, 7.0f);
	set_speed_rot(&infos, 3.0f);
	set_fps(&infos, 240);
	set_width(&infos, 1110);
	set_height(&infos, 700);
	init_mlx_core(&data, infos);
	destroy_mlx_core(&data);
	free_all_end(&data);
}
