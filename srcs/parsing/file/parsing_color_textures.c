/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:15:50 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/08 05:33:27 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_textures(char *line, t_texture *texture, int *textures_collect)
{
	int	fd;

	if (texture->texture_path != NULL)
		return (print_error(ERROR_TEXTURE_FILE, line));
	texture->texture_path = ft_substr(line, 3, ft_strlen(line) - 4);
	fd = open(texture->texture_path, O_RDONLY);
	if (fd == -1)
		return (print_error(ERROR_OPEN, line));
	else
		close(fd);
	(*textures_collect)++;
	return (0);
}

int	get_rgb(char *line, int rgb[3], int i, int j)
{
	while (j < 3)
	{
		while (*(line + i) && (ft_iswhitespace(*(line + i))
				|| (*(line + i) == '0' && *(line + i + 1) == '0')))
			i++;
		if (*(line + i) == '0' && ft_isdigit(*(line + i + 1)))
			i++;
		if (!ft_isdigit(*(line + i)))
			return (1);
		rgb[j] = ft_atoi(line + i, 0);
		if (rgb[j] > 255 || rgb[j] < 0)
			return (1);
		i += number_len(rgb[j]);
		while (*(line + i) && ft_iswhitespace(*(line + i))
			&& *(line + i) != ',')
			i++;
		if (*(line + i) != ',' && *(line + i) != 0)
			return (1);
		if (*(line + i) != 0)
			i++;
		j++;
	}
	return (0);
}

int	get_colors(char *line, int rgb[3], int *colors_collect)
{
	int	error;

	if (rgb[0] != -1)
		return (print_error(ERROR_COLORS, line));
	error = get_rgb(line + 2, rgb, 0, 0);
	if (error)
		return (print_error(ERROR_COLORS, line));
	(*colors_collect)++;
	return (0);
}

void	search_content(char *line, int *error, int *content[2], t_data *data)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(*(line + i)))
		i++;
	if (!ft_strncmp(line + i, "NO ", 3))
		*error = get_textures(line + i, &data->no, content[0]);
	else if (!ft_strncmp(line + i, "SO ", 3))
		*error = get_textures(line + i, &data->so, content[0]);
	else if (!ft_strncmp(line + i, "EA ", 3))
		*error = get_textures(line + i, &data->ea, content[0]);
	else if (!ft_strncmp(line + i, "WE ", 3))
		*error = get_textures(line + i, &data->we, content[0]);
	else if (!ft_strncmp(line + i, "F ", 2))
		*error = get_colors(line + i, data->floor_color, content[1]);
	else if (!ft_strncmp(line, "C ", 2))
		*error = get_colors(line + i, data->sky_color, content[1]);
	else if (ft_strcmp(line, "\n") || ft_isdigit(*(line + i)))
		*error = 2;
	free(line);
}

int	get_colors_textures(t_data *data, int textures_collect,
						int colors_collect, int fd)
{
	char	*line;
	int		error;
	int		*content[2];

	line = get_next_line(fd);
	error = 0;
	content[0] = &textures_collect;
	content[1] = &colors_collect;
	if (line == NULL)
		line = ft_strdup("");
	while (line && (textures_collect + colors_collect < 6) && !error)
	{
		data->line_read++;
		search_content(line, &error, content, data);
		if (error)
			break ;
		if (textures_collect + colors_collect != 6 && !error)
			line = get_next_line(fd);
	}
	if (error || (textures_collect + colors_collect != 6))
		return (free_textures(data, textures_collect, colors_collect, error));
	return (0);
}
