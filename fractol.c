#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#define WIN_WIDTH 800
#define WIN_HEIGHT 800
#define ITERMAX 100

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
	double		zoom;
	t_com	*z;
	t_com	*c;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;
	
	dst = data->addr + (y * data -> line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
	return (0);
}

int julia(double h, double w, t_data *data)
{
	// 식이 똑같고 z와 c가 어떻게 들어가는지만 다름!
	t_com	c;
	t_com	z;
	int		iter;
	double	tmpx;

	//c = *(data->c);
	//z = *(data->z);
	data->c = &c;
	data->z = &z;
	c.x = -0.75;
	c.y = 0;
	iter = 0;
	//z.x = (w - WIN_WIDTH  /2)/WIN_WIDTH  *4; // 이 파트 계산해서 넣어주는게 좋을듯
	//z.y = (h - WIN_HEIGHT /2)/WIN_HEIGHT  *4;
	//printf("%.2f\n",data->zoom);
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
	//c는 주어진 값으로 변환해서 사용하고 z가 평면에서의 위치임!
}

int	mandelbrot(double h, double w)
{
	t_com	c;
	t_com	z;
	int		iter;
	double	tmpx;

	iter = 0;
	z.x = 0;
	z.y = 0;
	c.x = (w - WIN_WIDTH/2)/WIN_WIDTH * 4 - 0.5;
	c.y = (h - WIN_HEIGHT/2)/WIN_HEIGHT * 4;
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
			//iter = mandelbrot((double)i,(double)j, &vars);
			iter = julia((double) h, (double)w, data);
			//iter = 0;
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

int	main(void)
{
	//t_vars vars;
	t_data data;

	data.mlx = mlx_init(); // 포인터 초기화
	data.win = mlx_new_window(data.mlx,800,800,"fractol"); // 생성할 윈도우 가리키는 포인터
	data.img = mlx_new_image(data.mlx, 800, 800);
	data.addr = mlx_get_data_addr(data.img,&data.bits_per_pixel, &data.line_length, &data.endian);
	data.zoom = 1;
	//image.img = mlx_new_image(vars.mlx, 800, 800); // 메모리에 새 이미지를 만든다.
	//image.addr = mlx_get_data_addr(image.img,&image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	//vars.data = &image;
	//vars.data->zoom = 1;
	draw_fractol(&data);
	/*여기까지 초기화고....*/
	/*여기서 부터 그리는 부분*/
	//mlx_put_image_to_window(data.mlx,data.win, data.img,0,0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	//mlx_mouse_hook(vars.win,mouse_hook,&vars);
	mlx_loop_hook(data.mlx, draw_fractol, &data);
	mlx_hook(data.win, 17, 0, exit_hook, 0);
	mlx_loop(data.mlx);
	return(0);
}