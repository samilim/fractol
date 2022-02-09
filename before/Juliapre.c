/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:33:36 by salimon           #+#    #+#             */
/*   Updated: 2022/02/09 06:26:23 by salimon          ###   ########.fr       */
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
        c->real_part = -0.7;
        c->imaginary_part = 0.27015;
    }
    else if (vars->fractal.arg == 2)
    {
        c->real_part = -0.8;
        c->imaginary_part = 0.156;
    }
    else if (vars->fractal.arg == 3)
    {
        c->real_part = -0.4;
        c->imaginary_part = 0.6;
    }
    else if (vars->fractal.arg == 4)
    {
        c->real_part = -0.75;
        c->imaginary_part = 0.11;
    }
    else if (vars->fractal.arg == 5)
    {
        c->real_part = -0.52;
        c->imaginary_part = 0.57;
    }
}

static void    next_z(t_complex_nb *z, t_complex_nb *c)
{
    double nz;

    nz = z->real_part * z->real_part - z->imaginary_part * z->imaginary_part + c->real_part;
    z->imaginary_part = 2 * z->real_part * z->imaginary_part + c->imaginary_part;
    z->real_part = nz;
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
            z.real_part = (vars->canvas.x - (WIN_WIDTH / 2.0)) * 4.0 / WIN_WIDTH;
            z.imaginary_part = (vars->canvas.y - (WIN_HEIGHT / 2.0)) * 4.0 / WIN_HEIGHT;
            julias_sets(vars, &c);
            iteration = 0;
            while ((iteration++ < (vars->fractal.max_iteration)) && ((z.real_part * z.real_part + z.imaginary_part * z.imaginary_part) <= 4.0))
                next_z(&z, &c);
            if (iteration < (vars->fractal.max_iteration))
                my_mlx_pixel_put(&vars->mlx, vars->canvas.x, vars->canvas.y, get_color(vars, iteration));
            vars->canvas.x++;
        }
        vars->canvas.y++;
    }
}