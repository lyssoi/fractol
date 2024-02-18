/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:22:38 by soljeong          #+#    #+#             */
/*   Updated: 2023/11/04 11:22:36 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pointer(unsigned long long n, int *is_error)
{
	char	*hex_str;
	int		str_len;

	hex_str = ft_basetoa(n, "0123456789abcdef");
	if (!hex_str)
	{
		*is_error = 1;
		return (MALLOC_ERROR);
	}
	str_len = ft_printf_string("0x", is_error);
	if (*is_error)
	{
		free(hex_str);
		return (WRITE_ERROR);
	}
	str_len += ft_printf_string(hex_str, is_error);
	free(hex_str);
	return (str_len);
}
