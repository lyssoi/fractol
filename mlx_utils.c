/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:00:48 by soljeong          #+#    #+#             */
/*   Updated: 2024/02/19 13:56:17 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		pixel;

	pixel = y * data -> line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + pixel;
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
	{
		data->zoom = data->zoom * 0.9;
	}
	if (mousecode == 5)
	{
		data->zoom = data->zoom * 1.1;
	}
	draw_fractol(data);
	return (0);
}

void	my_mlx_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->win = mlx_new_window(data->mlx, 800, 800, "fractol");
	if (!data->win)
		exit(1);
	data->img = mlx_new_image(data->mlx, 800, 800);
	if (!data->img)
		exit(1);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel), \
	&data->line_length, &data->endian);
	if (!data->addr)
		exit(1);
}
