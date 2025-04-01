/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:30:55 by mrouves           #+#    #+#             */
/*   Updated: 2024/10/08 18:47:47 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
