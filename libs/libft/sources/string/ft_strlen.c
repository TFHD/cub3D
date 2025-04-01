/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:31:49 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/16 16:51:51 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	if (__builtin_expect(!s, 0))
		return (0);
	ptr = s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}
