/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:54:49 by salimon           #+#    #+#             */
/*   Updated: 2021/11/08 08:10:57 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keycodes.h"

//gcc -Wall -Wextra -Werror fractol.c key_management.c -lbsd -lmlx -lXext -lX11 && ./a.out

int	valid_arg(char **argv)
{
	if (argv[1] == "Mandelbrot" || argv[1] == "Julia")
		return (1);
	else
		return (0);
}

int	print_help()
{
	printf("Invalid parameter.\n");
	printf("Valid parameters :\n Mandelbrot\n Julia");
	return (0);
}


void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


static void	init()
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, 1200, 800, "Fractol");
    mlx.img = mlx_new_image(mlx.mlx, 1200, 800);
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
								&mlx.endian);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	//mlx_hook(mlx.win, 2, 1L<<0, close_win, &mlx);
	mlx_loop(mlx.mlx);
}


/*
A parameter is passed on the command line to define what type of fractal will be
viewed. If no parameter is provided, or if the parameter is invalid, the program
displays a list of available parameters and exits properly.
•More parameters must be used for fractal parameters or ignored.
You must be able to create different Julia set with the parameters of the program.
*/

// USE IMAGE (?)

int main(int argc, char **argv)
{
	if (argc < 2 || !(valid_arg(argv)))
		return (print_help());
	else
    	init();
    return (0);
}