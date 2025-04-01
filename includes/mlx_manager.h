/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:47:44 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/31 22:51:32 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MANAGER_H
# define MLX_MANAGER_H

# include <structs.h>

void	init_mlx_core(t_data *data, t_infos infos);
void	destroy_mlx_core(t_data *data);

void	raycaster(void *params);

void	set_infos(t_data *data, t_infos infos);
void	set_utils(t_utils *utils, t_infos infos);
void	load_image(t_data *data, t_texture *tex);
void	set_win_player_textures_infos(t_data *data, t_infos infos);
void	set_sprites(t_data *data);

void	key_release_event(int key, void *params);
void	key_event(int key, void *params);
void	event_manager(t_data *data);
void	update_pos(void *params);

void	move_forward_back(t_data *data, t_ray *ray);
void	move_left_right(t_data *data, t_ray *ray);
void	up(t_data *data, t_ray *ray, t_vecf *vec);
void	down(t_data *data, t_ray *ray, t_vecf *vec);
void	left(t_data *data, t_ray *ray, t_vecf *vec);
void	right(t_data *data, t_ray *ray, t_vecf *vec);
void	turn_around(t_data *data, t_ray *ray, t_vec *mouse, t_vecf offset);
void	speed_handler(t_data *data, t_ray *ray);
double	get_fps(void);

#endif
