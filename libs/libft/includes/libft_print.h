/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_print.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:37:53 by albernar          #+#    #+#             */
/*   Updated: 2024/12/12 19:35:38 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINT_H
# define LIBFT_PRINT_H
# include "libft_strings.h"
# include <unistd.h>
# include <stdarg.h>

// Print
int			ft_putchar_fd(char c, int fd);
int			ft_putendl_fd(char *s, int fd);
int			ft_putnbr_fd(int n, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_putnchar_fd(char c, int n, int fd);
int			ft_putnstr_fd(char *str, int n, int fd);

#endif