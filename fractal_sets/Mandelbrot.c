/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:01:37 by salimon           #+#    #+#             */
/*   Updated: 2022/01/10 03:29:27 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycodes.h"
#include "../includes/colors.h"

//z²+c
//nb complexe = nb i dont le carré est égal à -1 tel que i = racine de -1

//l'ensemble sera ici contenu dans le carré 2 -2

// void    Mandelbrot(t_vars *vars, t_mlx *mlx)
// {
//     t_complex_nb    z;
//     int             iteration;
//     double          tmp;

//     iteration = 0;
//     while((z.real_part * z.real_part + z.imaginary_part * z.imaginary_part) < 2 && iteration < vars->fractal.iterations)
//     {
//         tmp = z.real_part;
//         z.real_part = z.real_part * z.real_part - z.imaginary_part * z.imaginary_part + vars->canvas.x; //a² - b²
//         z.imaginary_part = 2 * tmp * z.imaginary_part + vars->canvas.y; //2abi
//         iteration++;
//         if (2 == 3)
//             my_mlx_pixel_put(mlx, z.real_part, z.imaginary_part, LAVENDER);
//     }
// }

void    Mandelbrot(t_vars *vars, t_mlx *mlx)
{
    t_complex_nb    z;
    int             iteration;
    double          tmp;

    iteration = 0;
    while((z.real_part * z.real_part + z.imaginary_part * z.imaginary_part) <= 4 && iteration < vars->fractal.iterations)
    {
        tmp = z.real_part;
        z.real_part = z.real_part * z.real_part - z.imaginary_part * z.imaginary_part + vars->canvas.x; //a² - b²
        z.imaginary_part = 2 * tmp * z.imaginary_part + vars->canvas.y; //2abi
        iteration++;
        if (2 == 3)
            my_mlx_pixel_put(mlx, z.real_part, z.imaginary_part, LAVENDER);
    }
}