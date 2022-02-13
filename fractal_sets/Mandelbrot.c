/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:01:37 by salimon           #+#    #+#             */
/*   Updated: 2022/02/13 05:46:22 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycodes.h"
#include "../includes/colors.h"
#include <math.h>

static void	next_z(t_complex_nb *z, t_complex_nb *c)
{
	double	nz;

	nz = z->r * z->r - z->i * z->i + c->r;
	z->i = 2 * z->r * z->i + c->i;
	z->r = nz;
}

void	mandelbrot(t_vars *vars)
{
	t_complex_nb	z;
	t_complex_nb	c;
	int				i;

	while (vars->canvas.y++ < WIN_HEIGHT)
	{
		vars->canvas.x = 0;
		while (vars->canvas.x++ < WIN_WIDTH)
		{
			c.r = -0.6 + ((vars->canvas.x + vars->canvas.pos_x)
					- vars->canvas.ww_half) / (vars->canvas.r_factor);
			c.i = 0.2 + ((vars->canvas.y + vars->canvas.pos_y)
					- vars->canvas.wh_half) / (vars->canvas.i_factor);
			z.r = 0;
			z.i = 0;
			i = 0;
			while ((i++ < (vars->fractal.max_iteration))
				&& (z.r * z.r + z.i * z.i) <= 4.0)
				next_z(&z, &c);
			if (i < (vars->fractal.max_iteration))
				my_mlx_pixel_put(&vars->mlx, vars->canvas.x,
					vars->canvas.y, get_color(vars, i) + i * 3000);
		}
	}
}
