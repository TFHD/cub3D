/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:47:44 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/08 03:03:19 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MANAGER_H
# define MLX_MANAGER_H

# include "structs.h"
# include <stdio.h>

# define WIDTH 960
# define HEIGHT 540

void	init_mlx_core(t_data *data, t_infos infos);
void	destroy_mlx_core(t_data *data);

void	raycaster(void *params);

void	set_fps(t_infos *infos, int fps);
void	set_fov(t_infos *infos, double fov);
void	set_speed_mov(t_infos *infos, double mov);
void	set_speed_rot(t_infos *infos, double rot);
void	set_height(t_infos *infos, int height);
void	set_width(t_infos *infos, int width);
void	set_infos(t_data *data, t_infos infos);

void	event_manager(t_data *data);
void	update_pos(void *params);

void	move_forward_back(t_data *data, t_ray *ray);
void	move_left_right(t_data *data, t_ray *ray);
void	turn_left(t_data *data, t_ray *ray);
void	turn_right(t_data *data, t_ray *ray);

#endif
