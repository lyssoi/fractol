/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:59:12 by soljeong          #+#    #+#             */
/*   Updated: 2024/02/19 11:59:58 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_numerr(void)
{
	ft_printf("Please enter two valid double precision floating-point numbers"
		" after 'julia', (without using the exponent notation 'e')");
	exit(1);
}

int	ft_isspace(int c)
{
	if (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

double	ft_atof(char *str)
{
	double	flag;

	flag = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	if (*str == '\0')
	{
		ft_numerr();
	}
	return ((double)flag * ft_make_double(str));
}

double	ft_make_double(char *str)
{
	double	total;
	double	decimal;

	total = 0L;
	decimal = 0.1L;
	while (ft_isdigit(*str))
		total = total * 10 + *str++ - '0';
	if (*str && !ft_isdigit(*str) && !ft_isdecimalpoint(*str++))
		ft_numerr();
	while (*str && decimal >= 0.000000000000001)
	{
		if (!ft_isdigit(*str))
			ft_numerr();
		total += (*str++ - '0') * decimal;
		decimal *= 0.1;
	}
	return (total);
}

int	ft_isdecimalpoint(char c)
{
	if (c == '.')
		return (1);
	return (0);
}
