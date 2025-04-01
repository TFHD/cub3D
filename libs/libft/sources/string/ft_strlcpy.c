/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:32:33 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/25 19:11:44 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*start;
	size_t		index;

	start = src;
	while (*src)
	{
		index = src - start;
		if (size && index < size - 1)
			*dst++ = *src;
		src++;
	}
	if (size)
		*dst = '\0';
	return (src - start);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*tmp_dest;

	tmp_dest = dest;
	while (*src)
		*tmp_dest++ = *src++;
	*tmp_dest = 0;
	return (dest);
}
