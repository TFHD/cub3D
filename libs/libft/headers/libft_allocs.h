/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_allocs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:31:30 by mrouves           #+#    #+#             */
/*   Updated: 2025/02/27 18:39:57 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ALLOCS_H
# define LIBFT_ALLOCS_H

# include <stdlib.h>
# include <stdint.h>

# ifndef CACHE_DEBUG
#  define CACHE_DEBUG 0
# endif

# ifndef CACHE_STATIC_MAX
#  define CACHE_STATIC_MAX 0x10000
# endif

# ifndef CACHE_DYNAMIC_MAX
#  define CACHE_DYNAMIC_INIT 0x100
# endif

# define CACHE_FULL_MSG "Warning: static cache full, exiting safely...\n"
# define CACHE_FAIL_MSG "Warning: malloc failed, exiting safely...\n"
# define CACHE_CLR_MSG "Warning: cache automatic clear raised\n"

# define NO_CACHE 0
# define DC_CACHE 1
# define SC_CACHE 2
# ifndef CACHE_MODE
#  define CACHE_MODE 0
# endif

typedef struct s_mem_dynamic_cache
{
	void		**allocs;
	uint32_t	cap;
	uint32_t	len;
}	t_mem_dynamic_cache;

typedef struct s_mem_static_cache
{
	void		*allocs[CACHE_STATIC_MAX];
	uint32_t	len;
}	t_mem_static_cache;

void	*alloc_m(size_t size);
void	alloc_f(void *ptr);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *ptr, size_t nsize, size_t osize);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*sc_malloc(size_t size);
void	*dc_malloc(size_t size);
void	sc_free(void *ptr);
void	dc_free(void *ptr);

#endif
