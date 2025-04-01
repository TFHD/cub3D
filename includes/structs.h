/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:20:10 by sabartho          #+#    #+#             */
/*   Updated: 2025/04/01 19:35:09 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <mlx.h>
# include <mlx_extended.h>

# define NB_SPRITES 2

typedef struct s_vec
{
	int	x;
	int	y;
}		t_vec;

typedef struct s_vecf
{
	double	x;
	double	y;
}			t_vecf;

typedef enum s_mlx_key
{
	CUB_ESCAPE = 41,
	CUB_UP = 26,
	CUB_DOWN = 22,
	CUB_RIGHT = 7,
	CUB_LEFT = 4,
	CUB_ARROW_LEFT = 80,
	CUB_ARROW_RIGHT = 79,
	CUB_ARROW_DOWN = 81,
	CUB_ARROW_UP = 82,
	CUB_RUN = 224,
	CUB_NO_CLIP = 17
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
	int				save_x;
	int				save_y;
	char			error;
	char			max_stack_reached;
}					t_recursion_management;

typedef struct s_ray
{
	t_vecf	pos;
	t_vecf	dir;
	t_vecf	raydir;
	t_vec	map;
	t_vecf	sidedist;
	t_vecf	deltadist;
	t_vec	steps;
	t_vec	tex;
	t_vec	door_open;
	t_vecf	plane;
	double	camera_x;
	int		color;
	double	perpwalldist;
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
	double	step;
	double	texpos;
	int		pitch;
	int		touch_door_open;
	double	*zbuffer;
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

typedef struct s_minimap
{
	t_vec		size;
	t_vec		pos;
}				t_minimap;

typedef struct s_sp_draw
{
	t_vecf	sprite;
	t_vecf	transform;
	t_vec	sprite_size;
	t_vec	sprite_screen;
	t_vec	draw_x;
	t_vec	draw_y;
	t_vec	tex;
}			t_sp_draw;

typedef struct s_skyfloor_draw
{
	t_vecf		floor;
	t_vecf		floor_step;
	t_vec		cell;
	t_vec		tex;
	t_vec		index;
}	t_skyfloor_draw;

typedef struct s_utils
{
	int		flash_light;
	int		radius_light;
	int		circle_x;
	int		circle_y;
	int		darkness;
	int		pitch_min;
	int		pitch_max;
	double	mid_height;
	double	mid_width;
}			t_utils;

typedef struct s_sprite
{
	t_vecf		pos;
	t_texture	tex[2];
}				t_sprite;

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
	t_texture	floor;
	t_texture	sky;
	t_texture	test;
	t_texture	door;
	t_sprite	*sprites;
	int			sprite_ord[NB_SPRITES];
	t_utils		utils;
	mlx_color	*textures;
	mlx_color	floor_colors;
	mlx_color	sky_colors;
	mlx_image	*imgs[1024];
	int			imgs_nb;
	int			error;
	char		**map;
	t_ray		ray;
	t_minimap	minimap;
	t_infos		infos;
}				t_data;

typedef struct s_thread_data
{
	t_data		data;
	t_ray		ray;
	int			start_x;
	int			end_x;
}	t_thread_data;

#endif
