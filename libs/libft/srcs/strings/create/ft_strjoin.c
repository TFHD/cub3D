/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:45:36 by albernar          #+#    #+#             */
/*   Updated: 2024/12/12 19:31:13 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

char	*ft_strjoin(char const *s1, char const *s2, int free_s1, int free_s2)
{
	char	*dest;

	free_s1 = !!s1 * free_s1;
	free_s2 = !!s2 * free_s2;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	dest = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	ft_strlcat(dest, s1, ft_strlen(s1) + 1);
	ft_strlcat(dest, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	if (free_s1)
		free((char *)s1);
	if (free_s2)
		free((char *)s2);
	return (dest);
}
