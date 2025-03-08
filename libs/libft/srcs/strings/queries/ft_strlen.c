/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:50:33 by albernar          #+#    #+#             */
/*   Updated: 2025/01/31 04:06:26 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

size_t	ft_strlen(const char *s)
{
	const char	*tmp;

	if (!s)
		return (0);
	tmp = s;
	while (*tmp)
		tmp++;
	return (tmp - s);
}
