#include "fractol.h"

//gcc -Wall -Wextra -Werror mlxtest.c -lbsd -lmlx -lXext -lX11 && ./a.out


typedef struct  s_data
{
	void    *img;
	char    *addr; //memory address on which we will mutate the bytes accordingly
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_square(t_data img)
{
	int x = 5;
	int y = 5;

	while (y < 55)
	{
		x = 5;
		while (x < 55)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}

}

void	print_triangle(t_data img, int base)
{
	int x = base;
	int y = 0;
	int p = 0;

	while (y < base)
	{
		p = 0;
		x = base;
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		while(p - y)
		{
			my_mlx_pixel_put(&img, x + p, y, 0x00FF0000);
			my_mlx_pixel_put(&img, x - p, y, 0x00FF0000);
			p++;
		}
		y++;
	}
}


int main(void)
{
    void	*mlx;
    void	*mlx_win;
    t_data	img;

	mlx = mlx_init(); //establish a connection to the correct graphical system and will return a void * which holds the location of our current MLX instance.
    mlx_win = mlx_new_window(mlx, 1200, 800, "Hello world!");
    img.img = mlx_new_image(mlx, 1200, 800); //return a pointer to the window we have just created. We can give the window height, width and a title. We then will have to call mlx_loop to initiate the window rendering.

	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//print_square(img);
	print_triangle(img, 300);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	///mlx_key_hook(mlx_win, ft_key, 0);
	mlx_loop(mlx);
}