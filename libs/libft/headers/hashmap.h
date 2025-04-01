/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:23:11 by mykle             #+#    #+#             */
/*   Updated: 2025/03/12 01:18:34 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include <collection.h>
# include <libft_string.h>

typedef t_collection	t_hmap;

typedef struct s_hmap_bucket
{
	t_collection	keys;
	t_collection	values;
}	t_hmap_bucket;

uint32_t	hash(const char *data, int len);

bool		hmap_init(t_hmap *h, uint32_t cap, size_t mem, t_clear_info clr);
void		*hmap_get(t_hmap *h, const char *key);
void		hmap_unset(t_hmap *h, const char *key);
void		hmap_set(t_hmap *h, const char *key, void *val);
void		hmap_destroy(t_hmap *h);
uint32_t	hmap_len(t_hmap *h);

#endif
