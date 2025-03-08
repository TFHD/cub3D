/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:24:54 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 22:40:01 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	size;

	if (!s)
		return (0);
	size = ft_strlen(s);
	write(fd, s, size);
	write(fd, "\n", 1);
	return (size + 1);
}
