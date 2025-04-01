/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:34:10 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/17 03:40:13 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

char	*ft_strstr(const char *big, const char *little)
{
	size_t	little_len;
	size_t	big_len;
	size_t	i;

	if (!big || !little || little[0] == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	i = -1;
	while (big[++i] && i <= big_len - little_len)
		if (!ft_strncmp(big + i, little, little_len))
			return ((char *)(big + i));
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	little_len = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	i = -1;
	while (len && big[++i] && little_len <= len && i <= len - little_len)
		if (!ft_strncmp(big + i, little, little_len))
			return ((char *)(big + i));
	return (NULL);
}
