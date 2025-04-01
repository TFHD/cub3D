/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:32:59 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/25 19:11:11 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dst_length;
	size_t		src_length;
	char		*ptr;

	if ((!dst || !src) && !size)
		return (size);
	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (size <= dst_length)
		return (size + src_length);
	ptr = dst + dst_length;
	while (*src && (size_t)(ptr - dst) < size - 1)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dst_length + src_length);
}

char	*ft_strcat(char *dst, const char *src)
{
	char	*tmp_dst;

	tmp_dst = dst;
	while (*tmp_dst)
		tmp_dst++;
	while (*src)
		*tmp_dst++ = *src++;
	*tmp_dst = 0;
	return (dst);
}
