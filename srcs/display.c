/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 06:07:17 by salimon           #+#    #+#             */
/*   Updated: 2022/02/15 05:21:04 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_image(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.win, vars->mlx.img, 0, 0);
	mlx_mouse_hook(vars->mlx.win, mouse_hook, vars);
	mlx_hook(vars->mlx.win, 8, 1L << 5, mouse_exit_window, vars);
	mlx_key_hook(vars->mlx.win, key_hook, vars);
}

int	init_window(t_vars *vars)
{
	vars->mlx.mlx = mlx_init();
	if (!vars->mlx.mlx)
	{
		write(1, "Mlx failed to initiate\n", 24);
		return (-1);
	}
	vars->mlx.win = mlx_new_window(vars->mlx.mlx,
			WIN_HEIGHT + 1, WIN_WIDTH + 1, "Fractol");
	if (!vars->mlx.win)
	{
		write(1, "Mlx failed to create window\n", 29);
		return (-1);
	}
	return (0);
}

void	create_image(t_vars *vars)
{
	if (vars->mlx.img != NULL)
		mlx_destroy_image(vars->mlx.mlx, vars->mlx.img);
	vars->mlx.img = mlx_new_image(vars->mlx.mlx, WIN_HEIGHT + 1, WIN_WIDTH + 1);
	if (vars->mlx.img == NULL)
	{
		write(1, "Mlx failed to create a new image\n", 34);
		mlx_destroy_window(vars->mlx.mlx, vars->mlx.win);
		exit(EXIT_SUCCESS);
	}
	vars->mlx.addr = mlx_get_data_addr(vars->mlx.img,
			&vars->mlx.bits_per_pixel,
			&vars->mlx.line_length, &vars->mlx.endian);
}

void	display_fractal(t_vars *vars)
{
	create_image(vars);
	vars->canvas.x = 0.0;
	vars->canvas.y = 0.0;
	vars->canvas.r_factor = 0.5 * vars->canvas.zoom * WIN_WIDTH;
	vars->canvas.i_factor = 0.5 * vars->canvas.zoom * WIN_HEIGHT;
	if (vars->fractal.set == 1)
		mandelbrot(vars);
	else if (vars->fractal.set == 2)
		julia(vars);
	else if (vars->fractal.set == 3)
		mandelbar(vars);
	else if (vars->fractal.set == 4)
		burning_ship(vars);
	mlx_clear_window(vars->mlx.mlx, vars->mlx.win);
	init_image(vars);
}
