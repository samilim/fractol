/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 07:37:43 by salimon           #+#    #+#             */
/*   Updated: 2022/02/13 05:50:44 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int     get_color(t_vars *vars, int iteration)
{
	if (vars->fractal.palette == 1)
		return (SEA_GREEN);
	else if (vars->fractal.palette == 2)
		return (RED);
	else if (vars->fractal.palette == 3)
		return (PURPLE);
	else if (vars->fractal.palette == 4)
		return (PURPLE);
	else if (vars->fractal.palette == 5)
		return (PURPLE);
	else if (vars->fractal.palette == 6)
		return (PURPLE);
	else if (vars->fractal.palette == 7)
		return (PURPLE);
	else if (vars->fractal.palette == 8)
		return (PURPLE);
	else if (vars->fractal.palette == 9)
		return (PURPLE);
	else
		return (WHITE);
}
