/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:01:58 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 22:37:44 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	size;

	if (!s || !fd)
		return (0);
	size = ft_strlen(s);
	write(fd, s, size);
	return (size);
}
