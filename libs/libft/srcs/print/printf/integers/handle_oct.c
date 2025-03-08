/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:42:30 by albernar          #+#    #+#             */
/*   Updated: 2024/12/16 10:21:12 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	handle_oct(unsigned int nbr, char spec, t_flags flags, int *total_len)
{
	char	str[23];
	char	prefixed_str[24];

	flags.current_flag = spec;
	if (nbr == 0 && flags.has_precision && flags.precision == 0)
		str[0] = '\0';
	else
		ft_lltoa_base_buffer(nbr, "01234567", str);
	if (flags.hash && nbr != 0)
	{
		ft_strlcpy(prefixed_str, "0", sizeof(prefixed_str));
		ft_strlcat(prefixed_str, str, sizeof(prefixed_str));
		ft_strlcpy(str, prefixed_str, sizeof(str));
	}
	apply_flags(str, flags, total_len);
}
