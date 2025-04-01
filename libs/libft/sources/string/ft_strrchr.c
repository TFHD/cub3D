/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:33:34 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/16 16:52:42 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			last = s;
		s++;
	}
	if (!(unsigned char)c)
		last = s;
	return ((char *)last);
}
