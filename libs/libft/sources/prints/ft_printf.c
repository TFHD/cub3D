/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:03:06 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/07 00:41:00 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_prints.h>

static int	ft_handle(const char c, va_list args, int fd)
{
	if (c == '%')
		return (ft_putchar_pfd('%', fd));
	if (c == 'c')
		return (ft_putchar_pfd(va_arg(args, int), fd));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_pfd(va_arg(args, int), fd));
	if (c == 's')
		return (ft_putstr_pfd(va_arg(args, char *), fd));
	if (c == 'p')
		return (ft_putptr_pfd(va_arg(args, uintptr_t), fd));
	if (c == 'u')
		return (ft_putnbr_base_fd(va_arg(args, unsigned int), 10, DEC, fd));
	if (c == 'x')
		return (ft_putnbr_base_fd(va_arg(args, unsigned int), 16, LHEX, fd));
	if (c == 'X')
		return (ft_putnbr_base_fd(va_arg(args, unsigned int), 16, UHEX, fd));
	return (-1);
}

static int	ft_percent(const char **format, va_list args, int fd)
{
	int		handled;
	char	next;

	next = (*format)[1];
	handled = ft_handle(next, args, fd);
	if (handled < 0)
		return (ft_putchar_pfd('%', fd));
	(*format)++;
	return (handled);
}

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	int	printed;

	printed = 0;
	while (*format)
	{
		if (*format == '%')
			printed += ft_percent(&format, args, fd);
		else
			printed += ft_putchar_pfd(*format, fd);
		format++;
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;

	if (!format)
		return (-1);
	va_start(args, format);
	printed = ft_vdprintf(1, format, args);
	va_end(args);
	return (printed);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		printed;

	if (!format || fd < 0)
		return (-1);
	va_start(args, format);
	printed = ft_vdprintf(fd, format, args);
	va_end(args);
	return (printed);
}
