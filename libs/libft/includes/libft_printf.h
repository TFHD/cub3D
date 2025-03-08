/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:04:25 by albernar          #+#    #+#             */
/*   Updated: 2025/01/31 03:57:22 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H
# include "libft_print.h"

typedef struct s_flags
{
	char	current_flag;
	int		fd;
	int		left_align;
	int		zero_pad;
	int		width;
	int		precision;
	int		has_precision;
	int		hash;
	int		space;
	int		plus;
}			t_flags;

// ft_printf
int			ft_vprintf(int fd, const char *format, va_list args);
int			ft_dprintf(int fd, const char *format, ...);
int			ft_printf(const char *format, ...);

// Flags
void		apply_flags(char *str, t_flags flags, int *total_len);
void		parse_flags(const char **format, t_flags *flags, va_list args);
int			handle_output(char *str, t_flags flags);
int			calculate_precision_zeros(t_flags flags, int size);
int			handle_sign_and_prefix(char **str, t_flags flags, int *total_len);
int			calculate_padding_size(t_flags flags, int size, char *str);

// Conversions
void		handle_char(char c, t_flags flags, int *total_len);
void		handle_string(char *str, t_flags flags, int *total_len);
void		handle_number(long nbr, char spec, t_flags flags, int *total_len);
void		handle_ptr(void *ptr, char spec, t_flags flags, int *total_len);
void		handle_hex(unsigned int nbr, char spec, t_flags flags,
				int *total_len);
void		handle_oct(unsigned int nbr, char spec, t_flags flags,
				int *total_len);

#endif