/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:29:48 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 23:07:35 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	handle_string(char *str, t_flags flags, int *total_len)
{
	if (!str && !flags.has_precision)
		str = "(null)";
	else if (!str && flags.has_precision && flags.precision > 5)
		str = "(null)";
	else if (!str && flags.has_precision)
		str = "";
	if (flags.has_precision && flags.width
		&& flags.precision <= (int)ft_strlen(str))
		flags.width += ft_strlen(str) - flags.precision;
	flags.current_flag = 's';
	apply_flags(str, flags, total_len);
}
