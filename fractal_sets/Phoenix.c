/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:36:33 by salimon           #+#    #+#             */
/*   Updated: 2022/02/13 03:33:45 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycodes.h"
#include "../includes/colors.h"
#include <math.h>

static void	next_z(t_complex_nb *z, t_complex_nb *c)
{
    double	nz;

	// z->i = 2.0 * fabs(z->r * z->i) + c->i;
	// z->r = t->r - t->i - c->r;
    // t->r = z->r * z->r;
    // t->i = z->i * z->i;
    // nz = t->r + t->i;

    nz = z->r * z->r + z->i * z->i - c->r;
    z->i = 2 * fabs(z->r * z->i) + c->i;
    z->r = nz;
}

void	phoenix(t_vars *vars)
{
	t_complex_nb	z;
	t_complex_nb	c;

	int				iteration;

    c.r = -0.5;
    c.i = 0.56667;
	while (vars->canvas.y++ < WIN_HEIGHT)
	{
		vars->canvas.x = 0;
		while (vars->canvas.x < WIN_WIDTH)
		{
			z.r = (vars->canvas.x
					- (WIN_WIDTH / 2.0)) * 4.0 / WIN_WIDTH;
			z.i = (vars->canvas.y
					- (WIN_HEIGHT / 2.0)) * 4.0 / WIN_HEIGHT;
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
