/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:31:57 by mrouves           #+#    #+#             */
/*   Updated: 2025/02/27 00:00:13 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_allocs.h>

static inline void	set_remaining(unsigned char *dptr, int c, size_t n)
{
	while (n--)
		*dptr++ = (unsigned char)c;
}

static inline uint64_t	*set_64bytes(uint64_t *dptr64, int c, size_t blocks)
{
	uint64_t	value;

	value = (unsigned char)c;
	value |= (value << 8);
	value |= (value << 16);
	value |= (value << 32);
	while (blocks--)
	{
		*dptr64++ = value;
		*dptr64++ = value;
		*dptr64++ = value;
		*dptr64++ = value;
		*dptr64++ = value;
		*dptr64++ = value;
		*dptr64++ = value;
		*dptr64++ = value;
	}
	return (dptr64);
}

void	*ft_memset(void *dest, int c, size_t len)
{
	uint64_t		*dptr64;
	size_t			pre_bytes;

	if (__builtin_expect(len < 64, 0))
	{
		set_remaining(dest, c, len);
		return (dest);
	}
	pre_bytes = (8 - ((uintptr_t)dest & 7)) & 7;
	set_remaining((unsigned char *)dest, c, pre_bytes);
	dptr64 = (uint64_t *)((unsigned char *)dest + pre_bytes);
	dptr64 = set_64bytes(dptr64, c, (len - pre_bytes) >> 6);
	set_remaining((unsigned char *)dptr64, c, (len - pre_bytes) & 63);
	return (dest);
}
