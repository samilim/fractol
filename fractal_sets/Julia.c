/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:33:36 by salimon           #+#    #+#             */
/*   Updated: 2022/02/09 02:27:29 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycodes.h"
#include "../includes/colors.h"
# include <math.h>

//z²-(3/4)

static void    next_z(t_complex_nb *z, t_complex_nb *c)
{
    double nz;

    nz = z->real_part * z->real_part - z->imaginary_part * z->imaginary_part + c->real_part;
    z->imaginary_part = 2 * z->real_part * z->imaginary_part + c->imaginary_part;
    z->real_part = nz;
}
    
// void    Julia(t_vars *vars, t_mlx *mlx)
// {
//     t_complex_nb    z;
//     t_complex_nb    c;
//     int             iteration;

//     //c.real_part = ;
//     //c.imaginary_part = ;

//     while(vars->canvas.y < WIN_HEIGHT)
//     {
//         vars->canvas.x = 0;
//         while (vars->canvas.x < WIN_WIDTH)
//         {
//             c.real_part = (vars->canvas.x - (WIN_WIDTH / 2.0)) * 4.0 / WIN_WIDTH;
//             c.imaginary_part = (vars->canvas.y - (WIN_HEIGHT / 2.0)) * 4.0 / WIN_HEIGHT;
//             z.real_part = 0;
//             z.imaginary_part = 0;
//             iteration = 0;
//             while ((iteration++ < (vars->fractal.max_iteration)) && ((z.real_part * z.real_part + z.imaginary_part * z.imaginary_part) <= 4.0))
//                 next_z(&z, &c);
//             if (iteration < (vars->fractal.max_iteration))
//                 my_mlx_pixel_put(mlx, vars->canvas.x, vars->canvas.y, get_color(vars, iteration));
//             vars->canvas.x++;
//         }
//         vars->canvas.y++;
//     }
// }

void    Julia(t_vars *vars)
{
    t_complex_nb    z;
    t_complex_nb    c;
    int             iteration;

    while(vars->canvas.y < WIN_HEIGHT)
    {
        vars->canvas.x = 0;
        while (vars->canvas.x < WIN_WIDTH)
        {
            c.real_part = (vars->canvas.x - (WIN_WIDTH / 2.0)) * 4.0 / WIN_WIDTH;
            c.imaginary_part = (vars->canvas.y - (WIN_HEIGHT / 2.0)) * 4.0 / WIN_HEIGHT;
            z.real_part = 0;
            z.imaginary_part = 0;
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