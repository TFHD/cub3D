/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:15:49 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 20:54:16 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_dest;
	const unsigned char	*tmp_src;

	if (!dest && !src)
		return (NULL);
	tmp_dest = dest;
	tmp_src = src;
	while (n--)
		*tmp_dest++ = *tmp_src++;
	return (dest);
}
