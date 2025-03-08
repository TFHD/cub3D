/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:28:25 by albernar          #+#    #+#             */
/*   Updated: 2024/12/16 10:20:58 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	handle_ptr(void *ptr, char spec, t_flags flags, int *total_len)
{
	char	str[21];

	flags.current_flag = spec;
	if (!ptr)
	{
		ft_strlcpy(str, "(nil)", sizeof(str));
		flags.has_precision = 0;
	}
	else
	{
		ft_strlcpy(str, "0x", sizeof(str));
		ft_lltoa_base_buffer((unsigned long)ptr, "0123456789abcdef", str + 2);
	}
	apply_flags(str, flags, total_len);
}
