/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base_malloc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:00:08 by albernar          #+#    #+#             */
/*   Updated: 2024/12/16 13:14:13 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

char	*ft_lltoa_base_malloc(long long nbr, const char *base)
{
	const int	base_len = ft_strlen(base);
	const int	is_negative = (nbr < 0);
	char		buffer[21];
	int			i;

	i = 0;
	if (base_len < 2)
		return (NULL);
	if (nbr == 0)
		buffer[i++] = base[0];
	while (nbr != 0)
	{
		buffer[i++] = base[ft_llabs(nbr % base_len)];
		nbr /= base_len;
	}
	buffer[i] = 0;
	if (is_negative)
		buffer[i++] = '-';
	ft_strrev(buffer);
	return (ft_strdup(buffer));
}
