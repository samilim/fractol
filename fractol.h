/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:54:36 by salimon           #+#    #+#             */
/*   Updated: 2021/11/08 08:09:26 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "mlx_linux/mlx.h"

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800

typedef struct	s_vars
{
    int keycode;
}				t_vars;

typedef	struct s_complex_nb
{
	double	real_part;
	double	imaginary_part;
	
}				t_complex_nb;

/*
** Fractal's datas
*/

typedef	struct s_fractal
{
	int				iterations;
	t_complex_nb	min;
	t_complex_nb	max;
}				t_fractal;


/*
** Mlxes datas
** mlx		; establish a connection to the correct graphical system and will return a void * which holds the location of our current MLX instance
** win 		; windows id
** image	; return a pointer to the window we have just created. We can give the window height, width and a title. We then will have to call mlx_loop to initiate the window rendering
** addr		; memory address on which we will mutate the bytes accordingly
** bpp		;
** endian	;
*/

typedef struct  s_mlx
{
    void	*mlx;
	void	*win;
	void    *img;
	char    *addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}				t_mlx;


int	close_win(int keycode, t_mlx *mlx);

#endif