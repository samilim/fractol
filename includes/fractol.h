/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:54:36 by salimon           #+#    #+#             */
/*   Updated: 2022/02/13 08:15:19 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
//# include <mlx.h>
//# include <mlx_int.h>
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../includes/keycodes.h"
# include "../includes/colors.h"

# define WIN_HEIGHT 600
# define WIN_WIDTH 600

/*
** r = real part
** i = imaginary part
*/

typedef struct s_complex_nb
{
	double	r;
	double	i;
	double	magnitude;	
}				t_complex_nb;

/*
** Fractal's datas
*/

typedef struct s_fractal
{
	int				set;
	int				max_iteration;
	double			r_min;
	double			r_max;
	int				palette;
	int				arg;
}				t_fractal;

/*
** Coordinate system to know where to put the pixel in the window
*/

typedef struct s_canvas
{
	int		x;
	int		y;
	int		pos_x;
	int		pos_y;
	double	ww_half;
	double	wh_half;
	double	r_factor;
	double	i_factor;
	double	zoom;
}				t_canvas;

/*
** Mlx datas
** mlx		; establish a connection to the correct graphical system ans
** 		will return a void * which holds the location of our current MLX instance
** win 		; windows id
** image	; return a pointer to the window we have just created.
** 		We can give the window height, width and a title.
** 		We then will have to call mlx_loop to initiate the window rendering
** addr		; memory address on which we will mutate the bytes accordingly
** bpp		; bits per pixel
** endian	;
*/

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

typedef struct s_vars
{
	int			argc;
	char		**argv;
	t_fractal	fractal;
	t_canvas	canvas;
	t_mlx		mlx;
}				t_vars;

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	init_window(t_vars *vars);
void	init_image(t_vars *vars);
int		get_color(t_vars *vars, int iteration);
int		key_hook(int keycode, t_vars *vars);
int		left_click(int keycode, int x, int y, t_vars *vars);
int		mouse_hook(int keycode, int x, int y, t_vars *vars);
void	display_fractal(t_vars *vars);
int		mouse_exit_window(t_vars *vars);
/*
** Fractal algorithms
*/
void	mandelbrot(t_vars *vars);
void	julia(t_vars *vars);
void	mandelbar(t_vars *vars);
void	burning_ship(t_vars *vars);

#endif