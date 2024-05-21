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


//Here we scale down the square (width * height) to (max 2.00 * min - 1.99) 
//x is the pixel in the map in the (width * height) that we wanna scale
//x * (max - min) / width + min
//-1.99 para centrar el conjunto de Mandelbrot en el plano complejo. 

//in Y axes the max value is negative and the min is positive. x --> (min, max) --> (-2, 2) & y --> (min, max) --> (2, -2)

//if x^2 + y^2 > 4 stop iterating. if we create an imaginary triangle taking the point (x,y) and (0,0) we can calculate its hypotenuse. 
//considering the max 2.00 and min -1.99, if its calculation is > 4 I asume that the point escapes.

void fractal_mandel(int x, int y, t_data *mandel)
{
	int i;
	double	z_x;
	double	z_y;
	double	tempz_x;
	
	i = 0;
	z_x = 0;
	z_y = 0;
   	
   	mandel->position_c.x = x * (2.00 + 1.99) * mandel->zoom / WIDTH - 1.99 + (mandel->shift.x * mandel->zoom);
	mandel->position_c.y = y * (-2.00 - 1.99) * mandel->zoom / HEIGHT + 1.99 + (mandel->shift.y * mandel->zoom);

	while(i < mandel->iterations && z_x * z_x + z_y * z_y < 4)
	{
		tempz_x = z_x * z_x - z_y * z_y + mandel->position_c.x;
		z_y = 2.0 * z_x * z_y + mandel->position_c.y;
		z_x = tempz_x;
		i++;
	}
	
	my_put_pixel(mandel, x, y, i); //es necesario enviar el color???
	// float t = (float)i / (float)mandel->iterations;
	// int color = interpolateColor(mandel->base_color_1, mandel->base_color_2, t);
	
	// if (i == mandel->iterations) //dentro
	// 	mlx_pixel_put(mandel->mlx, mandel->win, x, y, 0x000000);
	// else //fuera 
	// 	//mlx_pixel_put(mandel->mlx, mandel->win, x, y, color);
	// 	//mlx_pixel_put(mandel->mlx, mandel->win, x, y, mandel->color * i / 100);
	// 	mlx_put_image_to_window(mandel->mlx, mandel->win, mandel->img, x, y);
}
