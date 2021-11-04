#include "fractol.h"

int main(void)
{
    void	*mlx;
    void    *mlx_win;

	mlx = mlx_init(); //establish a connection to the correct graphical system and will return a void * which holds the location of our current MLX instance.
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!"); //return a pointer to the window we have just created. We can give the window height, width and a title. We then will have to call mlx_loop to initiate the window rendering.
	mlx_loop(mlx);
}