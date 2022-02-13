/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:54:12 by salimon           #+#    #+#             */
/*   Updated: 2022/02/13 07:59:12 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycodes.h"
#include "../includes/colors.h"
# include "../mlx_linux/mlx.h"
#include <unistd.h>

void zoom(int keycode, t_vars *vars)
{
    if (keycode == 4)
    {
        //zoom
		vars->canvas.zoom *= 1.050;
    }
    else
    {
        //dezoom
		vars->canvas.zoom /= 1.050;
    }
}

void move(int keycode, t_vars *vars)
{
	if (keycode == UP_KEY)
		vars->canvas.pos_y -= 10.0;
	if (keycode == DOWN_KEY)
		vars->canvas.pos_y += 10.0;
	if (keycode == LEFT_KEY)
		vars->canvas.pos_x -= 10.0;
	if (keycode == RIGHT_KEY)
		vars->canvas.pos_x += 10.0;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
    {
		mlx_destroy_window(vars->mlx.mlx, vars->mlx.win);
        exit(EXIT_SUCCESS);
    }
	if (keycode == SPACE_KEY)
	{
		if (vars->fractal.palette != 7)
			vars->fractal.palette++;
		else
			vars->fractal.palette = 1;
		display_fractal(vars);
	}
	else if (keycode == UP_KEY || keycode == DOWN_KEY || keycode == LEFT_KEY || keycode == RIGHT_KEY)
	{
		move(keycode, vars);
		display_fractal(vars);
	}
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	if ((x && y ) && (keycode == SCROLLDOWN_KEY || keycode == SCROLLUP_KEY))
	{
        zoom(keycode, vars);
		display_fractal(vars);
	}
	else if (keycode == LEFT_CLICK)
	{
		if (vars->fractal.set != 4)
			vars->fractal.set++;
		else
			vars->fractal.set = 1;
		vars->canvas.zoom = 0.64;
		vars->canvas.pos_x = 0;
		vars->canvas.pos_y = 0;
		display_fractal(vars);
	}
	return (0);
}

int	mouse_exit_window(t_vars *vars)
{
	if (vars->fractal.arg != 5)
		vars->fractal.arg++;
	else
		vars->fractal.arg = 1;
	display_fractal(vars);
	return(0);
}