/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:21:14 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/07 22:46:17 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	stock_map(t_data *data, char *line, int fd, int size)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->map = malloc(sizeof(char *) * (size + 1));
	while (line && x != size)
	{
		data->map[x] = malloc(ft_strlen(line));
		while (*(line + y + 1))
		{
			data->map[x][y] = *(line + y);
			y++;
		}
		data->map[x][y] = 0;
		y = 0;
		x++;
		free(line);
		line = get_next_line(fd);
	}
	data->map[x] = 0;
	close(fd);
}

int	get_map_size(t_data *data, int fd)
{
	char	*line;
	int		size;
	int		find;

	size = 0;
	find = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 1 && ft_strlen_whitespace(line) > 1)
			find = 1;
		if (!find)
			data->line_read++;
		else
			size++;
		free(line);
		line = get_next_line(fd);
	}
	return (size);
}

int	parse_map(t_data *data, int fd, char *file)
{
	char	*line;
	int		size;

	size = get_map_size(data, fd);
	(void)size;
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_error(ERROR_OPEN, file));
	line = go_to_map_line(data, fd);
	stock_map(data, line, fd, size);
	return (0);
}

int	parsing_map(t_data *data, char *file)
{
	int		fd;
	char	**map_cpy;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_error(ERROR_OPEN, file));
	if (get_colors_textures(data, 0, 0, fd))
		return (error_wrong_line(fd));
	if (parse_map(data, fd, file))
		return (1);
	map_cpy = copy_map(data->map);
	if (check_map(map_cpy, data))
		return (free_all(data, map_cpy));
	while (check_zero(NULL, NULL, map_cpy))
		if (check_map(map_cpy, data))
			return (free_all(data, map_cpy));
	free_arrays(map_cpy, 0);
	return (0);
}

int	parsing(int ac, char **av, t_data *data)
{
	if (parsing_args(ac, av))
		return (1);
	if (parsing_map(data, av[1]))
		return (1);
	return (0);
}
