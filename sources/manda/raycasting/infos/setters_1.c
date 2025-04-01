/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:54:05 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/07 01:21:25 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	set_fov(t_infos *infos, double fov)
{
	infos->fov = fov;
}

void	set_speed_mov(t_infos *infos, double mov)
{
	infos->speed_mov = mov;
}

void	set_speed_rot(t_infos *infos, double rot)
{
	infos->speed_rot = rot;
}

void	set_fps(t_infos *infos, int fps)
{
	infos->fps = fps;
}

void	set_height(t_infos *infos, int height)
{
	infos->height = height;
}
