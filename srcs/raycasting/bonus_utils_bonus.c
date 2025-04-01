/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:57:29 by sabartho          #+#    #+#             */
/*   Updated: 2025/04/01 17:58:25 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D_bonus.h"

int	give_type_texture(int incr)
{
	static struct timeval	val_cur;
	static int				last_res;	

	if (!incr)
		return (last_res);
	gettimeofday(&val_cur, 0);
	if (val_cur.tv_usec > 0 && val_cur.tv_usec < 600000 == 0)
	{
		last_res = 1;
		return (1);
	}
	last_res = 0;
	return (0);
}

int	check_files_are_here(void)
{
	static char	*files[6] = {"./textures/lebron.jpg",
		"./textures/lebron1.png",
		"./textures/lamptorch.png",
		"./textures/planks_jungle.png",
		"./textures/clay.png",
		"./textures/door.jpeg"};
	int			fd;
	int			i;

	i = -1;
	while (++i < 6)
	{
		fd = open(files[i], O_RDONLY);
		if (fd == -1)
			return (1);
		close(fd);
	}
	return (0);
}
