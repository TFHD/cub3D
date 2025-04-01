/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:38:49 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/14 17:49:14 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	length;

	if (!s || !len || start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	length = ft_strlen(s + start);
	if (len > length)
		len = length;
	result = alloc_m((len + 1) * sizeof(char));
	if (!result)
		return (0);
	ft_memcpy(result, s + start, len);
	result[len] = 0;
	return (result);
}
