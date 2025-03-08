/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:29:32 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 23:07:35 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	handle_char(char c, t_flags flags, int *total_len)
{
	char	str[2];

	flags.current_flag = 'c';
	str[0] = c;
	str[1] = 0;
	apply_flags(str, flags, total_len);
}
