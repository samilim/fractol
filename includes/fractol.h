/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:54:36 by salimon           #+#    #+#             */
/*   Updated: 2022/02/09 02:26:21 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
//# include <mlx.h>
# include <math.h>

#include <string.h>

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../includes/keycodes.h"
# include "../includes/colors.h"

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

typedef	struct s_complex_nb
{
	double	real_part;
	double	imaginary_part;
	double	magnitude;
	
}				t_complex_nb;

/*
** Fractal's datas
*/

typedef	struct s_fractal
{
	const char		*set;
	int				max_iteration;
	int				palette;
}				t_fractal;

/*
** Coordinate system to know where to put the pixel in the window
*/

typedef	struct s_canvas
{
	int	x;
	int y;
}				t_canvas;


/*
** Mlx datas
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

typedef struct	s_vars
{
	t_fractal	fractal;
    t_canvas	canvas;
	t_mlx		mlx;
}				t_vars;

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int     get_color(t_vars *vars, int iteration);
int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int keycode, t_vars *vars);
/*
** Fractal algorithms
*/
void   	Mandelbrot(t_vars *vars);
void    Julia(t_vars *vars);

#endif