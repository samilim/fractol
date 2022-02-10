/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:54:12 by salimon           #+#    #+#             */
/*   Updated: 2022/02/10 08:38:11 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycodes.h"
#include "../includes/colors.h"
# include "../mlx_linux/mlx.h"

/*
** Zoom in / out INDEFINITLY with mouse wheel
** Bonus : zoom follows the actual mouse position
*/

void zoom(int keycode, t_vars *vars)
{
    if (keycode == 4)
    {
        //zoom
		vars->canvas.zoom -= 0.3;
    }
    else
    {
        //dezoom
		vars->canvas.zoom += 0.3;
    }
}

/* BONUS
** Move with the arrows
*/

void move(int keycode, t_vars *vars)
{
	if (keycode == UP_KEY)
		vars->canvas.y += 0.1;
	if (keycode == DOWN_KEY)
		vars->canvas.y -= 0.1;
	if (keycode == LEFT_KEY)
		vars->canvas.x -= 0.1;
	if (keycode == RIGHT_KEY)
		vars->canvas.x += 0.1;
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("keycode = %d\n", keycode);
	if (keycode == ESC_KEY)
    {
		mlx_destroy_window(vars->mlx.mlx, vars->mlx.win);
        exit(EXIT_SUCCESS);
    }
	if (keycode == SPACE_KEY)
	{
		mlx_destroy_image(vars->mlx.mlx, vars->mlx.img);
		if (vars->fractal.palette != 3)
			vars->fractal.palette++;
		else
			vars->fractal.palette = 1;
		printf("Changement de palette : %d\n", vars->fractal.palette);
		display_fractal(vars);
	}
	else if (keycode == UP_KEY || keycode == DOWN_KEY || keycode == LEFT_KEY || keycode == RIGHT_KEY)
	{
		mlx_destroy_image(vars->mlx.mlx, vars->mlx.img);
		move(keycode, vars);
		display_fractal(vars);
	}
	return (0);
}

int	mouse_hook(int keycode, t_vars *vars)
{
	printf("keycode = %d\n", keycode);
	if (keycode == SCROLLDOWN_KEY || keycode == SCROLLUP_KEY)
	{
		mlx_destroy_image(vars->mlx.mlx, vars->mlx.img);
        zoom(keycode, vars);
		display_fractal(vars);
	}
	/*varier config Julia avec les mvmts de la souris*/
	return (0);
}