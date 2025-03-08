/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:18:31 by albernar          #+#    #+#             */
/*   Updated: 2024/12/12 19:31:13 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp_dest;
	char	*dest;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (!len)
		start = 0;
	if (ft_strlen(s) < len + start)
		len = ft_strlen(s + start);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	s += start;
	tmp_dest = dest;
	while (*s && len--)
		*tmp_dest++ = *s++;
	*tmp_dest = 0;
	return (dest);
}
