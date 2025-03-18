/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:10:52 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/18 16:09:32 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

float	is_in_circle(int x, int y, t_utils utils)
{
	int	radius;
	int	pos;
	int	circle_x;
	int	circle_y;

	radius = utils.radius_light;
	circle_x = utils.circle_x;
	circle_y = utils.circle_y;
	pos = (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y);
	if (pos <= radius * radius)
		return (0.01 * ((float)pos / radius));
	return (0);
}

void	torch_effect(t_data *data, t_ray *ray, int x, int index)
{
	float	darkness;
	float	circle;
	float	res;
	float	tmp;

	circle = is_in_circle(x, ray->drawstart, data->utils);
	res = ray->perpwalldist * circle * (circle >= 1)
		+ (circle < 1) * (ray->perpwalldist);
	tmp = res;
	res = 1 / res;
	if (ray->perpwalldist > 1.0 / data->utils.darkness
		&& (!data->flash_light || !circle))
	{
		darkness = 1 / (ray->perpwalldist * data->utils.darkness);
		data->textures[index].r *= darkness;
		data->textures[index].g *= darkness;
		data->textures[index].b *= darkness;
	}
	else if (data->flash_light && circle
		&& ray->perpwalldist > 1.0 / data->utils.darkness)
	{
		data->textures[index].r *= res * (tmp >= 1) + (tmp < 1);
		data->textures[index].g *= res * (tmp >= 1) + (tmp < 1);
		data->textures[index].b *= res * (tmp >= 1) + (tmp < 1);
	}
}
