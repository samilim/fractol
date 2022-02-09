/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:54:49 by salimon           #+#    #+#             */
/*   Updated: 2022/02/09 02:45:07 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycodes.h"
#include "../includes/colors.h"
# include "../mlx_linux/mlx.h"
# include <math.h>


//comp home
//gcc -Wno-unused-function -Wno-unused-variable -Wno-unused-parameter libft/*.c fractal_sets/*.c srcs/*.c -lbsd -lmlx -lXext -lX11 -lm && ./a.out Mandelbrot

//gcc -Wno-unused-function -Wno-unused-variable -Wno-unused-parameter -g libft/*.c fractal_sets/*.c srcs/*.c -lbsd -lmlx -lXext -lX11 -lm && gdb ./a.out Mandelbrot
//42
//gcc -Wno-unused-function -Wno-unused-variable -Wno-unused-parameter libft/*.c fractal_sets/*.c srcs/*.c -lbsd -lmlx -Lmlx_linux -lXext -lX11 -lm && ./a.out Mandelbrot

int	valid_arg(char **argv)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0 || ft_strcmp(argv[1], "Julia") == 0)
		return (1);
	else
		return (0);
}

int	print_help()
{
	printf("Invalid parameter.\n");
	printf("Please use one of those parameters :\n Mandelbrot\n Julia\n");
	return (1);
}

void	init_datas(char **argv, t_vars *vars)
{
	t_fractal	fractal;
	t_canvas	canvas;

	vars->canvas.x = 0.0;
	vars->canvas.y = 0.0;
	vars->fractal.set = argv[1];
	vars->fractal.max_iteration = 50;
	vars->fractal.palette = 3;
}

void	init_image(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.win, vars->mlx.img, 0, 0);
	//mlx_hook(mlx.win, 2, 1L<<0, close_win, &mlx);
	printf("palette %d\n", vars->fractal.palette);
	mlx_key_hook(vars->mlx.win, key_hook, vars);
	mlx_mouse_hook(vars->mlx.win, mouse_hook, vars);
	//mlx_hook(mlx->win, 2, 0L, key_actions, &mlx);
	mlx_loop(vars->mlx.mlx);
}
// void	init_image(t_mlx *mlx, t_vars *vars)
// {
// 	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
// 	//mlx_hook(mlx.win, 2, 1L<<0, close_win, &mlx);
// 	mlx_key_hook(mlx->win, key_hook, &vars);
// 	mlx_mouse_hook(mlx->win, mouse_hook, &vars);
// 	//mlx_hook(mlx->win, 2, 0L, key_actions, &mlx);
// 	mlx_loop(mlx->mlx);
// }

void	init_window(t_vars *vars)
{
	vars->mlx.mlx = mlx_init();
    vars->mlx.win = mlx_new_window(vars->mlx.mlx, WIN_HEIGHT, WIN_WIDTH, "Fractol");
    vars->mlx.img = mlx_new_image(vars->mlx.mlx, WIN_HEIGHT, WIN_WIDTH);
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	vars->mlx.addr = mlx_get_data_addr(vars->mlx.img, &vars->mlx.bits_per_pixel, &vars->mlx.line_length,
								&vars->mlx.endian);
}

// void	init_window(t_mlx *mlx)
// {
// 	mlx->mlx = mlx_init();
//     mlx->win = mlx_new_window(mlx->mlx, WIN_HEIGHT, WIN_WIDTH, "Fractol");
//     mlx->img = mlx_new_image(mlx->mlx, WIN_HEIGHT, WIN_WIDTH);
// 	/*
// 	** After creating an image, we can call `mlx_get_data_addr`, we pass
// 	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
// 	** then be set accordingly for the *current* data address.
// 	*/
// 	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length,
// 								&mlx->endian);
// }


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
	t_vars	vars;
	t_mlx		mlx;
	
	if (argc < 2 || !(valid_arg(argv)))
		return (print_help());
	else
	{
		printf("Space to change palette\nZoom in and out with mouse wheel\nEsc to exit\n");
		init_datas(argv, &vars);
    	init_window(&vars);
		if (ft_strcmp(vars.fractal.set, "Mandelbrot") == 0)
			Mandelbrot(&vars);
		else if (ft_strcmp(vars.fractal.set, "Julia") == 0)
			Julia(&vars);
		init_image(&vars);
	}
	return (0);
}