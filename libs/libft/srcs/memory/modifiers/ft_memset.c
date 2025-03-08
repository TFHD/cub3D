/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:54:54 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 20:58:47 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void	*ft_memset(void *ptr, uint32_t value, uint32_t size)
{
	uint8_t		*byte_ptr;
	uint32_t	i;

	i = 0;
	byte_ptr = ptr;
	while (size && (uint64_t)byte_ptr & (sizeof(uint64_t) - 1))
	{
		*byte_ptr++ = value;
		size--;
	}
	while (i < size / 8)
	{
		*((uint64_t *)(byte_ptr + i * 8)) = (-1ULL / 255) * value;
		i++;
	}
	while (size)
	{
		*byte_ptr++ = value;
		size--;
	}
	return (ptr);
}
