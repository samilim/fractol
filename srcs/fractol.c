/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:54:49 by salimon           #+#    #+#             */
/*   Updated: 2022/02/09 07:05:35 by salimon          ###   ########.fr       */
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

int	valid_arg(char **argv, t_vars *vars)
{
	t_fractal	fractal;
	int argument;

	if (ft_strcmp(argv[1], "Mandelbrot") != 0 && ft_strcmp(argv[1], "Julia") != 0 && ft_strcmp(argv[1], "Mandelbar") != 0)
		return (0);
	if (argv[2])
	{
		if (ft_strcmp(argv[1], "Julia") != 0)
			return (0);
		argument = ft_atoi(argv[2]);
		// if (ft_isfloat(argv[2]) == 1)
		// {
		// 	if (argv[3])
		// 	{
		// 		if (ft_isfloat(argv[3]) != 1)
		// 			return(0);
		// 	}
		// }
		// else
		// 	return (0);
		//printf("arg = %d\n", vars->fractal.arg);
		if (argument > 0 && argument < 6)
			vars->fractal.arg = argument;
		else
			return (0);
	}
	return (1);
}

int	print_help()
{
	printf("Invalid parameter.\n");
	printf("Please use one of those parameters :\n Mandelbrot\n Julia\n");
	return (1);
}

void	init_datas(int argc, char **argv, t_vars *vars)
{
	t_canvas	canvas;

	vars->argc = argc;
	vars->argv = argv;
	vars->canvas.x = 0.0;
	vars->canvas.y = 0.0;
	vars->fractal.set = argv[1];
	vars->fractal.max_iteration = 200;
	vars->fractal.palette = 3;
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
	t_vars	vars;
	t_mlx		mlx;
	
	if (argc < 2 || !(valid_arg(argv, &vars)))
		return (print_help());
	else
	{
		printf("===KEYS===\nSpace to change palette\nMouse wheel to zoom in and out\nEsc to exit\n==========\n");
		init_datas(argc, argv, &vars);
		init_window(&vars);
		if (ft_strcmp(vars.fractal.set, "Mandelbrot") == 0)
			mandelbrot(&vars);
		else if (ft_strcmp(vars.fractal.set, "Julia") == 0)
			julia(&vars);
		else if (ft_strcmp(vars.fractal.set, "Mandelbar") == 0)
			mandelbar(&vars);
		init_image(&vars);
	}
	return (0);
}