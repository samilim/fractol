/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:54:49 by salimon           #+#    #+#             */
/*   Updated: 2022/02/13 05:51:17 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycodes.h"
#include "../includes/colors.h"
#include "../mlx_linux/mlx.h"
#include <math.h>


//comp home
//gcc -Wno-unused-function -Wno-unused-variable -Wno-unused-parameter libft/*.c fractal_sets/*.c srcs/*.c -lbsd -lmlx -lXext -lX11 -lm && ./a.out Mandelbrot

//gcc -Wno-unused-function -Wno-unused-variable -Wno-unused-parameter -g libft/*.c fractal_sets/*.c srcs/*.c -lbsd -lmlx -lXext -lX11 -lm && gdb ./a.out Mandelbrot
//42
//gcc -Wno-unused-function -Wno-unused-variable -Wno-unused-parameter libft/*.c fractal_sets/*.c srcs/*.c -lbsd -lmlx -Lmlx_linux -lXext -lX11 -lm && ./a.out Mandelbrot


void	init_set(t_vars *vars, char **argv)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		vars->fractal.set = 1;
	else if (ft_strcmp(argv[1], "Julia") == 0)
		vars->fractal.set = 2;
	else if (ft_strcmp(argv[1], "Mandelbar") == 0)
		vars->fractal.set = 3;
	else if (ft_strcmp(argv[1], "Phoenix") == 0)
		vars->fractal.set = 4;
	else
		vars->fractal.set = -1;
}

int	valid_arg(char **argv, t_vars *vars)
{
	int argument;

	if (!vars->fractal.set)
		return (0);
	if (argv[2])
	{
		if (vars->fractal.set != 2)
			return (0);
		argument = ft_atoi(argv[2]);
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
	printf("Please use one of those parameters :\n Mandelbrot\n Julia (add a second int parameter between 1 and 5 to choose the Julia's configuration to initate)\n");
	return (1);
}

void	init_datas(int argc, char **argv, t_vars *vars)
{
	vars->argc = argc;
	vars->argv = argv;
	vars->canvas.pos_x = 0;
	vars->canvas.pos_y = 0;
	if (vars->fractal.set == 3)
		vars->canvas.zoom = 0.55;
	else
		vars->canvas.zoom = 1;
	vars->canvas.ww_half = WIN_WIDTH / 2;
	vars->canvas.wh_half = WIN_HEIGHT / 2;
	vars->fractal.max_iteration = 50;
	vars->fractal.palette = 1;
	if (argc == 3)
		vars->fractal.arg = ft_atoi(argv[2]);
	else
		vars->fractal.arg = 1;
}

int main(int argc, char **argv)
{
	t_vars	vars;

	init_set(&vars, argv);
	if (argc < 2 || !(valid_arg(argv, &vars)))
		return (print_help());
	else
	{
		printf("\n===KEYS===\n[Esc] to exit\n[Space] to change palette\n[Mouse wheel] to zoom in and out\n[Left click] to change fractal\n[Arrows] to move\n[Move the mouse] to change the Julia's set pattern\n==========\n\n");
		init_datas(argc, argv, &vars);
		init_window(&vars);
		display_fractal(&vars);
		mlx_loop(vars.mlx.mlx);
	}
	return (0);
}


// void	phoenix(t_vars *vars)
// {
//     t_complex_nb	z;
// 	t_complex_nb	c;
// 	int				iteration;
// 	double	n;
// 	t_cnb	t;

// 	n = z.real * z.real + z.imag * z.imag;
// 	t = (t_cnb) {.real = 0, .imag = 0};
// 	while (iteration < vars->fractal.max_iteration && n < 4)
// 	{
// 		z.imag = 2 * fabs(z.imag * z.real) + c.imag;
// 		z.real = t.real - t.imag - c.real;
// 		t.real = z.real * z.real;
// 		t.imag = z.imag * z.imag;
// 		n = t.real + t.imag;
// 	}
// }