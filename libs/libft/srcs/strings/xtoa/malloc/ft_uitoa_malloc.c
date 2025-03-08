/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:17:08 by albernar          #+#    #+#             */
/*   Updated: 2024/12/16 13:17:27 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

char	*ft_uitoa_malloc(unsigned int nbr)
{
	char	*result;

	result = ft_lltoa_base_malloc(nbr, "0123456789");
	return (result);
}
