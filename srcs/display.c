/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 06:07:17 by salimon           #+#    #+#             */
/*   Updated: 2022/02/11 03:46:22 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycodes.h"
#include "../includes/colors.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init_image(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.win, vars->mlx.img, 0, 0);
	mlx_mouse_hook(vars->mlx.win, mouse_hook, vars);
	//mlx_hook(vars->mlx.win, 4, 1L<<2, left_click , vars);
	mlx_key_hook(vars->mlx.win, key_hook, vars);
}

void	init_window(t_vars *vars)
{
	vars->mlx.mlx = mlx_init();
    vars->mlx.win = mlx_new_window(vars->mlx.mlx, WIN_HEIGHT, WIN_WIDTH, "Fractol");
}

void	display_fractal(t_vars *vars)
{
	vars->mlx.img = mlx_new_image(vars->mlx.mlx, WIN_HEIGHT, WIN_WIDTH);
	vars->mlx.addr = mlx_get_data_addr(vars->mlx.img, &vars->mlx.bits_per_pixel, &vars->mlx.line_length,
			&vars->mlx.endian);
	if (vars->fractal.set == 1)
		mandelbrot(vars);
	else if (vars->fractal.set == 2)
		julia(vars);
	else if (vars->fractal.set == 3)
	 	mandelbar(vars);
	else if (vars->fractal.set == 4)
	 	phoenix(vars);
	mlx_clear_window(vars->mlx.mlx, vars->mlx.win);
	init_image(vars);
}