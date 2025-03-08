/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:52:24 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 20:20:25 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

long long	ft_atoll(const char *str, int *is_overflow)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -sign;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if (result * sign > LLONG_MAX && is_overflow)
			*is_overflow = 1;
		if (result * sign < LLONG_MIN && is_overflow)
			*is_overflow = 1;
		str++;
	}
	return (result * sign);
}
