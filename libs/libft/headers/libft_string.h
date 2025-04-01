/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:39:01 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/25 19:11:09 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H

# include <libft_allocs.h>
# include <unistd.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int		ft_isalpha(int c);
int		ft_isspace(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

int		ft_atoi(const char *nptr);
bool	ft_safe_atoi(const char *s, int32_t *out);
bool	ft_safe_atou64(const char *s, uint64_t *out);
bool	ft_safe_atoi64(const char *s, int64_t	*out);

char	*get_next_line(int fd);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
char	*ft_strjoin_f(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strremove_f(char *str, const char *charset);
char	*ft_strremove(const char *str, const char *charset);
char	*ft_strjoins_f(char **strings, int n, const char *sep);
char	*ft_strjoins(const char **strings, int n, const char *sep);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strreplace(const char *orig, const char *rep, const char *with);
void	ft_split_free(char **split);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strtok(char *str, const char *delim);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
bool	ft_isempty(const char *str);

#endif
