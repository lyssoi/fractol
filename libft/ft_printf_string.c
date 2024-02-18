/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:19:50 by soljeong          #+#    #+#             */
/*   Updated: 2023/11/04 11:23:10 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_string(char *string, int *is_error)
{
	int	str_len;

	if (!string)
	{
		if (write(1, "(null)", 6) < 0)
			*is_error = 1;
		return (6);
	}
	str_len = ft_strlen(string);
	if (write(1, string, str_len) < 0)
		*is_error = 1;
	return (str_len);
}
