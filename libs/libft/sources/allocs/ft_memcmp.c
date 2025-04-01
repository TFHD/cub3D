/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:34:02 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/04 13:11:46 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_allocs.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (n && *str1++ == *str2++)
		n--;
	if (n)
		return (*(str1 - 1) - *(str2 - 1));
	return (0);
}
