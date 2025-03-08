/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:51:11 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 20:45:24 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

char	*ft_strstr(char *str, char *to_find)
{
	if (!str || !to_find)
		return (NULL);
	if (!*to_find)
		return (str);
	while (*str)
	{
		while (*str && *to_find && *str == *to_find)
		{
			str++;
			to_find++;
		}
		if (!*to_find)
			return (&(*str));
		str++;
	}
	return (NULL);
}
