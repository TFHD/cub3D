/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:33:55 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/04 13:11:35 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_allocs.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		val;

	str = (const unsigned char *)s;
	val = (unsigned char)c;
	while (n && *str++ != val)
		n--;
	if (n)
		return ((void *)(str - 1));
	return (NULL);
}
