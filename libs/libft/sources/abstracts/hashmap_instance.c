/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_instance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:31:15 by mykle             #+#    #+#             */
/*   Updated: 2025/03/06 18:46:21 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hashmap.h>

static void	__bucket_clear(void *ptr)
{
	t_hmap_bucket	*bucket;

	bucket = ptr;
	if (!bucket)
		return ;
	collection_destroy(&bucket->keys);
	collection_destroy(&bucket->values);
}

bool	hmap_init(t_hmap *h, uint32_t cap, size_t mem, t_clear_info info)
{
	static t_clear_info	keys_clr = {alloc_f, T_HEAP};
	static t_clear_info	bckt_clr = {__bucket_clear, T_STACK};
	t_hmap_bucket		*bckt;
	bool				success;

	cap--;
	cap |= cap >> 1;
	cap |= cap >> 2;
	cap |= cap >> 4;
	cap |= cap >> 8;
	cap |= cap >> 16;
	cap++;
	if (__builtin_expect(!h || !cap || !mem, 0))
		return (false);
	success = collection_init(h, sizeof(t_hmap_bucket), cap, bckt_clr);
	while (success && h->len < cap)
	{
		bckt = ((t_hmap_bucket *)h->data) + h->len++;
		success &= collection_init(&bckt->keys, sizeof(void *), 2, keys_clr);
		success &= collection_init(&bckt->values, mem, 2, info);
	}
	if (!success)
		collection_destroy(h);
	return (success);
}

void	hmap_destroy(t_hmap *h)
{
	collection_destroy(h);
}
