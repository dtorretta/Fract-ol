/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:04:37 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/02 19:04:37 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	fractal_mandel (int x, int y, t_data *mandel)
{
    int i;
    double	z_x;
	double	z_y;
	double	tempz_x;
	
	i = 0;
	z_x = 0;
	z_y = 0;
   	
	//El valor de x (el punto en el mapa) se multiplica por el factor de escala, que es la diferencia entre el límite superior e inferior del rango deseado (1.0 + 2.00) (rango total del eje x)
    //y se divide por el total del ancho - 1 porque los índices de píxeles generalmente comienzan desde 0 en los lenguajes de programación.
    //-2.0 para centrar el conjunto de Mandelbrot en el plano complejo. 
	mandel->position_c.x = x * ((1.0 + 2.00) / (mandel->width - 1)) - 2.00;
    mandel->position_c.y = y * (1.2 + 1.3) / (mandel->height - 1) - 1.3;

    while(i < mandel->iterations && z_x * z_x + z_y * z_y < 4)
    {
        tempz_x = z_x * z_x - z_y * z_y + mandel->position_c.x;
		z_y = 2.0 * z_x * z_y + mandel->position_c.y;
		z_x = tempz_x;
		i++;
    }

    if (i == mandel->iterations) //dentro
        mlx_pixel_put(mandel->mlx, mandel->win, x, y, 0x000000);
    else //fuera 
        mlx_pixel_put(mandel->mlx, mandel->win, x, y, mandel->color * i / 100);
}

void	draw_mandelbrot(t_data *fractal)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (x < fractal->width)
	{
		while (y < fractal->height)
		{
			fractal_mandel(x, y, fractal);
			y++;
		}
		y = 0;
		x++;
	}
}
