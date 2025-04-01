/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:04:22 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/16 16:39:11 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

static size_t	ft_separate(char const *s, char c, char **save)
{
	char const	*start;
	size_t		count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		count += *s != 0;
		start = s;
		while (*s && *s != c)
			s++;
		if (!(*start) || !save)
			continue ;
		save[count - 1] = ft_substr(start, 0, s - start);
		if (!save[count - 1])
			return (0);
	}
	return (count);
}

void	ft_split_free(char **s)
{
	char	**start;

	if (__builtin_expect(!s, 0))
		return ;
	start = s;
	while (*s)
		alloc_f(*s++);
	alloc_f(start);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	len;

	if (__builtin_expect(!s, 0))
		return (NULL);
	len = ft_separate(s, c, 0);
	result = alloc_m((len + 1) * sizeof(char *));
	if (__builtin_expect(!result, 0))
		return (NULL);
	result[len] = NULL;
	if (__builtin_expect(ft_separate(s, c, result) == len, 1))
		return (result);
	ft_split_free(result);
	return (NULL);
}
