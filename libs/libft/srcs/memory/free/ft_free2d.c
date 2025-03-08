/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:04:46 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 21:06:58 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void	ft_free2d(void **ptr)
{
	void	**tmp_ptr;

	tmp_ptr = ptr;
	while (tmp_ptr && *tmp_ptr)
		free(*tmp_ptr++);
	if (ptr)
		free(ptr);
}
