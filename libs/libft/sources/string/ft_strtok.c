/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 06:10:25 by mykle             #+#    #+#             */
/*   Updated: 2025/03/14 06:11:03 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

static int	ft_is_delim(char c, const char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*saved;
	char		*token;

	if (str)
		saved = str;
	if (!saved || !*saved)
		return (NULL);
	while (*saved && ft_is_delim(*saved, delim))
		saved++;
	if (!*saved)
		return (NULL);
	token = saved;
	while (*saved && !ft_is_delim(*saved, delim))
		saved++;
	if (*saved)
		*saved++ = '\0';
	else
		saved = NULL;
	return (token);
}
