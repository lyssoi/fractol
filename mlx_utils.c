#include "fractol.h"

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
	draw_fractol(data);
	return (0);
}

void	my_mlx_init(t_data *data)
{
	if (!(data->mlx = mlx_init()))
		exit(1); // 포인터 초기화
	if (!(data->win = mlx_new_window(data->mlx,800,800,"fractol")))
		exit(1); // 생성할 윈도우 가리키는 포인터
	if (!(data->img = mlx_new_image(data->mlx, 800, 800))) // 메모리에 새 이미지를 만든다.
		exit(1);
	if (!(data->addr = mlx_get_data_addr(data->img,&(data->bits_per_pixel), &data->line_length, &data->endian)))// 이미지 주소 할당
		exit(1);
}