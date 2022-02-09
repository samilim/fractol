/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 06:14:35 by salimon           #+#    #+#             */
/*   Updated: 2022/02/09 07:05:16 by salimon          ###   ########.fr       */
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
	z->i = (-2.0) * z->r * z->i + c->i;
	z->r = nz;
}

static double	magnitude(t_complex_nb *complex)
{
	double	sq;

	sq = sqrt((complex->r * complex->r)
			+ (complex->i * complex->i));
	return (sq);
}

void	mandelbar(t_vars *vars)
{
	t_complex_nb	z;
	t_complex_nb	c;
	int				iteration;

	while (vars->canvas.y++ < WIN_HEIGHT)
	{
		vars->canvas.x = 0;
		while (vars->canvas.x < WIN_WIDTH)
		{
			c.r = (vars->canvas.x
					- (WIN_WIDTH / 2.0)) * 4.0 / WIN_WIDTH;
			c.i = (vars->canvas.y
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
