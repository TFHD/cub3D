/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_numbers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:14:16 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/25 18:23:04 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_NUMBERS_H
# define LIBFT_NUMBERS_H

# include <libft_allocs.h>
# include <libft_string.h>

char	*ft_itoa(int n);
void	ft_itoa_buf(int n, char buf[static 12]);
int		ft_nbdigits(int n);

#endif
