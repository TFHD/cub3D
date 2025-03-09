/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:03:12 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/08 18:56:09 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	recursion_management(t_recursion_management *rec_man,
								int *x, int *y, char **map)
{
	if (rec_man->max_stack_reached == 1)
		return (-1);
	if (rec_man->i == 1000)
	{
		rec_man->max_stack_reached = 1;
		rec_man->i = 0;
		return (-1);
	}
	if (rec_man->i == 0 && rec_man->total_recursions != 0)
	{
		*x = rec_man->save_x;
		*y = rec_man->save_y;
		map[*y][*x] = '0';
	}
	rec_man->total_recursions++;
	rec_man->i++;
	return (0);
}

static int	flood_fill(int x, int y, char **map,
						t_recursion_management *rec_man)
{
	if (recursion_management(rec_man, &x, &y, map))
		return (-1);
	if (x < 0 || y < 0 || y >= ft_str_arr_len(map)
		|| x >= (int)ft_strlen(map[y]) || ft_isspace(map[y][x]) != 0)
	{
		rec_man->error = 1;
		return (1);
	}
	else if (map[y][x] == '1')
		return (0);
	else if (map[y][x] == '0')
	{
		rec_man->save_x = x;
		rec_man->save_y = y;
	}
	map[y][x] = '1';
	return (flood_fill(x + 1, y, map, rec_man)
		+ flood_fill(x - 1, y, map, rec_man)
		+ flood_fill(x, y + 1, map, rec_man)
		+ flood_fill(x, y - 1, map, rec_man));
}

static int	managed_flood_fill(int player_x, int player_y, char **map,
						t_recursion_management *rec_man)
{
	int	ret;

	ret = -1;
	while (ret != 0)
	{
		ret = flood_fill(player_x, player_y, map, rec_man);
		rec_man->max_stack_reached = 0;
		if (rec_man->error == 1)
			break ;
	}
	return (ret);
}

int	check_map(char **map, t_data *data)
{
	static int				i = 0;
	int						ret;
	double					player_x;
	double					player_y;
	t_recursion_management	rec_man;

	player_x = -1;
	player_y = -1;
	if (i)
		check_zero(&player_x, &player_y, map);
	else if (find_player_location(&player_x, &player_y, data))
		return (print_error(ERROR_MAP_NO_1_PLAYER, NULL, TRUE));
	if (check_wrong_chars(map))
		return (print_error(ERROR_MAP_BAD_ELEMENTS, NULL, TRUE));
	recursion_management_init(&rec_man);
	ret = managed_flood_fill(player_x, player_y, map, &rec_man);
	if (rec_man.error == 1)
		return (print_error(ERROR_MAP_WALLS, NULL, TRUE));
	i++;
	return (ret);
}
