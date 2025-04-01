/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:03:03 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/16 16:53:26 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

static char	*ft_strchr_eol(const char *s, int c, int endptr)
{
	while (s && *s && *s != (unsigned char)c)
		s++;
	if (s && (*s || endptr))
		return ((char *)s + (*s != 0));
	return (NULL);
}

static char	*ft_strjoin_f1(char *s1, char const *s2)
{
	char	*result;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = alloc_m((len_s1 + len_s2 + 1) * sizeof(char));
	if (result && s1)
		ft_memcpy(result, s1, len_s1);
	if (result && s2)
		ft_memcpy(result + len_s1, s2, len_s2);
	alloc_f(s1);
	if (result)
		result[len_s1 + len_s2] = 0;
	return (result);
}

static char	*ft_substr_safe(const char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	length;

	if (!s || !len || start >= ft_strlen(s))
		return (NULL);
	length = ft_strlen(s);
	if (len > length)
		len = length;
	result = alloc_m((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_memcpy(result, s + start, len);
	result[len] = 0;
	return (result);
}

static int	ft_read_content(char **prev, int fd)
{
	char	*buf;
	ssize_t	rd_bytes;

	buf = alloc_m((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	rd_bytes = read(fd, buf, BUFFER_SIZE);
	while (rd_bytes > 0)
	{
		buf[rd_bytes] = 0;
		*prev = ft_strjoin_f1(*prev, buf);
		if (!(*prev))
			rd_bytes = -1;
		if (!(*prev) || ft_strchr_eol(*prev, '\n', 0))
			break ;
		rd_bytes = read(fd, buf, BUFFER_SIZE);
	}
	alloc_f(buf);
	return (rd_bytes != -1);
}

char	*get_next_line(int fd)
{
	static char	*content = NULL;
	char		*line;
	char		*end;
	char		*tmp;

	line = NULL;
	tmp = NULL;
	if (fd >= 0 && ft_read_content(&content, fd))
	{
		end = ft_strchr_eol(content, '\n', 1);
		line = ft_substr_safe(content, 0, end - content);
		tmp = ft_substr_safe(end, 0, ft_strlen(end));
	}
	alloc_f(content);
	content = tmp;
	return (line);
}
