/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:10:14 by sabartho          #+#    #+#             */
/*   Updated: 2025/04/01 19:15:17 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <structs_bonus.h>
# include <parsing_bonus.h>
# include <math.h>
# include <sys/time.h>

void		print_fps(t_data *data, double fps);
void		print_coords(void *data);

void		dda(t_ray *ray);
void		send_ray(t_data *data, t_ray *ray);
void		update_textures(t_data *data, t_ray *ray, int x);
void		trace_line(t_data *data, t_ray *ray);
t_texture	*get_texture(t_ray *ray, t_data *data);
void		init_value_raycasting(t_ray *ray, int x);
int			in_map(int x, int y, char **map);
void		raycasting_sprites(t_data *data, t_ray *ray);
void		door_handler_ray(char **map, t_ray *ray);
void		sort_sprites(t_sprite *sprite, t_vecf *pos, int *arr, t_vec i);
void		threading_raycast_sky_floor(t_data *data, t_ray *ray);

void		torch_effect(t_data *data, t_ray *ray, int x, int index);
void		create_minimap(t_data *data, t_vec pos, t_vec size);
int			give_type_texture(int incr);

double		get_fps(void);
int			has_moove(t_data *data);

#endif
