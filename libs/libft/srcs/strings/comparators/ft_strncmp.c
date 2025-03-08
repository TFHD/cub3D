/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:33:44 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 20:17:10 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while (n && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
