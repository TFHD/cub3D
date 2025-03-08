/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:15:17 by albernar          #+#    #+#             */
/*   Updated: 2024/12/16 13:17:29 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

char	*ft_itoa_malloc(int nbr)
{
	char	*result;

	result = ft_lltoa_base_malloc(nbr, "0123456789");
	return (result);
}
