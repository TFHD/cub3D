/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:48:50 by albernar          #+#    #+#             */
/*   Updated: 2024/12/12 19:31:13 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

char	*ft_strdup(const char *src)
{
	const char	*new_src;
	char		*dest;

	if (!src)
		return (NULL);
	new_src = src;
	while (*new_src)
		new_src++;
	dest = malloc(sizeof(char) * (new_src - src + 1));
	if (!dest)
		return (NULL);
	new_src = dest;
	while (*src)
		*dest++ = *src++;
	*dest = 0;
	return ((char *)new_src);
}
