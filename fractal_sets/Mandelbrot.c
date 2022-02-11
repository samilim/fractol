/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:01:37 by salimon           #+#    #+#             */
/*   Updated: 2022/02/11 03:41:50 by salimon          ###   ########.fr       */
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

static double	magnitude(t_complex_nb *complex)
{
	double	sq;

	sq = sqrt((complex->r * complex->r)
			+ (complex->i * complex->i));
	return (sq);
}

void	mandelbrot(t_vars *vars)
{
	t_complex_nb	z;
	t_complex_nb	c;
	int				iteration;

	vars->canvas.x = 0;
	vars->canvas.y = 0;
	while (vars->canvas.y++ < WIN_HEIGHT)
	{
		vars->canvas.x = 0;
		while (vars->canvas.x < WIN_WIDTH)
		{
			c.r = vars->canvas.zoom * (vars->canvas.x + vars->canvas.pos_x
					- (WIN_WIDTH / 2.0)) * 4.0 / WIN_WIDTH;
			c.i = vars->canvas.zoom * (vars->canvas.y + vars->canvas.pos_y
					- (WIN_HEIGHT / 2.0)) * 4.0 / WIN_HEIGHT;
			z.r = 0;
			z.i = 0;
			iteration = 0;
			while ((iteration++ < (vars->fractal.max_iteration))
				&& ((z.r * z.r + z.i * z.i) <= 4.0))
				next_z(&z, &c);
			if (iteration < (vars->fractal.max_iteration))
				my_mlx_pixel_put(&vars->mlx, vars->canvas.x,
					vars->canvas.y, get_color(vars, iteration));
			vars->canvas.x++;
		}
	}
}
