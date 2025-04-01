/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:34:18 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/19 14:16:45 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

int	ft_atoi(const char *s)
{
	int	result;
	int	sign;

	result = 0;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	sign = (*s != '-') - (*s == '-');
	s += (*s == '-' || *s == '+');
	while (ft_isdigit(*s))
		result = (result << 3) + (result << 1) + (*s++) - '0';
	return (result * sign);
}

bool	ft_safe_atoi(const char *s, int32_t	*out)
{
	int8_t		sign;
	uint64_t	convert;

	if (__builtin_expect(!out || !s || !(*s), 0))
		return (false);
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	sign = (*s != '-') - (*s == '-');
	s += sign < 0;
	if (!ft_safe_atou64(s, &convert) || convert - (sign < 0) > INT32_MAX)
		return (false);
	*out = convert * sign;
	return (true);
}

bool	ft_safe_atoi64(const char *s, int64_t	*out)
{
	int8_t		sign;
	uint64_t	convert;

	if (__builtin_expect(!out || !s || !(*s), 0))
		return (false);
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	sign = (*s != '-') - (*s == '-');
	s += (*s == '-');
	if (!ft_safe_atou64(s, &convert) || convert - (sign < 0) > INT64_MAX)
		return (false);
	*out = convert * sign;
	return (true);
}

bool	ft_safe_atou64(const char *s, uint64_t *out)
{
	uint64_t	overflow;

	if (__builtin_expect(!out || !s || !(*s), 0))
		return (false);
	*out = 0;
	s += (*s == '+');
	if (!(*s))
		return (false);
	while (*s)
	{
		overflow = (*out << 3) + (*out << 1) + (*s - '0');
		if (!ft_isdigit(*s++) || overflow < *out)
			return (false);
		*out = overflow;
	}
	return (true);
}
