/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:22:57 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 20:29:23 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*tmp_src;
	size_t		i;

	if (!dst || !src)
		return (0);
	i = 0;
	tmp_src = src;
	if (size)
	{
		while (*tmp_src && i++ < (size - 1))
			*dst++ = *tmp_src++;
		*dst = 0;
	}
	tmp_src = src;
	while (*tmp_src)
		tmp_src++;
	return (tmp_src - src);
}
