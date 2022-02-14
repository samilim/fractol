/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Burning ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 06:35:15 by salimon           #+#    #+#             */
/*   Updated: 2022/02/13 08:06:59 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	cycle(t_vars *vars, t_complex_nb *z, t_complex_nb *c)
{
	c->r = -0.6 + ((vars->canvas.x + vars->canvas.pos_x + 40)
			- vars->canvas.ww_half) / (vars->canvas.r_factor);
	c->i = 0.2 + ((vars->canvas.y + vars->canvas.pos_y -150)
			- vars->canvas.wh_half) / (vars->canvas.i_factor);
	z->r = 0;
	z->i = 0;
}

static void	next_z(t_complex_nb *z, t_complex_nb *c)
{
	double	nz;

	nz = z->r * z->r - z->i * z->i + c->r;
	z->i = 2 * fabs(z->r * z->i) + c->i;
	z->r = nz;
}

void	burning_ship(t_vars *vars)
{
	t_complex_nb	z;
	t_complex_nb	c;
	int				i;

	while (vars->canvas.y++ < WIN_HEIGHT)
	{
		vars->canvas.x = 0;
		while (vars->canvas.x++ < WIN_WIDTH)
		{
			cycle(vars, &z, &c);
			i = 0;
			while ((i++ < (vars->fractal.max_iteration)))
			{
				next_z(&z, &c);
				if ((z.r * z.r + z.i * z.i) > 10.0)
					break ;
			}
			if (i != (vars->fractal.max_iteration))
				my_mlx_pixel_put(&vars->mlx, vars->canvas.x,
					vars->canvas.y, get_color(vars, i));
		}
	}
}
