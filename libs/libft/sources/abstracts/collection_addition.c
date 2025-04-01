/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection_addition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:01:25 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/17 01:22:50 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <collection.h>

static inline bool	collection_realloc(t_collection *col)
{
	uint32_t	prev;

	if (__builtin_expect(col->cap == UINT32_MAX, 0))
		return (false);
	prev = col->cap;
	col->cap <<= 1;
	if (col->cap >> 1 != prev)
		col->cap = UINT32_MAX;
	col->data = ft_realloc(col->data, col->cap * col->mem, prev * col->mem);
	return (col->data != NULL);
}

void	collection_append(t_collection *c, void *ptr)
{
	if (__builtin_expect(!c || !c->data || c->len == UINT32_MAX
			|| (c->len >= c->cap && !collection_realloc(c)), 0))
		return ;
	ft_memmove(c->data + c->len * c->mem, ptr, c->mem);
	c->len++;
}

void	collection_insert(t_collection *c, void *ptr, uint32_t index)
{
	if (__builtin_expect(!c || !c->data || c->len == UINT32_MAX
			|| index > c->len
			|| (c->len >= c->cap && !collection_realloc(c)), 0))
		return ;
	if (index < c->len)
		ft_memmove(c->data + c->mem * (index + 1),
			c->data + c->mem * index,
			c->mem * (c->len - index));
	ft_memmove(c->data + c->mem * index, ptr, c->mem);
	c->len++;
}
