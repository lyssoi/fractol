/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:21:50 by soljeong          #+#    #+#             */
/*   Updated: 2024/02/19 11:00:01 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double h, double w, t_data *data)
{
	t_com	z;
	t_com	c;
	int		iter;
	double	tmpx;

	z = *data->z;
	c = *data->c;
	iter = 0;
	z.x = (w - WIN_WIDTH / 2) / WIN_WIDTH * (data->zoom) * 4;
	z.y = (h - WIN_HEIGHT / 2) / WIN_HEIGHT * (data->zoom) * 4;
	while ((z.x * z.x) + (z.y * z.y) < 4 && iter < ITERMAX)
	{
		tmpx = (z.x * z.x) - (z.y * z.y);
		z.y = (2 * z.x * z.y) + c.y;
		z.x = tmpx + c.x;
		iter++;
	}
	return (iter);
}

void	julia_init(int argc, char *argv[], t_data *data)
{
	if (argc != 4)
		ft_inputerror();
	data->c->x = ft_atof(argv[2]);
	data->c->y = ft_atof(argv[3]);
	data->fractoltype = T_JULIA;
}
