/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 03:28:49 by mykle             #+#    #+#             */
/*   Updated: 2025/03/19 06:00:06 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

static int	count_replacements(const char *orig, const char *rep)
{
	int		count;
	char	*ins;
	int		len_rep;

	if (!orig || !rep)
		return (0);
	len_rep = ft_strlen(rep);
	if (len_rep == 0)
		return (0);
	count = 0;
	ins = ft_strstr(orig, rep);
	while (ins)
	{
		ins += len_rep;
		count++;
		ins = ft_strstr(ins, rep);
	}
	return (count);
}

static char	*replace_all(const char *orig, const char *rep,
				const char *with, char *result)
{
	char	*ins;
	char	*tmp;
	int		len_rep;
	int		len_with;
	int		len_front;

	len_rep = ft_strlen(rep);
	len_with = ft_strlen(with);
	ins = ft_strstr(orig, rep);
	tmp = result;
	while (ins)
	{
		len_front = ins - orig;
		tmp = (char *)ft_memcpy(tmp, orig, len_front) + len_front;
		tmp = (char *)ft_memcpy(tmp, with, len_with) + len_with;
		orig += len_front + len_rep;
		ins = ft_strstr(orig, rep);
	}
	ft_memcpy(tmp, orig, ft_strlen(orig) + 1);
	return (result);
}

char	*ft_strreplace(const char *orig, const char *rep, const char *with)
{
	char	*result;
	int		count;

	count = count_replacements(orig, rep);
	if (!count)
		return ((char *)orig);
	if (!with)
		with = "";
	result = alloc_m(ft_strlen(orig)
			+ (ft_strlen(with) - ft_strlen(rep)) * count + 1);
	if (!result)
		return (NULL);
	return (replace_all(orig, rep, with, result));
}
