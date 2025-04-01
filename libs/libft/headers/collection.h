/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:21:48 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/12 02:36:36 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTION_H
# define COLLECTION_H

# include <libft_allocs.h>
# include <stdbool.h>
# include <stdint.h>

typedef void	(*t_free)(void *);
typedef void	(*t_iter_callb)(void *, void *);

typedef enum e_clear_type
{
	T_HEAP,
	T_STACK,
}	t_clear_type;

typedef struct s_clear_info
{
	t_free			func;
	t_clear_type	type;
}	t_clear_info;

typedef struct s_collection
{
	void			*data;
	t_clear_info	clear;
	uint32_t		mem;
	uint32_t		len;
	uint32_t		cap;
}	t_collection;

t_collection	*collection_create(uint32_t mem, uint32_t cap,
					t_clear_info clear);
bool			collection_init(t_collection *c, uint32_t mem,
					uint32_t cap, t_clear_info clear);

void			collection_destroy(t_collection *c);
void			collection_free(t_collection *c);

void			collection_clear(t_collection *c);
void			*collection_get(t_collection *c, uint32_t i);
void			collection_set(t_collection *c, uint32_t i, void *p);
void			collection_replace(t_collection *c, uint32_t i, void *p);
void			collection_iter(t_collection *c, void *arg, t_iter_callb f);

void			collection_append(t_collection *c, void *p);
void			collection_insert(t_collection *c, void *p, uint32_t i);

void			collection_rplast(t_collection *c, uint32_t i);
void			collection_remove(t_collection *c, uint32_t i);
void			collection_vanish(t_collection *c, uint32_t i);

#endif
