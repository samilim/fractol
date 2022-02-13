/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_management_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 07:37:43 by salimon           #+#    #+#             */
/*   Updated: 2022/02/13 09:04:10 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	get_color(t_vars *vars, int iteration)
{
	if (vars->fractal.palette == 1)
		return (BLACK + iteration * iteration);
	else if (vars->fractal.palette == 2)
		return (RED + iteration * 3000);
	else if (vars->fractal.palette == 3)
		return (PURPLE + iteration * 3000);
	else if (vars->fractal.palette == 4)
		return (WHITE * iteration * 2000);
	else if (vars->fractal.palette == 5)
		return (SEA_GREEN + iteration * 3000);
	else if (vars->fractal.palette == 6)
		return (ORANGE + iteration * 1000);
	else
		return (LAVENDER * iteration * 100);
}
