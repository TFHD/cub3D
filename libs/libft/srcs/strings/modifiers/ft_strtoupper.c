/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:34:13 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 20:37:43 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

char	*ft_strtoupper(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
	{
		if (ft_islower(*ptr))
			*ptr = ft_toupper(*ptr);
		ptr++;
	}
	return (str);
}
