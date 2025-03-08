/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_memory.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:52:51 by albernar          #+#    #+#             */
/*   Updated: 2024/12/12 19:35:35 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEMORY_H
# define LIBFT_MEMORY_H
# include <stdlib.h>
# include <stdint.h>

// Memory Alloc
void	*ft_calloc(size_t nmenb, size_t size);

// Memory Comparators
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// Memory Free
void	ft_free1d(void *ptr);
void	ft_free2d(void **ptr);

// Memory Modifiers
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *ptr, uint32_t value, uint32_t size);

#endif