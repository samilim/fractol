/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:54:12 by salimon           #+#    #+#             */
/*   Updated: 2021/11/08 09:21:40 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keycodes.h"

static void    key_actions(int key, t_mlx *mlx)
{
    if (key == ESC_KEY)
	    mlx_destroy_window(mlx->mlx, mlx->win);
}

/*
** Zoom in / out INDEFINITLY with mouse wheel
** Bonus : zoom follows the actual mouse position
*/

void zoom(int key)
{

}

/*BONUS*/
void move(int key)
{
    /*move with the arrows*/
}