/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:29:27 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/04 13:13:20 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_prints.h>

int	ft_putnbr_base_fd(uint64_t n, uint8_t base, const char *table, int fd)
{
	int	count;

	count = 1;
	if (n >= base)
		count += ft_putnbr_base_fd(n / base, base, table, fd);
	write(fd, table + (n % base), 1);
	return (count);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = (n >= 0) - (n < 0);
	if (sign < 0)
		ft_putchar_pfd('-', fd);
	ft_putnbr_base_fd((unsigned int)(n * sign), 10, DEC, fd);
}

int	ft_putnbr_pfd(int64_t n, int fd)
{
	int64_t	sign;

	sign = (n >= 0) - (n < 0);
	if (sign < 0)
		ft_putchar_fd('-', fd);
	return (ft_putnbr_base_fd(n * sign, 10, DEC, fd) + (sign < 0));
}
