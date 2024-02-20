/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:24:18 by soljeong          #+#    #+#             */
/*   Updated: 2024/02/19 14:00:13 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	draw_fractol(t_data *data)
{
	int	h;
	int	w;
	int	iter;

	h = 0;
	w = 0;
	while (h <= WIN_HEIGHT)
	{
		w = 0;
		while (w <= WIN_WIDTH)
		{
			if (data->fractoltype == T_JULIA)
				iter = julia((double) h, (double)w, data);
			else if (data->fractoltype == T_MANDELBROT)
				iter = mandelbrot((double)h, (double)w, data);
			my_mlx_pixel_put(data, w, h, ((iter * 18) << 16));
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}

void	ft_inputerror(void)
{
	ft_printf("Please enter 'julia' or 'mandelbrot' as the second argument,"
		" and after 'julia', enter num1 and num2."
		" and do not enter anything else.\n");
	exit(1);
}

void	ft_parse(int argc, char *argv[], t_data *data)
{
	if (argc <= 1)
		ft_inputerror();
	if (argc > 4)
		ft_inputerror();
	if (ft_strcmp(argv[1], "julia") == 0)
		julia_init(argc, argv, data);
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		mandelbrot_init(argc, data);
	else
		ft_inputerror();
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_com	z;
	t_com	c;

	data.z = &z;
	data.c = &c;
	data.zoom = 1;
	ft_parse(argc, argv, &data);
	my_mlx_init(&data);
	draw_fractol(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 17, 0, exit_hook, 0);
	mlx_loop(data.mlx);
	return (0);
}
