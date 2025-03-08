/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:05:39 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 20:45:24 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurence;

	last_occurence = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			last_occurence = s;
		s++;
	}
	if (!(unsigned char)c)
		return ((char *)s);
	return ((char *)last_occurence);
}
