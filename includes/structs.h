/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:20:10 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/09 18:31:56 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libs/MacroLibX/includes/mlx.h"
# include "../libs/MacroLibX/includes/mlx_extended.h"

# define WIDTH 960
# define HEIGHT 540

typedef enum s_mlx_key
{
	CUB_UP = 26,
	CUB_DOWN = 22,
	CUB_RIGHT = 7,
	CUB_LEFT = 4,
	CUB_ARROW_LEFT = 80,
	CUB_ARROW_RIGHT = 79,
}	t_mlx_key;

typedef struct s_infos
{
	double	fov;
	double	speed_mov;
	double	speed_rot;
	double	fps;
	int		height;
	int		width;
}			t_infos;

typedef struct s_recursion_management
{
	unsigned int	i;
	unsigned int	total_recursions;
	char			max_stack_reached;
	int				save_x;
	int				save_y;
	char			error;
}					t_recursion_management;

typedef struct s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	int		color;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	movespeed;
	double	rotspeed;
	double	olddir_x;
	double	oldplane_x;
	double	speed_mov;
	double	speed_rot;
	int		height;
	int		width;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	texpos;
}			t_ray;

typedef struct s_texture
{
	char		*texture_path;
	mlx_image	img;
	mlx_color	*colors;
	int			width;
	int			height;
}				t_texture;

typedef struct s_window
{
	mlx_window				win;
	mlx_window_create_info	info;
}							t_window;

typedef struct s_data
{
	mlx_context	mlx;
	t_window	win;
	int			line_read;
	int			keys[256];
	int			floor_color[3];
	int			sky_color[3];
	char		direction;
	t_texture	no;
	t_texture	ea;
	t_texture	we;
	t_texture	so;
	mlx_color	*textures;
	char		**map;
	t_ray		ray;
}				t_data;

#endif
