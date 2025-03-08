/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:37:42 by albernar          #+#    #+#             */
/*   Updated: 2024/12/16 12:57:11 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

void	ft_lltoa_base_buffer(long long nbr, const char *base, char *str)
{
	const int	base_len = ft_strlen(base);
	const int	is_negative = (nbr < 0);
	char		buffer[21];
	int			i;
	int			j;

	i = 0;
	if (base_len < 2)
		return ;
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
	j = 0;
	while (--i >= 0)
		str[j++] = buffer[i];
	str[j] = 0;
}
