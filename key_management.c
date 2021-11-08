/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:54:12 by salimon           #+#    #+#             */
/*   Updated: 2021/11/08 08:14:03 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keycodes.h"

int	close_win(int keycode, t_mlx *mlx) //dstroy fenetre quand on appuie sur esc
{
	mlx_destroy_window(mlx->mlx, mlx->win);
    return 0;
}

/*
** Zoom in / out INDEFINITLY with mouse wheel
** Bonus : zoom follows the actual mouse position
*/

int zoom(int keycode)
{

}

/*BONUS*/
int move(int keycode)
{
    /*move with the arrows*/
}