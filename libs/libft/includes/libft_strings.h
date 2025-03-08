/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strings.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:17:19 by albernar          #+#    #+#             */
/*   Updated: 2024/12/16 13:17:48 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRINGS_H
# define LIBFT_STRINGS_H
# include "libft_memory.h"
# include "libft_maths.h"
# include <limits.h>
# include <stdlib.h>

// ATOX FUNCTIONS
int				ft_atoi(const char *str, int *is_overflow);
long long		ft_atoll(const char *str, int *is_overflow);
unsigned int	ft_atoui(const char *str, int *is_overflow);

// COMPARATORS
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_iswhitespace(char c);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

// CREATE
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char const *s1, char const *s2,
					int free_s1, int free_s2);
char			*ft_strsjoin(int free_flag, int strs_count, ...);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);

// MODIFIERS
char			*ft_strcat(char *dst, char *src);
char			*ft_strcpy(char *dest, const char *src);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t n);
void			ft_strrev(char *str);
char			*ft_strtolower(char *str);
char			*ft_strtoupper(char *str);
int				ft_tolower(int c);
int				ft_toupper(int c);

// QUERIES
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(char *str, char *to_find);

// XTOA FUNCTIONS
void			ft_itoa_buffer(int nbr, char *buffer);
void			ft_lltoa_base_buffer(long long nbr, const char *base,
					char *str);
void			ft_uitoa_buffer(unsigned int nbr, char *buffer);
char			*ft_itoa_malloc(int nbr);
char			*ft_lltoa_base_malloc(long long nbr, const char *base);
char			*ft_uitoa_malloc(unsigned int nbr);

char	*get_next_line(int fd);

#endif
