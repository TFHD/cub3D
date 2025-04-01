/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_accessor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:22:48 by mykle             #+#    #+#             */
/*   Updated: 2025/03/12 01:17:58 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hashmap.h>

static inline uint32_t	hmap_query(t_hmap *h, const char *key,
							t_collection **keys, t_collection **vals)
{
	uint32_t		index;

	index = hash(key, ft_strlen(key)) & (h->cap - 1);
	*keys = &(((t_hmap_bucket *)h->data) + index)->keys;
	*vals = &(((t_hmap_bucket *)h->data) + index)->values;
	index = 0;
	while (index < (*keys)->len && ft_strcmp(
			*((char **)(*keys)->data + index), key))
		index++;
	return (index);
}

void	*hmap_get(t_hmap *h, const char *key)
{
	t_collection	*vals;
	t_collection	*keys;
	uint32_t		index;

	if (__builtin_expect(!h || !key, 0))
		return (NULL);
	index = hmap_query(h, key, &keys, &vals);
	if (__builtin_expect(index < vals->len, 1))
		return (vals->data + vals->mem * index);
	return (NULL);
}

void	hmap_set(t_hmap *h, const char *key, void *val)
{
	t_collection	*vals;
	t_collection	*keys;
	uint32_t		index;

	if (__builtin_expect(!h || !key, 0))
		return ;
	index = hmap_query(h, key, &keys, &vals);
	if (index >= vals->len)
	{
		collection_append(vals, val);
		collection_append(keys, &((char *){ft_strdup(key)}));
	}
	else
		collection_replace(vals, index, val);
}

void	hmap_unset(t_hmap *h, const char *key)
{
	t_collection	*vals;
	t_collection	*keys;
	uint32_t		index;

	if (__builtin_expect(!h || !key, 0))
		return ;
	index = hmap_query(h, key, &keys, &vals);
	if (index < vals->len)
	{
		collection_rplast(keys, index);
		collection_rplast(vals, index);
	}
}

uint32_t	hmap_len(t_hmap *h)
{
	uint32_t		i;
	uint32_t		len;

	if (__builtin_expect(!h, 0))
		return (0);
	len = 0;
	i = -1;
	while (++i < h->cap)
		len += ((t_hmap_bucket *)h->data + i)->keys.len;
	return (len);
}
