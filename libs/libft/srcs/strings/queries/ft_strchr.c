/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:02:39 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 20:45:24 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	if (!(unsigned char)c)
		return ((char *)s);
	return (NULL);
}
