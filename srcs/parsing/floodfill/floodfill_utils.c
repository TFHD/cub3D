/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:42:14 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/08 18:46:54 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_str_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (*(arr + i) != NULL)
		i++;
	return (i);
}

void	*free_arrays(char **copy, int i)
{
	int	j;

	j = 0;
	if (i)
	{
		while (j < i)
			free(copy[j++]);
	}
	else
	{
		while (copy[j])
			free(copy[j++]);
	}
	free(copy);
	return (NULL);
}

char	**copy_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(*copy) * (ft_str_arr_len(map) + 1));
	if (copy == NULL)
		return (NULL);
	while (map[i] != NULL)
	{
		copy[i] = malloc(sizeof(*copy[i]) * (ft_strlen(map[i]) + 1));
		if (copy[i] == NULL)
			return (free_arrays(copy, i));
		ft_strlcpy(copy[i], map[i], ft_strlen(map[i]) + 1);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	check_wrong_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		if (map[i][j] == '\0')
			return (-1);
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'W' && map[i][j] != 'E'
				&& map[i][j] != '1' && map[i][j] != '0'
				&& ft_isspace(map[i][j]) == 0)
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_zero(double *player_x, double *player_y, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == '0')
			{
				if (player_x && player_y)
				{
					*player_x = y;
					*player_y = x;
				}
				return (1);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}
