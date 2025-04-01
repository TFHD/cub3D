/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:56:57 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/17 00:25:21 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_allocs.h>

void	*ft_realloc(void *ptr, size_t new_size, size_t old_size)
{
	void	*result;

	if (__builtin_expect(!ptr, 0))
		return (alloc_m(new_size));
	if (__builtin_expect(old_size >= new_size, 0))
		return (ptr);
	result = alloc_m(new_size);
	if (__builtin_expect(result != NULL, 1))
	{
		ft_memset(result + old_size, 0, new_size - old_size);
		ft_memmove(result, ptr, old_size);
	}
	alloc_f(ptr);
	return (result);
}
