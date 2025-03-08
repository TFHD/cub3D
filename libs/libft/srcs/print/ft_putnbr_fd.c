/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:03:25 by albernar          #+#    #+#             */
/*   Updated: 2024/12/10 22:37:41 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		count += ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			count += ft_putnbr_fd(n / 10, fd);
		count += ft_putchar_fd(n % 10 + '0', fd);
	}
	return (count);
}
