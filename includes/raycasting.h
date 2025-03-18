/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:10:14 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/18 17:39:16 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "structs.h"
# include "parsing.h"
# include <math.h>
# include <sys/time.h>

void		print_fps(void *params, double fps);
void		print_coords(void *data);

void		dda(t_ray *ray);
void		send_ray(t_data *data, t_ray *ray);
void		update_textures(t_data *data, t_ray *ray, int x);
void		trace_line(t_ray *ray);
t_texture	*get_texture(t_ray *ray, t_data *data);
void		init_value_raycasting(t_ray *ray, int x);

void		torch_effect(t_data *data, t_ray *ray, int x, int index);
void		create_minimap(t_data *data, t_vec pos, t_vec size);

#endif
