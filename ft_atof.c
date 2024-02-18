/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:59:12 by soljeong          #+#    #+#             */
/*   Updated: 2024/02/18 19:06:52 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

void ft_numerr()
{
	ft_printf("Please enter two valid double precision floating-point numbers after 'julia', (without using the exponent notation 'e')");
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
	double	d_total;
	double	d_temp;
	int		i;
	int		flag;

	d_total = 0;
	d_temp = 0;
	i = 0;
	flag = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			flag = -1;
	}
	if (!str[i]){
		ft_numerr();
	}
	while(str[i]){
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '.')
			{
				d_temp = 0.1;
			}
			else
				ft_numerr();
		}
		else if (d_temp == 0){
			d_total *= 10;
			d_total += str[i] - '0';
		}else if (d_temp >= 0.000000000000001){
			d_total += (str[i] - '0') * d_temp;
			d_temp *= 0.1;
		}
		i++;
	}
	return (flag * d_total);
}

// int main(int argc, char *argv[]){
// 	if (argc < 1)
// 		return 0;
// 	double f = ft_atof(argv[1]);
// 	printf("%.16f",f);
// 	return 0;
// }