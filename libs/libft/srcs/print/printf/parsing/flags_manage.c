/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:53:30 by albernar          #+#    #+#             */
/*   Updated: 2024/12/16 12:57:28 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	calculate_padding_size(t_flags flags, int size, char *str)
{
	int	padding_size;

	if (flags.current_flag == 'c')
	{
		padding_size = flags.width - 1;
		if (padding_size < 0)
			padding_size = 0;
		return (padding_size);
	}
	padding_size = flags.width - size;
	if (flags.has_precision && flags.current_flag != 's'
		&& flags.current_flag != 'c')
		if (flags.precision > size)
			padding_size = flags.width - flags.precision;
	if (flags.current_flag == 'd' || flags.current_flag == 'i'
		|| flags.current_flag == 'u' || flags.current_flag == 'x'
		|| flags.current_flag == 'X' || flags.current_flag == 'o')
		if (str[0] == '-' || flags.plus || flags.space)
			padding_size--;
	if ((flags.current_flag == 'x' || flags.current_flag == 'X') && flags.hash
		&& *str != '0')
		padding_size -= 2;
	if (padding_size < 0)
		padding_size = 0;
	return (padding_size);
}

static void	handle_di_flag(char **str, t_flags flags, int *total_len, int *sign)
{
	if (**str == '-' || flags.plus || flags.space)
		*sign = 1;
	if (**str == '-')
	{
		*total_len += ft_putchar_fd('-', flags.fd);
		(*str)++;
	}
	else if (flags.plus)
		*total_len += ft_putchar_fd('+', flags.fd);
	else if (flags.space)
		*total_len += ft_putchar_fd(' ', flags.fd);
}

int	handle_sign_and_prefix(char **str, t_flags flags, int *total_len)
{
	int	sign;

	sign = 0;
	if (flags.current_flag == 'd' || flags.current_flag == 'i')
		handle_di_flag(str, flags, total_len, &sign);
	else if (flags.current_flag == 'p')
		*total_len += ft_putstr_fd("0x", flags.fd);
	else if ((flags.current_flag == 'x' || flags.current_flag == 'X')
		&& flags.hash && **str != '0')
	{
		if (flags.current_flag == 'x')
			*total_len += ft_putstr_fd("0x", flags.fd);
		else
			*total_len += ft_putstr_fd("0X", flags.fd);
	}
	else if (flags.current_flag == 'o' && flags.hash && **str != '0')
		*total_len += ft_putchar_fd('0', flags.fd);
	return (sign);
}

int	calculate_precision_zeros(t_flags flags, int size)
{
	if (flags.has_precision && flags.current_flag != 's'
		&& flags.current_flag != 'c')
		if (flags.precision > size)
			return (flags.precision - size);
	return (0);
}

int	handle_output(char *str, t_flags flags)
{
	int	len;

	len = 0;
	if (flags.current_flag == 'c')
		len += ft_putchar_fd(*str, flags.fd);
	else if (flags.current_flag == 's')
	{
		if (flags.has_precision)
			len += ft_putnstr_fd(str, flags.precision, flags.fd);
		else
			len += ft_putstr_fd(str, flags.fd);
	}
	else if (flags.current_flag == 'p')
		len += ft_putstr_fd(str, flags.fd);
	else if (flags.current_flag == 'd' || flags.current_flag == 'i'
		|| flags.current_flag == 'u' || flags.current_flag == 'x'
		|| flags.current_flag == 'X' || flags.current_flag == 'o')
		len += ft_putstr_fd(str, flags.fd);
	return (len);
}
