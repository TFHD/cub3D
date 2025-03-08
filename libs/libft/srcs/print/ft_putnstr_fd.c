/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:57:49 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 23:06:28 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

int	ft_putnstr_fd(char *str, int n, int fd)
{
	int	size;

	if (!str)
		return (0);
	size = ft_strlen(str);
	if (size > n)
		size = n;
	write(fd, str, size);
	return (size);
}
