/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:47:37 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/31 22:47:53 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	key_event(int key, void *params)
{
	t_data	*data;

	data = (t_data *)params;
	if (key == CUB_ESCAPE)
		mlx_loop_end(data->mlx);
	data->keys[key] = 1;
	if (key == 9 && !data->utils.flash_light)
	{
		data->utils.flash_light = 1;
		return ;
	}
	if (key == 9 && data->utils.flash_light)
		data->utils.flash_light = 0;
}

void	key_release_event(int key, void *params)
{
	t_data	*data;

	data = (t_data *)params;
	data->keys[key] = 0;
}
