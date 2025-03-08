/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color_textures_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 05:11:43 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/08 05:12:14 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	free_textures(t_data *data, int textures_collect,
					int colors_collect, int error)
{
	if (data->so.texture_path)
		free(data->so.texture_path);
	if (data->no.texture_path)
		free(data->no.texture_path);
	if (data->we.texture_path)
		free(data->we.texture_path);
	if (data->ea.texture_path)
		free(data->ea.texture_path);
	if (textures_collect != 4 && error == 2)
		print_error(ERROR_MISSING_TEXTURES, NULL);
	else if (colors_collect != 2 && error == 2)
		print_error(ERROR_MISSING_COLORS, NULL);
	return (1);
}
