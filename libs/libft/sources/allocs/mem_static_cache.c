/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_static_cache.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:49:42 by mykle             #+#    #+#             */
/*   Updated: 2025/02/27 18:40:43 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_allocs.h>
#include <unistd.h>

static t_mem_static_cache	*cache_get(void)
{
	static t_mem_static_cache	cache = {0};

	return (&cache);
}

__attribute__((destructor))
static void	cache_destroy(void)
{
	t_mem_static_cache	*cache;
	uint32_t			index;

	cache = cache_get();
	index = -1;
	while (++index < CACHE_STATIC_MAX)
	{
		free(cache->allocs[index]);
		cache->allocs[index] = NULL;
	}
	if (CACHE_DEBUG && cache->len)
		write(1, CACHE_CLR_MSG, sizeof(CACHE_CLR_MSG) - 1);
	cache->len = 0;
}

void	*sc_malloc(size_t size)
{
	t_mem_static_cache	*cache;
	void				*ptr;
	size_t				index;

	cache = cache_get();
	if (__builtin_expect(cache->len >= CACHE_STATIC_MAX, 0))
	{
		if (CACHE_DEBUG)
			write(2, CACHE_FULL_MSG, sizeof(CACHE_FULL_MSG));
		exit(1);
	}
	ptr = malloc(size);
	if (__builtin_expect(!ptr, 0))
	{
		if (CACHE_DEBUG)
			write(2, CACHE_FAIL_MSG, sizeof(CACHE_FAIL_MSG));
		exit(1);
	}
	index = ((uintptr_t)ptr) & (CACHE_STATIC_MAX - 1);
	while (cache->allocs[index] != 0)
		index = (index + 1) & (CACHE_STATIC_MAX - 1);
	cache->allocs[index] = ptr;
	cache->len++;
	return (ptr);
}

void	sc_free(void *ptr)
{
	t_mem_static_cache	*cache;
	size_t				index;
	size_t				start;

	cache = cache_get();
	if (__builtin_expect(!ptr || !cache->len, 0))
		return ;
	index = ((uintptr_t)ptr) & (CACHE_STATIC_MAX - 1);
	start = index;
	while (cache->allocs[index] != ptr)
	{
		index = (index + 1) & (CACHE_STATIC_MAX - 1);
		if (index == start)
			return ;
	}
	free(cache->allocs[index]);
	cache->allocs[index] = NULL;
	cache->len--;
}
