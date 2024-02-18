/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:59:35 by soljeong          #+#    #+#             */
/*   Updated: 2024/02/08 14:59:55 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ERROR -1
# define WRITE_ERROR 0
# define MALLOC_ERROR 0
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
char	*ft_basetoa(unsigned long long n, char *base);
int		ft_printf_char(char c, int *is_error);
int		ft_printf_integer(int n, int *is_error);
int		ft_printf_lower_hex(unsigned int n, int *is_error);
int		ft_printf_unsigned_integer(unsigned int n, int *is_error);
int		ft_printf_string(char *string, int *is_error);
int		ft_printf_upper_hex(unsigned int n, int *is_error);
int		ft_printf_pointer(unsigned long long n, int *is_error);

#endif