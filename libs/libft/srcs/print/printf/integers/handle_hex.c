/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:42:31 by albernar          #+#    #+#             */
/*   Updated: 2024/12/16 10:23:55 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	handle_hex(unsigned int nbr, char spec, t_flags flags, int *total_len)
{
	char	str[21];
	char	*base;

	flags.current_flag = spec;
	base = "0123456789abcdef";
	if (flags.current_flag == 'X')
		base = "0123456789ABCDEF";
	if (nbr == 0 && flags.has_precision && flags.precision == 0)
		str[0] = 0;
	else
		ft_lltoa_base_buffer(nbr, base, str);
	apply_flags(str, flags, total_len);
}
