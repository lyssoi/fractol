/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:45:52 by soljeong          #+#    #+#             */
/*   Updated: 2023/11/04 11:21:57 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_integer(int n, int *is_error)
{
	char	*str;
	int		str_len;

	str = ft_itoa(n);
	if (!str)
	{
		*is_error = 1;
		return (MALLOC_ERROR);
	}
	str_len = 0;
	str_len += ft_printf_string(str, is_error);
	free(str);
	return (str_len);
}
