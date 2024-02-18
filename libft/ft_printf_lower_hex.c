/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lower_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:26:03 by soljeong          #+#    #+#             */
/*   Updated: 2023/11/04 11:23:55 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_lower_hex(unsigned int n, int *is_error)
{
	char	*str;
	int		str_len;

	str = ft_basetoa((unsigned long long)n, "0123456789abcdef");
	if (!str)
	{
		*is_error = 1;
		return (MALLOC_ERROR);
	}
	str_len = ft_printf_string(str, is_error);
	free(str);
	return (str_len);
}
