/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection_deletion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:21:47 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/29 05:15:48 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <collection.h>

void	collection_vanish(t_collection *c, uint32_t index)
{
	if (__builtin_expect(!c || !c->data || index >= c->cap || !c->len, 0))
		return ;
	c->len--;
	if (c->clear.func && c->clear.type == T_STACK)
		c->clear.func(c->data + c->mem * index);
	else if (c->clear.func && *(void **)(c->data + c->mem * index))
		c->clear.func(*(void **)(c->data + c->mem * index));
	ft_memset(c->data + c->mem * index, 0, c->mem);
}

void	collection_rplast(t_collection *c, uint32_t index)
{
	if (__builtin_expect(!c || !c->data || index >= c->len || !c->len, 0))
		return ;
	collection_vanish(c, index);
	if (index < c->len)
		ft_memmove(c->data + c->mem * index, c->data + c->mem * c->len, c->mem);
}

void	collection_remove(t_collection *c, uint32_t index)
{
	if (__builtin_expect(!c || !c->data || index >= c->len || !c->len, 0))
		return ;
	collection_vanish(c, index);
	if (index < c->len)
		ft_memmove(c->data + c->mem * index, c->data + c->mem * (index + 1),
			c->mem * (c->len - index));
	ft_memset(c->data + c->mem * c->len, 0, c->mem);
}
