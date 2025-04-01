/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:02:36 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/07 22:42:25 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	recursion_management_init(t_recursion_management *rec_man)
{
	rec_man->i = 0;
	rec_man->total_recursions = 0;
	rec_man->max_stack_reached = 0;
	rec_man->save_x = -1;
	rec_man->save_y = -1;
	rec_man->error = 0;
}

int	find_player_location(double *x, double *y, t_data *data)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = -1;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || \
				data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				*x = (double)j;
				*y = (double)i;
				flag++;
				data->direction = data->map[i][j];
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (flag);
}
