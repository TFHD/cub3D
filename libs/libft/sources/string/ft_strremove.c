/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 06:06:57 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/19 06:14:50 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

static char	*filter_chars(const char *str, const char *charset)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(str);
	result = alloc_m(len + 1);
	if (!result)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < len)
		if (!ft_strchr(charset, str[i]))
			result[j++] = str[i];
	result[j] = '\0';
	return (result);
}

char	*ft_strremove(const char *str, const char *charset)
{
	if (__builtin_expect(!str, 0))
		return (NULL);
	if (!charset || charset[0] == '\0')
		return (ft_strdup(str));
	return (filter_chars(str, charset));
}

char	*ft_strremove_f(char *str, const char *charset)
{
	char	*result;

	result = ft_strremove(str, charset);
	alloc_f(str);
	return (result);
}
