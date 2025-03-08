/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:28:13 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 20:17:10 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	if (!str1 || !str2)
		return (1);
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
