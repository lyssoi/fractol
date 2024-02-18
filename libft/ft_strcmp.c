/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:18:20 by soljeong          #+#    #+#             */
/*   Updated: 2024/02/18 17:37:52 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	strlen1;
	int	strlen2;

	strlen1 = ft_strlen(s1);
	strlen2 = ft_strlen(s2);
	if (strlen1 != strlen2)
		return (-1);
	return ft_strncmp(s1, s2, strlen1);
}