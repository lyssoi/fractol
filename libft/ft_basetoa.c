/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basetoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:45:55 by soljeong          #+#    #+#             */
/*   Updated: 2023/11/04 11:11:30 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_basetoa_len(unsigned long long n, int base_len);

char	*ft_basetoa(unsigned long long n, char *base)
{
	char	*str;
	int		base_len;
	int		idx;

	if (n == 0)
		return (ft_strdup("0"));
	base_len = ft_strlen(base);
	idx = ft_basetoa_len(n, base_len);
	str = (char *)malloc(sizeof(char) * (idx + 1));
	if (!str)
		return (NULL);
	str[idx] = '\0';
	while (n > 0)
	{
		str[--idx] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}

static int	ft_basetoa_len(unsigned long long n, int base_len)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base_len;
		len++;
	}
	return (len);
}
