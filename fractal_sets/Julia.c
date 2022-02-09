/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:33:36 by salimon           #+#    #+#             */
/*   Updated: 2022/02/09 06:31:33 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycodes.h"
#include "../includes/colors.h"
# include <math.h>

void    julias_sets(t_vars *vars, t_complex_nb *c)
{
    if (vars->fractal.arg == 1)
    {
        c->r = -0.7;
        c->i = 0.27015;
    }
    else if (vars->fractal.arg == 2)
    {
        c->r = -0.8;
        c->i = 0.156;
    }
    else if (vars->fractal.arg == 3)
    {
        c->r = -0.4;
        c->i = 0.6;
    }
    else if (vars->fractal.arg == 4)
    {
        c->r = -0.75;
        c->i = 0.11;
    }
    else if (vars->fractal.arg == 5)
    {
        c->r = -0.52;
        c->i = 0.57;
    }
}

static void    next_z(t_complex_nb *z, t_complex_nb *c)
{
    double nz;

    nz = z->r * z->r - z->i * z->i + c->r;
    z->i = 2 * z->r * z->i + c->i;
    z->r = nz;
}

void    julia(t_vars *vars)
{
    t_complex_nb    z;
    t_complex_nb    c;
    int             iteration;

    while(vars->canvas.y < WIN_HEIGHT)
    {
        vars->canvas.x = 0;
        while (vars->canvas.x < WIN_WIDTH)
        {
            z.r = (vars->canvas.x - (WIN_WIDTH / 2.0)) * 4.0 / WIN_WIDTH;
            z.i = (vars->canvas.y - (WIN_HEIGHT / 2.0)) * 4.0 / WIN_HEIGHT;
            julias_sets(vars, &c);
            iteration = 0;
            while ((iteration++ < (vars->fractal.max_iteration)) && ((z.r * z.r + z.i * z.i) <= 4.0))
                next_z(&z, &c);
            if (iteration < (vars->fractal.max_iteration))
                my_mlx_pixel_put(&vars->mlx, vars->canvas.x, vars->canvas.y, get_color(vars, iteration));
            vars->canvas.x++;
        }
        vars->canvas.y++;
    }
}