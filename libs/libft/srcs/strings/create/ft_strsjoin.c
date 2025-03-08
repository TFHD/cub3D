/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:09:28 by albernar          #+#    #+#             */
/*   Updated: 2024/12/12 19:31:13 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"
#include <stdarg.h>

static int	ft_strslen(int strs_count, va_list strs)
{
	va_list	strs_copy;
	char	*current_str;
	int		total_len;

	total_len = 0;
	va_copy(strs_copy, strs);
	while (strs_count-- > 0)
	{
		current_str = va_arg(strs_copy, char *);
		if (current_str)
			total_len += ft_strlen(current_str);
	}
	va_end(strs_copy);
	return (total_len);
}

static void	ft_strsfree(int free_flag, int strs_count, va_list strs)
{
	va_list	strs_copy;
	char	*current_str;
	int		i;

	i = -1;
	va_copy(strs_copy, strs);
	while (++i < strs_count)
	{
		current_str = va_arg(strs, char *);
		if (free_flag & (1 << (strs_count - 1 - i)) && current_str != NULL)
			free(current_str);
	}
	va_end(strs_copy);
}

char	*ft_strsjoin(int free_flag, int strs_count, ...)
{
	va_list	strs;
	int		i;
	char	*result;
	char	*current_str;

	va_start(strs, strs_count);
	result = malloc(sizeof(char) * (ft_strslen(strs_count, strs) + 1));
	if (result)
	{
		*result = 0;
		i = -1;
		va_start(strs, strs_count);
		while (++i < strs_count)
		{
			current_str = va_arg(strs, char *);
			if (current_str)
				ft_strcat(result, current_str);
		}
	}
	va_start(strs, strs_count);
	ft_strsfree(free_flag, strs_count, strs);
	va_end(strs);
	return (result);
}
