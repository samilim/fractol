/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:01:37 by salimon           #+#    #+#             */
/*   Updated: 2021/11/09 08:17:37 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycodes.h"
#include "../includes/colors.h"

//z²+c
//nb complexe = nb i dont le carré est égal à -1 tel que i = racine de -1

static void    Mandelbrot(t_fractal fractal, t_canvas canvas, t_mlx *mlx)
{
    t_complex_nb    z;
    int             iteration;
    double          tmp;

    iteration = 0;
    while((z.real_part * z.real_part + z.imaginary_part * z.imaginary_part) < 2 && iteration < fractal.iterations)
    {
        tmp = z.real_part;
        z.real_part = z.real_part * z.real_part - z.imaginary_part * z.imaginary_part + canvas.x; //a² - b²
        z.imaginary_part = 2 * tmp * z.imaginary_part + canvas.y; //2abi
        iteration++;
        if (/*condition validee*/)
            my_mlx_pixel_put(mlx, z.real_part, z.imaginary_part, LAVENDER);
    }
}