/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:05:26 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/31 22:28:42 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "Cub3D_bonus.h"

void	print_coords(void *data_ptr)
{
	t_data	*data;
	char	str_x[15];
	char	str_y[15];
	char	x[12];
	char	y[12];

	data = (t_data *)data_ptr;
	ft_strcpy(str_x, "X : ");
	ft_strcpy(str_y, "Y : ");
	ft_itoa_buf((int)data->ray.pos.x, x);
	ft_itoa_buf((int)data->ray.pos.y, y);
	ft_strcat(str_x, x);
	ft_strcat(str_y, y);
	mlx_string_put(data->mlx, data->win.win, 5,
		50, (mlx_color){.rgba = 0xFFFFFFFF}, str_x);
	mlx_string_put(data->mlx, data->win.win, 5,
		70, (mlx_color){.rgba = 0xFFFFFFFF}, str_y);
}

void	print_fps(t_data *data, double fps)
{
	static int				frame = 0;
	static struct timeval	val_cur;
	static struct timeval	val_last;
	char					str[17];
	char					c_fps[12];

	ft_strcpy(str, "FPS : ");
	gettimeofday(&val_cur, 0);
	frame++;
	fps = (val_cur.tv_sec - val_last.tv_sec)
		+ (val_cur.tv_usec - val_last.tv_usec) * 0.000001;
	ft_itoa_buf(frame / fps, c_fps);
	ft_strcat(str, c_fps);
	mlx_set_font(data->mlx, "libs/font/Minecraft.ttf");
	mlx_set_font_scale(data->mlx, "libs/font/Minecraft.ttf", 21.0);
	mlx_string_put(data->mlx, data->win.win, 5,
		20, (mlx_color){.rgba = 0xFFFFFFFF}, str);
	frame = 0;
	val_last = val_cur;
}

int	in_map(int x, int y, char **map)
{
	if (x >= 0 && y >= 0 && x < ft_str_arr_len(map)
		&& y < (int)ft_strlen(map[x]))
		return (1);
	return (0);
}

int	is_wall(int x, int y, char **map)
{
	if (map[x][y] == '1' || map[x][y] == '2')
		return (1);
	return (0);
}
