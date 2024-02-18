/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:41:05 by soljeong          #+#    #+#             */
/*   Updated: 2023/11/04 11:21:40 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(char c, int *is_error)
{
	if (write(1, &c, 1) < 0)
	{
		*is_error = 1;
		return (WRITE_ERROR);
	}
	return (1);
}
