/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:26:30 by mykle             #+#    #+#             */
/*   Updated: 2025/01/21 15:05:09 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

static inline uint32_t	get16bits(const char *data)
{
	return ((((uint32_t)(((const uint8_t *)data)[1])) << 8)
		+ (uint32_t)(((const uint8_t *)data)[0]));
}

static inline uint32_t	shift_rem(const char *data, uint32_t hash, int rem)
{
	if (rem == 3)
	{
		hash += get16bits(data);
		hash ^= hash << 16;
		hash ^= ((signed char)data[sizeof (uint16_t)]) << 18;
		hash += hash >> 11;
	}
	if (rem == 2)
	{
		hash += get16bits(data);
		hash ^= hash << 11;
		hash += hash >> 17;
	}
	if (rem == 1)
	{
		hash += (signed char)*data;
		hash ^= hash << 10;
		hash += hash >> 1;
	}
	return (hash);
}

uint32_t	hash(const char *data, int len)
{
	uint32_t	hash;
	uint32_t	tmp;
	int			rem;

	if (len <= 0 || data == NULL)
		return (0);
	hash = len;
	rem = len & 3;
	len >>= 2;
	while (len--)
	{
		hash += get16bits(data);
		tmp = (get16bits(data + 2) << 11) ^ hash;
		hash = (hash << 16) ^ tmp;
		data += (sizeof(uint16_t) << 1);
		hash += hash >> 11;
	}
	hash = shift_rem(data, hash, rem);
	hash ^= hash << 3;
	hash += hash >> 5;
	hash ^= hash << 4;
	hash += hash >> 17;
	hash ^= hash << 25;
	hash += hash >> 6;
	return (hash);
}
