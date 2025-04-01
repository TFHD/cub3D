/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:59:30 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/16 16:57:40 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_prints.h>

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
		ft_putchar_fd(*str++, fd);
}

int	ft_putstr_pfd(const char *s, int fd)
{
	int	len;

	if (!s)
		return (ft_putstr_pfd("(null)", fd));
	len = write(fd, s, ft_strlen(s));
	return (len * (len > 0));
}

int	ft_putptr_pfd(uintptr_t ptr, int fd)
{
	if (!ptr)
		return (ft_putstr_pfd("(nil)", fd));
	return (ft_putstr_pfd("0x", fd) + ft_putnbr_base_fd(ptr, 16, LHEX, fd));
}
