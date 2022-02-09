/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 07:37:43 by salimon           #+#    #+#             */
/*   Updated: 2022/02/09 07:06:01 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycodes.h"
#include "../includes/colors.h"

//You must use at least a few colors to show the depth of each fractal. It’s even better f you hack away on psychedelic effects

int greenish(int iteration)
{
    if (iteration < 10)
        return (SEA_GREEN);
    if (iteration < 30)
        return (DARK_SLATE_GRAY);
    if (iteration < 50)
        return (LIME);
    if (iteration < 60)
        return (OLIVE);
    if (iteration < 80)
        return (MISTY_ROSE);
    if (iteration < 100)
        return (PURPLE);
    return (BLACK);
}

int redish(int iteration)
{
    if (iteration < 10)
        return (RED);
    if (iteration < 30)
        return (ORANGE);
    if (iteration < 50)
        return (BEIGE);
    if (iteration < 60)
        return (CRIMSON);
    if (iteration < 80)
        return (MISTY_ROSE);
    if (iteration < 100)
        return (YELLOW);
    return (BLACK);
}

int rainbow(int iteration)
{
    if (iteration < 5)
        return (BEIGE);
    if (iteration < 10)
        return (CORAL);
    if (iteration < 20)
        return (PURPLE);
    if (iteration < 30)
        return (RED);
    if (iteration < 40)
        return (GREEN);
    if (iteration < 60)
        return (BLUE);
    if (iteration < 80)
        return (YELLOW);
    if (iteration < 100)
        return (MAGENTA);
    if (iteration < 150)
        return (ALICE_BLUE);
    if (iteration < 200)
        return (CYAN);
    if (iteration < 300)
        return (SALMON);
    if (iteration < 500)
        return (SADDLEBROWN);
    return (BLACK);
}

int     get_color(t_vars *vars, int iteration)
{
    if (vars->fractal.palette == 1)
        return (greenish(iteration));
    if (vars->fractal.palette == 2)
        return (redish(iteration));
    if (vars->fractal.palette == 3)
        return (rainbow(iteration));
    else
        return (WHITE);
}

