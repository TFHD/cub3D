/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:47:36 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 20:20:39 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

unsigned int	ft_atoui(const char *str, int *is_overflow)
{
	long long	result;

	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-' && is_overflow)
			*is_overflow = -1;
	if (is_overflow && *is_overflow == -1)
		return (0);
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if (result > UINT_MAX && is_overflow)
			*is_overflow = 1;
		str++;
	}
	return (result);
}
