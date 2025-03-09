/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color_textures_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 05:11:43 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/08 22:31:47 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	free_textures(t_data *data, int textures_collect,
					int colors_collect, int error)
{
	int	nb_error;

	nb_error = 0;
	if (data->so.texture_path)
		free(data->so.texture_path);
	if (data->no.texture_path)
		free(data->no.texture_path);
	if (data->we.texture_path)
		free(data->we.texture_path);
	if (data->ea.texture_path)
		free(data->ea.texture_path);
	if (textures_collect != 4 && error == 2)
		print_error(ERROR_MISSING_TEXTURES, NULL, ++nb_error);
	if (colors_collect != 2 && error == 2)
		print_error(ERROR_MISSING_COLORS, NULL, nb_error - 1);
	return (1);
}

int	search_double(char *line, int fd)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (ft_iswhitespace(*(line + i)))
		i++;
	if (!ft_strncmp(line + i, "NO ", 3))
		error = error_wrong_line(fd);
	else if (!ft_strncmp(line + i, "SO ", 3))
		error = 1;
	else if (!ft_strncmp(line + i, "EA ", 3))
		error = 1;
	else if (!ft_strncmp(line + i, "WE ", 3))
		error = 1;
	else if (!ft_strncmp(line + i, "F ", 2))
		error = 1;
	else if (!ft_strncmp(line + i, "C ", 2))
		error = 1;
	if (error)
		return (print_error(ERROR_DUPLICATE_ELEMENTS, line, TRUE));
	return (0);
}
