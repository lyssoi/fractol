/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:22:39 by soljeong          #+#    #+#             */
/*   Updated: 2024/02/18 20:23:16 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_init(int argc, t_data *data)
{
	if (argc != 2)
		ft_inputerror();
	data->fractoltype = T_MANDELBROT;
}


int	mandelbrot(double h, double w, t_data*data)
{
	t_com	c;
	t_com	z;
	int		iter;
	double	tmpx;

	iter = 0;
	z.x = 0;
	z.y = 0;
	c.x = (w - WIN_WIDTH/2)/WIN_WIDTH * (data->zoom) * 4;
	c.y = (h - WIN_HEIGHT/2)/WIN_HEIGHT* (data->zoom) * 4;
	while ((z.x * z.x) + (z.y * z.y) < 4 && iter < ITERMAX)
	{
		tmpx = (z.x * z.x) - (z.y * z.y);
		z.y = (2 * z.x * z.y) + c.y;
		z.x = tmpx + c.x;
		iter++;
	}
	return (iter);
}

