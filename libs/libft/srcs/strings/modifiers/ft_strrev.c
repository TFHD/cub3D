/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:09:41 by albernar          #+#    #+#             */
/*   Updated: 2024/12/16 13:14:08 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strings.h"

void	ft_strrev(char *str)
{
	char	*ptr_start;
	char	*ptr_end;
	char	tmp;

	if (!str)
		return ;
	ptr_start = str;
	ptr_end = str;
	while (*ptr_end)
		ptr_end++;
	ptr_end--;
	while (ptr_start < ptr_end)
	{
		tmp = *ptr_start;
		*ptr_start = *ptr_end;
		*ptr_end = tmp;
		ptr_start++;
		ptr_end--;
	}
}
