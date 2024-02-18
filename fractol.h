/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:57:57 by soljeong          #+#    #+#             */
/*   Updated: 2024/02/18 20:23:01 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include "libft/libft.h"
#define WIN_WIDTH 800
#define WIN_HEIGHT 800
#define ITERMAX 100
#define T_JULIA 1
#define T_MANDELBROT 2

typedef struct s_com
{
	double	x;
	double	y;
}	t_com;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fractoltype;
	double	zoom;
	t_com	*z;
	t_com	*c;
}	t_data;

int julia(double h, double w, t_data *data);
int	mandelbrot(double h, double w, t_data*data);
int draw_fractol(t_data *data);
int exit_hook(void);
void ft_inputerror();
void ft_parse(int argc, char *argv[], t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	key_hook(int keycode, t_data *data);
int	mouse_hook(int mousecode, int x, int y, t_data *data);
void	my_mlx_init(t_data *data);
void ft_numerr();
int	ft_isspace(int c);
double	ft_atof(char *str);
void	julia_init(int argc, char *argv[],t_data *data);
void	mandelbrot_init(int argc, t_data *data);