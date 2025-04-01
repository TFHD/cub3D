/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_prints.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:35:38 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/07 00:28:44 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTS_H
# define LIBFT_PRINTS_H

# include <stdarg.h>
# include <unistd.h>
# include <libft_string.h>

# define LHEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"
# define DEC "0123456789"

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

int		ft_putchar_pfd(char c, int fd);
int		ft_putnbr_pfd(int64_t n, int fd);
int		ft_putstr_pfd(const char *s, int fd);
int		ft_putptr_pfd(uintptr_t ptr, int fd);
int		ft_putnbr_base_fd(uint64_t n, uint8_t base, const char *table, int fd);

int		ft_vdprintf(int fd, const char *s, va_list ap);
int		ft_dprintf(int fd, const char *s, ...);
int		ft_printf(const char *s, ...);

#endif
