/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:54:12 by salimon           #+#    #+#             */
/*   Updated: 2022/02/09 02:53:57 by salimon          ###   ########.fr       */
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
    }
    else
    {
        //dezoom
    }
}

/*BONUS*/
void move(int key)
{
    /*move with the arrows*/
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
		if (vars->fractal.palette != 3)
			vars->fractal.palette++;
		else
			vars->fractal.palette = 1;
		printf("palette %d\n", vars->fractal.palette);
	}
	return (0);
}

int	mouse_hook(int keycode, t_vars *vars)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 5 || keycode == 4)
        zoom(keycode, vars);
	return (0);
}