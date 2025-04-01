/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection_accessor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:50:02 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/12 02:37:24 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <collection.h>

void	*collection_get(t_collection *c, uint32_t index)
{
	if (__builtin_expect(!c || !c->data || index >= c->len, 0))
		return (NULL);
	return (c->data + c->mem * index);
}

void	collection_set(t_collection *c, uint32_t index, void *ptr)
{
	if (__builtin_expect(!c || !c->data || index >= c->len, 0))
		return ;
	ft_memmove(c->data + c->mem * index, ptr, c->mem);
}

void	collection_replace(t_collection *c, uint32_t index, void *ptr)
{
	if (__builtin_expect(!c || !c->data || index >= c->len, 0))
		return ;
	collection_vanish(c, index);
	c->len++;
	ft_memmove(c->data + c->mem * index, ptr, c->mem);
}

void	collection_iter(t_collection *c, void *arg, t_iter_callb iter)
{
	uint32_t	i;

	if (__builtin_expect(!c || !c->data || !c->len || !iter, 0))
		return ;
	i = -1;
	while (++i < c->len)
		iter(c->data + c->mem * i, arg);
}

void	collection_clear(t_collection *c)
{
	uint32_t	i;

	if (__builtin_expect(!c || !c->data || !c->len, 0))
		return ;
	i = -1;
	while (++i < c->cap)
		collection_vanish(c, i);
}
