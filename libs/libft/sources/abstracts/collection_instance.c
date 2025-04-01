/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection_instance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:37:53 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/06 18:41:31 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <collection.h>

static inline bool	collection_fill(t_collection *c, uint32_t mem,
						uint32_t cap, t_clear_info clear)
{
	c->len = 0;
	c->cap = cap;
	c->mem = mem;
	c->clear = clear;
	c->data = ft_calloc(mem, cap);
	return (c->data != NULL);
}

bool	collection_init(t_collection *c, uint32_t mem,
			uint32_t cap, t_clear_info clear)
{
	return (c && mem && cap && collection_fill(c, mem, cap, clear));
}

t_collection	*collection_create(uint32_t mem, uint32_t cap,
					t_clear_info clear)
{
	t_collection	*res;

	res = alloc_m(sizeof(t_collection));
	if (__builtin_expect(mem && cap && res
			&& collection_fill(res, mem, cap, clear), 1))
		return (res);
	alloc_f(res);
	return (NULL);
}

void	collection_destroy(t_collection *c)
{
	uint32_t	i;

	if (__builtin_expect(!c || !c->data, 0))
		return ;
	i = -1;
	while (c->clear.func && ++i < c->cap)
		collection_vanish(c, i);
	alloc_f(c->data);
	ft_memset(c, 0, sizeof(t_collection));
}

void	collection_free(t_collection *c)
{
	if (__builtin_expect(!c || !c->data, 0))
		return ;
	collection_destroy(c);
	alloc_f(c);
}
