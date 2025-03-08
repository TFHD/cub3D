/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:45:18 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 20:55:24 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	result;

	result = 0;
	while (n && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n)
		result = (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (result);
}
