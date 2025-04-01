/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:20:19 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/16 16:52:53 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

static int	ft_isset(char const *set, char c)
{
	while (*set && *set != c)
		set++;
	return (*set == c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_isset(set, *s1))
		s1++;
	if (!(*s1))
		return (ft_calloc(1, 1));
	start = s1;
	s1 = start + ft_strlen(start);
	while (s1 > start && ft_isset(set, *s1))
		s1--;
	return (ft_substr(start, 0, s1 - start + 1));
}
