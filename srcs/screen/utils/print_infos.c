/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:05:26 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/08 03:25:35 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_manager.h"
#include "structs.h"
#include <sys/time.h>
#include <unistd.h>
#include "../../../libs/libft/includes/libft.h"

void	print_coords(void *data_ptr)
{
	t_data	*data;
	char	str_x[15];
	char	str_y[15];
	char	x[11];
	char	y[11];

	data = (t_data *)data_ptr;
	ft_strcpy(str_x, "X : ");
	ft_strcpy(str_y, "Y : ");
	ft_itoa_buffer((int)data->ray.pos_x, x);
	ft_itoa_buffer((int)data->ray.pos_y, y);
	ft_strcat(str_x, x);
	ft_strcat(str_y, y);
	mlx_string_put(data->mlx, data->win.win, 5,
		50, (mlx_color){.rgba = 0xFFFFFFFF}, str_x);
	mlx_string_put(data->mlx, data->win.win, 5,
		70, (mlx_color){.rgba = 0xFFFFFFFF}, str_y);
}

void	print_windows_size(void *params)
{
	int		w;
	int		h;
	t_data	*data;

	data = (t_data *)params;
	mlx_get_window_size(data->mlx, data->win.win, &w, &h);
	printf("WIDTH : %d\n", w);
	printf("HEIGHT : %d\n", h);
}

void	print_fps(t_data *data, double fps)
{
	static int				frame = 0;
	static struct timeval	val_cur;
	static struct timeval	val_last;
	char					str[17];
	char					c_fps[11];

	ft_strcpy(str, "FPS : ");
	gettimeofday(&val_cur, 0);
	frame++;
	fps = (val_cur.tv_sec - val_last.tv_sec)
		+ (val_cur.tv_usec - val_last.tv_usec) / 1000000.0;
	ft_itoa_buffer(frame / fps, c_fps);
	ft_strcat(str, c_fps);
	mlx_set_font(data->mlx, "libs/font/Minecraft.ttf");
	mlx_set_font_scale(data->mlx, "libs/font/Minecraft.ttf", 21.0);
	mlx_string_put(data->mlx, data->win.win, 5,
		20, (mlx_color){.rgba = 0xFFFFFFFF}, str);
	frame = 0;
	val_last = val_cur;
}
