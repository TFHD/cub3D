/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:32:15 by mrouves           #+#    #+#             */
/*   Updated: 2025/02/27 00:00:39 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_allocs.h>

static inline void	*copy_remaining(unsigned char *dptr,
				const unsigned char *sptr, size_t n)
{
	unsigned char	*start;

	start = dptr;
	while (n--)
		*dptr++ = *sptr++;
	return (start);
}

static inline size_t	get_alignement(void *dst, const void *src,
				uint64_t **dptr64, const uint64_t **sptr64)
{
	size_t	pre_bytes;

	pre_bytes = (8 - ((uintptr_t)dst & 7)) & 7;
	copy_remaining(dst, src, pre_bytes);
	*dptr64 = (uint64_t *)((unsigned char *)dst + pre_bytes);
	*sptr64 = (const uint64_t *)((const unsigned char *)src + pre_bytes);
	return (pre_bytes);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	uint64_t		*dptr64;
	const uint64_t	*sptr64;
	size_t			blocks;
	size_t			pre_bytes;

	if (__builtin_expect(n < 64, 0))
		return (copy_remaining(dst, src, n));
	pre_bytes = get_alignement(dst, src, &dptr64, &sptr64);
	blocks = (n - pre_bytes) >> 6;
	while (blocks--)
	{
		*dptr64++ = *sptr64++;
		*dptr64++ = *sptr64++;
		*dptr64++ = *sptr64++;
		*dptr64++ = *sptr64++;
		*dptr64++ = *sptr64++;
		*dptr64++ = *sptr64++;
		*dptr64++ = *sptr64++;
		*dptr64++ = *sptr64++;
	}
	copy_remaining((unsigned char *)dptr64, (const unsigned char *)sptr64,
		(n - pre_bytes) & 63);
	return (dst);
}
