/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:01:45 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/21 20:32:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "libft/libft.h"
# include "./libmlx/mlx.h"
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>


# define WIDTH 1000
# define HEIGHT 1000


	
typedef struct s_fractal
{
    double x;
    double y;
}           t_fractal;

typedef struct l_fractal {
	char		*name;
	void		*img; //pixel buffer
	void		*mlx;
	void		*win;
	void		*addr; //ver mlx_get_data_addr -  para obtener la dirección del primer byte de la imagen en memoria asignada por la función mlx_new_image
	int			bits_per_pixel; //r mlx_get_data_addr - puntero a un entero donde se almacenará el número de bits por píxel de la imagen.
	int			line_length; //ver mlx_get_data_addr - puntero a un entero donde se almacenará el tamaño en bytes de una línea de píxeles de la imagen.
	int			endian; //ver mlx_get_data_addr - puntero a un entero donde se almacenará el valor del endian de la arquitectura (0 para big endian, 1 para little endian). no lo usamos 
	t_fractal	position_c;
	t_fractal	shift;
	t_fractal	track;
	double		zoom;
	//double		xarrow;
	//double		yarrow;
	double		radius; //ver
	int			iterations;
	int			color;
	int			base_color_1;
	int			base_color_2;
}				t_data;


/* MANDELBROT */
void	fractal_mandel (int x, int y, t_data *mandel);
//void	draw_fractal(t_data *fractal, char *name);
//void	draw_mandelbrot(t_data *fractal);

/* JULIA */
void fractal_julia(double x, double y, t_data *julia);
//void	draw_julia(t_data *fractal);

/* PARAMS */
void	mandelbrot_param(t_data *fractal);
void	julia_param(t_data *fractal);

/* EVENTS */
int mouse_handle(int button, int x, int y, t_data *fractal);
int key_handle(int keycode, t_data *fractal);
int close_handle(t_data *fractal);
//int mouse_move(int x, int y, t_data *fractal);

/* MAIN */
void	draw_fractal(t_data *fractal, char *name);
void    my_put_pixel(t_data *fractal, int x, int y, int iterations);


#endif