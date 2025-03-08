/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:30:36 by albernar          #+#    #+#             */
/*   Updated: 2024/12/16 10:23:51 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	handle_number(long nbr, char spec, t_flags flags, int *total_len)
{
	char	str[21];

	flags.current_flag = spec;
	if (nbr == 0 && flags.has_precision && flags.precision == 0)
		str[0] = 0;
	else
	{
		if (flags.current_flag == 'd' || flags.current_flag == 'i')
			ft_itoa_buffer(nbr, str);
		else if (flags.current_flag == 'u')
			ft_uitoa_buffer(nbr, str);
	}
	apply_flags(str, flags, total_len);
}
