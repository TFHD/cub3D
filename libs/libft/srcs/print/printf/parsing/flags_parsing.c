/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:51:36 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 23:07:35 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void	init_flags(t_flags *flags)
{
	flags->current_flag = 0;
	flags->left_align = 0;
	flags->zero_pad = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->has_precision = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
}

static void	parse_width(const char **format, t_flags *flags, va_list args)
{
	if (**format >= '0' && **format <= '9')
	{
		flags->width = ft_atoi(*format, NULL);
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}
	else if (**format == '*')
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->left_align = 1;
			flags->width = -flags->width;
		}
		(*format)++;
	}
}

static void	parse_precision(const char **format, t_flags *flags, va_list args)
{
	if (**format == '.')
	{
		(*format)++;
		flags->has_precision = 1;
		if (**format >= '0' && **format <= '9')
		{
			flags->precision = ft_atoi(*format, NULL);
			while (**format >= '0' && **format <= '9')
				(*format)++;
		}
		else if (**format == '*')
		{
			flags->precision = va_arg(args, int);
			if (flags->precision < 0)
				flags->has_precision = 0;
			(*format)++;
		}
	}
}

void	parse_flags(const char **format, t_flags *flags, va_list args)
{
	init_flags(flags);
	while (**format == '-' || **format == '0' || **format == '#'
		|| **format == '+' || **format == ' ')
	{
		if (**format == '-')
			flags->left_align = 1;
		else if (**format == '0')
			flags->zero_pad = 1;
		else if (**format == '#')
			flags->hash = 1;
		else if (**format == '+')
			flags->plus = 1;
		else if (**format == ' ')
			flags->space = 1;
		(*format)++;
	}
	parse_width(format, flags, args);
	parse_precision(format, flags, args);
}

void	apply_flags(char *str, t_flags flags, int *total_len)
{
	int	size;
	int	padding_size;
	int	precision_zeros;

	size = ft_strlen(str);
	if (*str == '-' && flags.current_flag != 's')
		size--;
	precision_zeros = calculate_precision_zeros(flags, size);
	padding_size = calculate_padding_size(flags, size + precision_zeros, str);
	if (!flags.left_align && (!flags.zero_pad || flags.has_precision))
		*total_len += ft_putnchar_fd(' ', padding_size, flags.fd);
	if (*str == '-' || flags.plus || flags.space || flags.hash)
		handle_sign_and_prefix(&str, flags, total_len);
	if (flags.zero_pad && !flags.left_align && !flags.has_precision)
		*total_len += ft_putnchar_fd('0', padding_size, flags.fd);
	if (flags.has_precision)
		*total_len += ft_putnchar_fd('0', precision_zeros, flags.fd);
	*total_len += handle_output(str, flags);
	if (flags.left_align)
		*total_len += ft_putnchar_fd(' ', padding_size, flags.fd);
}
