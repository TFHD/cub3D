/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:12:41 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/07 01:07:03 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	print_error(char *str, char *arg)
{
	write(2, ERROR, ft_strlen(ERROR));
	if (str)
		write(2, str, ft_strlen(str));
	if (arg)
		write(2, arg, ft_strlen(arg));
	write(2, "\n\e[0m", 5);
	return (1);
}

int	error_wrong_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	ft_strlen_whitespace(char *str)
{
	int	i;
	int	caract;

	i = 0;
	caract = 0;
	while (*(str + i))
	{
		if (!ft_iswhitespace(*(str + i)))
			caract++;
		i++;
	}
	return (caract);
}

int	parsing_args(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (print_error(ERROR_NUM_ARGS, NULL));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (print_error(ERROR_OPEN, av[1]));
	if (ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".cub"))
	{
		close(fd);
		return (print_error(ERROR_NAME_FILE, av[1]));
	}
	close(fd);
	return (0);
}

int	check_pos_infos(char *line, int textures_collect, char infos[6][4], int i)
{
	if (ft_strncmp(line, infos[textures_collect], 3 - i))
		return (1);
	return (0);
}
