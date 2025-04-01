/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:10:44 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/16 16:51:38 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = alloc_m(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len)
		result[i] = f(i, s[i]);
	result[len] = '\0';
	return (result);
}
