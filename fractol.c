
#include "fractol.h"

int julia(double h, double w, t_data *data)
{
	t_com	c;
	t_com	z;
	int		iter;
	double	tmpx;

	data->c = &c;
	data->z = &z;
	c.x = -0.75;
	c.y = 0;
	// c.x와 c.y에다 strd 해서 넣으면 됨!
	iter = 0;
	z.x = (w - WIN_WIDTH /2)/WIN_WIDTH * (data->zoom) *4; // 이 파트 계산해서 넣어주는게 좋을듯
	z.y = (h - WIN_HEIGHT /2)/WIN_HEIGHT * (data->zoom) *4;
	while((z.x * z.x) + (z.y * z.y) < 4 && iter < ITERMAX)
	{
		tmpx = (z.x * z.x) - (z.y * z.y);
		z.y = (2 * z.x * z.y) + c.y;
		z.x = tmpx + c.x;
		iter++;
	}
	return iter;
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
	c.x = (w - WIN_WIDTH/2)/WIN_WIDTH * (data->zoom) * 4 - 0.5;
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

int draw_fractol(t_data *data)
{
	int	h;
	int	w;
	int	iter;

	h = 0;
	w = 0;
	while(h <= WIN_HEIGHT)
	{
		w = 0;
		while(w <= WIN_WIDTH)
		{
			if (data->fractoltype == T_JULIA)
				iter = julia((double) h, (double)w, data); 
			else if (data->fractoltype == T_MANDELBROT)
				iter = mandelbrot((double)h,(double)w, data);
			my_mlx_pixel_put(data, w, h, iter * 18);
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(data->mlx,data->win, data->img,0,0);
	return 0;
}

int exit_hook(void)
{
	exit(0);
}


void ft_inputerror()
{
	ft_printf("Please enter 'julia' or 'mandelbrot' as the second argument, and after 'julia', please enter num1 and num2. And do not enter anything else.\n");
	exit(1);
}

void ft_parse(int argc, char *argv[], t_data *data)
{
	(void)argv;
	if (argc > 4)
		ft_inputerror();
	if (ft_strcmp(argv[1],"julia") == 0)
		data->fractoltype = T_JULIA;
	else if (ft_strcmp(argv[1],"mandelbrot") == 0)
		data->fractoltype = T_MANDELBROT;
	else
		ft_inputerror();
}


int	main(int argc, char *argv[])
{
	t_data data;

	data.zoom = 1;
	ft_parse(argc,argv,&data);
	my_mlx_init(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop_hook(data.mlx, draw_fractol, &data);
	mlx_hook(data.win, 17, 0, exit_hook, 0);
	mlx_loop(data.mlx);
	return(0);
}

