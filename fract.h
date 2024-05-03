/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:01:45 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/03 19:42:38 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "libft/libft.h"
# include "./libmlx/mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_fractal
{
    double x;
    double y;
}           t_fractal;

typedef struct l_fractal {
	char		*name;
	void		*img;
	void		*addr; //ver mlx_get_data_addr -  para obtener la dirección del primer byte de la imagen en memoria asignada por la función mlx_new_image
	int			bits_per_pixel; //r mlx_get_data_addr - puntero a un entero donde se almacenará el número de bits por píxel de la imagen.
	int			line_length; //ver mlx_get_data_addr - puntero a un entero donde se almacenará el tamaño en bytes de una línea de píxeles de la imagen.
	int			endian; //ver mlx_get_data_addr - puntero a un entero donde se almacenará el valor del endian de la arquitectura (0 para big endian, 1 para little endian).
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_fractal	position_c;
	double		zoom;
	//double		xarrow;
	//double		yarrow;
	double		radius; //ver
	int			iterations; 
	int			color;
}				t_data;



void	mandelbrot_param(t_data *fractal);
void	julia_param(t_data *fractal);

void fractal_mandel(int x, int y, t_data *mandel);

#endif