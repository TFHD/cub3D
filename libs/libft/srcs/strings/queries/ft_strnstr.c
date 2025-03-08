/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:50:23 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 20:45:24 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*tmp_big;
	const char	*tmp_little;
	size_t		rlen;

	if (!little || !big)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (len && *big)
	{
		tmp_big = big;
		tmp_little = little;
		rlen = len;
		while (*tmp_big && *tmp_little && *tmp_big == *tmp_little && rlen)
		{
			tmp_big++;
			tmp_little++;
			rlen--;
		}
		if (!*tmp_little)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
