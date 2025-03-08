/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:45:30 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 20:29:23 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;

	if (!src)
		return (size);
	if (!dst)
		return (size + ft_strlen(src));
	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	if (size <= dest_len)
		return (size + src_len);
	dst += dest_len;
	while (*src && (dest_len + i++) < (size - 1))
		*dst++ = *src++;
	*dst = 0;
	return (src_len + dest_len);
}
