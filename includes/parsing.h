/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <sabartho@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:02:06 by sabartho          #+#    #+#             */
/*   Updated: 2025/03/08 05:39:16 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "structs.h"
# include "../libs/libft/includes/libft.h"

# define ERROR "Error\n"
# define ERROR_NUM_ARGS "\e[31mInvalid argument number !"
# define ERROR_NAME_FILE "\e[31mInvalid file name : "
# define ERROR_OPEN "\e[31mNo file exist : "
# define ERROR_TEXTURE_FILE "\e[31mError Textures : "
# define ERROR_COLORS "\e[31mError Colors : "
# define ERROR_MISSING_COLORS "\e[31mMissing Colors !"
# define ERROR_MISSING_TEXTURES "\e[31mMissing Textures !"
# define ERROR_MAP_NO_1_PLAYER "\e[31mNo or more than 1 player int he map !"
# define ERROR_MAP_WALLS "\e[31mBad build walls int the map !"
# define ERROR_MAP_BAD_ELEMENTS "\e[31mThere is bad elements in the map !"

int		parsing(int ac, char **av, t_data *data);
int		print_error(char *str, char *arg);
int		error_wrong_line(int fd);
int		ft_strlen_whitespace(char *str);
int		parsing_args(int ac, char **av);
int		check_pos_infos(char *line, int textures_collect,
			char infos[6][4], int i);
int		number_len(int nb);
int		get_rgb(char *line, int rgb[3], int i, int j);
int		get_textures(char *line, t_texture *texture, int *textures_collect);
int		get_colors(char *line, int rgb[3], int *colors_collect);
int		get_colors_textures(t_data *data, int textures_collect,
			int colors_collect, int fd);
int		find_player_location(double *x, double *y, t_data *data);
void	recursion_management_init(t_recursion_management *rec_man);
int		check_map(char **map, t_data *data);
char	**copy_map(char **map);
int		free_textures(t_data *data, int textures_collect,
			int colors_collect, int error);
void	*free_arrays(char **copy, int i);
int		check_zero(double *player_x, double *player_y, char **map);
int		check_wrong_chars(char **map);
int		ft_str_arr_len(char **arr);
int		free_all(t_data *data, char **map_cpy);
char	*go_to_map_line(t_data *data, int fd);
int		ft_str_map_width(char **map);
int		free_textures(t_data *data, int textures_collect,
			int colors_collect, int error);
#endif
