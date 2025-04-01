/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:18:14 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/16 21:53:33 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_allocs.h>

#if CACHE_MODE == NO_CACHE

void	*alloc_m(size_t size)
{
	return (malloc(size));
}

void	alloc_f(void *ptr)
{
	free(ptr);
}

#else

void	*alloc_m(size_t size)
{
	if (CACHE_MODE == DC_CACHE)
		return (dc_malloc(size));
	return (sc_malloc(size));
}

void	alloc_f(void *ptr)
{
	if (CACHE_MODE == DC_CACHE)
		dc_free(ptr);
	sc_free(ptr);
}

#endif
