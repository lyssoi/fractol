/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:13:40 by soljeong          #+#    #+#             */
/*   Updated: 2023/11/04 11:24:21 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	search_format(char format, va_list ap, int *is_error);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		is_error;
	int		printed_len;

	is_error = 0;
	printed_len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			printed_len += search_format(*str, ap, &is_error);
		}
		else
			printed_len += ft_printf_char(*str, &is_error);
		if (is_error)
			return (ERROR);
		str++;
	}
	return (printed_len);
}

static int	search_format(char format, va_list ap, int *is_error)
{
	if (format == 'c')
		return (ft_printf_char(va_arg(ap, int), is_error));
	else if (format == 's')
		return (ft_printf_string(va_arg(ap, char *), is_error));
	else if (format == 'p')
		return (ft_printf_pointer(va_arg(ap, unsigned long long), is_error));
	else if (format == 'd')
		return (ft_printf_integer(va_arg(ap, int), is_error));
	else if (format == 'i')
		return (ft_printf_integer(va_arg(ap, int), is_error));
	else if (format == 'u')
		return (ft_printf_unsigned_integer(va_arg(ap, unsigned int), is_error));
	else if (format == 'x')
		return (ft_printf_lower_hex(va_arg(ap, unsigned int), is_error));
	else if (format == 'X')
		return (ft_printf_upper_hex(va_arg(ap, unsigned int), is_error));
	else if (format == '%')
		return (ft_printf_char('%', is_error));
	*is_error = 1;
	return (ERROR);
}
