/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 06:14:35 by salimon           #+#    #+#             */
/*   Updated: 2022/02/13 05:45:13 by salimon          ###   ########.fr       */
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

void	mandelbar(t_vars *vars)
{
	t_complex_nb	z;
	t_complex_nb	c;
	int				iteration;

	printf("zoom = %f\n", vars->canvas.zoom);
	while (vars->canvas.y++ < WIN_HEIGHT)
	{
		vars->canvas.x = 0;
		while (vars->canvas.x++ < WIN_WIDTH)
		{
			c.r = ((vars->canvas.x + vars->canvas.pos_x)
					- vars->canvas.ww_half) / (vars->canvas.r_factor);
			c.i = ((vars->canvas.y + vars->canvas.pos_y)
					- vars->canvas.wh_half) / (vars->canvas.i_factor);
			z.r = 0;
			z.i = 0;
			iteration = 0;
			while ((iteration++ < (vars->fractal.max_iteration))
				&& ((z.r * z.r + z.i * z.i) <= 4.0))
				next_z(&z, &c);
			if (iteration < (vars->fractal.max_iteration))
				my_mlx_pixel_put(&vars->mlx, vars->canvas.x,
					vars->canvas.y, get_color(vars, iteration) + iteration * 3000);
		}
	}
}
