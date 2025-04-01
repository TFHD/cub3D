/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:51:01 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/19 07:07:33 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

bool	ft_isempty(const char *str)
{
	if (!str)
		return (true);
	while (*str && ft_isspace(*str))
		str++;
	return (*str == '\0');
}
