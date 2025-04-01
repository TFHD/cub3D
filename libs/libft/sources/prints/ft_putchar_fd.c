/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:22:02 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/04 13:13:00 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_prints.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putchar_pfd(char c, int fd)
{
	return (write(fd, &c, 1) != -1);
}
