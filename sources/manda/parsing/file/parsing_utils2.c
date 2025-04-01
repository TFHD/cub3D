/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:54:14 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/05 00:27:50 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	number_len(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_str_map_width(char **map)
{
	int	x;
	int	len;

	len = 0;
	x = 0;
	while (map[x])
	{
		if ((int)ft_strlen(map[x]) > len)
			len = ft_strlen(map[x]);
		x++;
	}
	return (len);
}

int	free_all(t_data *data, char **map_cpy)
{
	int	i;

	i = 0;
	while (map_cpy[i])
		free(map_cpy[i++]);
	free(map_cpy);
	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
	free_textures(data, 0, 0, 0);
	return (1);
}

char	*go_to_map_line(t_data *data, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line && i != data->line_read)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

void	print_map(char **map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		ft_printf("%s", map[x++]);
		ft_printf("\n");
	}
}
