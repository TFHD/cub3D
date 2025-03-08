/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:49:14 by albernar          #+#    #+#             */
/*   Updated: 2024/12/16 10:22:27 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

void	ft_uitoa_buffer(unsigned int nbr, char *buffer)
{
	ft_lltoa_base_buffer(nbr, "0123456789", buffer);
}
