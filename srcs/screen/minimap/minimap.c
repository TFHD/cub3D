/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:44:27 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/18 22:16:05 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "raycasting.h"

void	create_minimap_background(t_data *data, t_vec pos, t_vec size)
{
	int	y_tmp;

	y_tmp = size.y;
	while (size.x >= 0 && size.y >= 0)
	{
		if ((pos.x + size.x) * data->ray.width + size.y < data->ray.width * data->ray.height)
			data->textures[(pos.x + size.x) * data->ray.width + (pos.y + size.y)].rgba = 0xFFFFFFFF;
		size.y--;
		if (size.y < 0)
		{
			size.x--;
			size.y = y_tmp;
		}
	}
}

void	draw_player(t_data *data, t_vec pos, t_vec coords, int map_values[2])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (coords.x == (int)data->ray.pos_x && coords.y == (int)data->ray.pos_y
		&& data->ray.pos_x >= 0 && data->ray.pos_y >= 0)
	{
		while (x < map_values[0] && y < map_values[1])
		{
			data->textures[(pos.x + x) * data->ray.width + (pos.y + y)].rgba = 0xFF0000FF;
			y++;
			if (y == map_values[1])
			{
				x++;
				y = 0;
			}
		}
	}
}

void	draw_square(t_data *data, t_vec *pos, int map_values[2], char type)
{
	t_vec		coords;
	mlx_color	color;

	if (type == '1')
		color.rgba = 0x7F7F7FFF;
	else
		color.rgba = 0xFFFFFFFF;
	coords = (t_vec){0};
	while (coords.x < map_values[0] && coords.y < map_values[1])
	{
		data->textures[(pos->x + coords.x) * data->ray.width + (pos->y + coords.y)].rgba = color.rgba;
		coords.y++;
		if (coords.y == map_values[1])
		{
			coords.x++;
			coords.y = 0;
		}
	}
}

void	create_minimap_squares(t_data *data, t_vec pos, t_vec size)
{
	int		square_width;
	int		square_height;
	int		map_height;
	int		map_width;
	t_vec	vec;
	int		temp;

	temp = pos.y;
	map_height = ft_str_arr_len(data->map);
	map_width = ft_str_map_width(data->map);
	square_width = size.y / map_width;
	square_height = size.x / map_height;
	vec = (t_vec){0};
	while (vec.x < map_height)
	{
		while (vec.y < map_width)
		{
			draw_square(data, &pos, (int[2]){square_height, square_width}, data->map[vec.x][vec.y]);
			draw_player(data, pos, vec, (int[2]){square_height, square_width});
			vec.y++;
			pos.y += square_width;
		}
		pos.y = temp;
		pos.x += square_height;
		vec.y = 0;
		vec.x++;
	}
}

void	create_minimap(t_data *data, t_vec pos, t_vec size)
{
	create_minimap_background(data, pos, size);
	create_minimap_squares(data, pos, size);
}
