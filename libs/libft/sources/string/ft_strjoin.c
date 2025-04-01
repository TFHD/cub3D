/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:56:45 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/17 22:01:45 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = alloc_m((len_s1 + len_s2 + 1) * sizeof(char));
	if (result && s1)
		ft_memcpy(result, s1, len_s1);
	if (result && s2)
		ft_memcpy(result + len_s1, s2, len_s2);
	if (result)
		result[len_s1 + len_s2] = 0;
	return (result);
}

char	*ft_strjoin_f(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	alloc_f(s1);
	alloc_f(s2);
	return (result);
}

char	*ft_strjoins(const char **strings, int n, const char *sep)
{
	char	*result;
	int		i;
	int		len;
	int		sep_len;

	len = 1;
	i = -1;
	if (!strings || !sep || n <= 0)
		return (NULL);
	sep_len = ft_strlen(sep);
	while (++i < n)
		len += ft_strlen(strings[i]);
	len += sep_len * (n - 1);
	result = ft_calloc(len, sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < n)
	{
		if (strings[i])
			ft_strlcat(result, strings[i], len);
		if (i < n - 1)
			ft_strlcat(result, sep, len);
	}
	return (result);
}

char	*ft_strjoins_f(char **strings, int n, const char *sep)
{
	char	*result;

	result = ft_strjoins((const char **)strings, n, sep);
	while (n--)
		alloc_f(strings[n]);
	return (result);
}
