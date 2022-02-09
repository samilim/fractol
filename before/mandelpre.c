/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:01:37 by salimon           #+#    #+#             */
/*   Updated: 2022/02/09 06:01:07 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycodes.h"
#include "../includes/colors.h"
#include <math.h>

/*
* Pour chaque pixel, trouver 
* les valeurs réelle et imaginaire pour p, correspondant au x, y et z de l'image. 
* Trouver le nb d'itérations dans la formule Mandelbrot en utilisant p.
* L'axe x représente la partie réelle, l'axe y la partie imaginaire.
*
* Formule Mandelbrot : 
* Il sagit d'un set de complexes c sur lesquels la fonction z = z² + c ne diverge pas quand
* itérée à partir de 0.
* EX : sur un canvas avec -3 et 3 en valeurs respectivement min et max pour les parties réelles et imaginaires;
* c en lui même est un nb complexe (a + ib)
* les pixels imprimés seront ceux correspondants au c qui tendent à ne pas diverger, ne pas tendre vers l'infini
* (a + ib) * (a + ib) + c donnera les composants de la prochaine itération
* a² - b² donne la partie aa
* 2ab donna le partie bb
* si la valeur absolue du nombre complexe c sur lequel on applique iter fois (z = z² + c) ne diverge pas sur toutes les iterations 
* avant que le nombre d'iteration max soit atteint, il sera compris dans 
* l'ensemble de Mandelbrot et donc imprimé
* Le set de Mandelbrot s'étend sur un radius de 2. UN point appartient au set seulement si 
* Autrement dit, si la valeur absolue devient > 2, la sequence s'étendra vers l'infini
* scaling :
*/

static void    next_z(t_complex_nb *z, t_complex_nb *c)
{
    double nz;

    nz = z->real_part * z->real_part - z->imaginary_part * z->imaginary_part + c->real_part;
    z->imaginary_part = 2 * z->real_part * z->imaginary_part + c->imaginary_part;
    z->real_part = nz;
}

//pour opti calcul ?

double    magnitude(t_complex_nb *complex)
{
    double sq;
    
    sq = sqrt((complex->real_part * complex->real_part) + (complex->imaginary_part * complex->imaginary_part));
    return (sq);
}

void    Mandelbrot(t_vars *vars)
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
