/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:29:29 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 20:33:59 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

char	*ft_strtolower(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
	{
		if (ft_isupper(*ptr))
			*ptr = ft_tolower(*ptr);
		ptr++;
	}
	return (str);
}
