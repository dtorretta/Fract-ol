/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:35:10 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/23 18:35:10 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

// It iterates through a series of calculations to determine whether
// the given point belongs to the Mandelbrot set.
// It scales down the square (width * height) to (max 2.00 * min - 1.99)
// x is the pixel in the map in the (width * height) that needs to be scale
// x * (max - min) / width + min
// (-1.99 || +1.99) is added to center the fractal on the complex plane.
// In Y axes the max value is negative and the min is positive.
// (min, max) x --> (-2, 2) || y --> (2, -2)
// if x^2 + y^2 > 4 stop iterating. if we create an imaginary triangle
// taking the point (x,y) and (0,0) we can calculate its hypotenuse.
// Considering the max 2.00 and min -1.99, if its calculation is > 4
// we can asume that the point escapes.
// The resulting color is then displayed on the screen using my_put_pixel
void	fractal_mandel(int x, int y, t_data *mandel)
{
	int		i;
	double	z_x;
	double	z_y;
	double	tempz_x;

	i = 0;
	z_x = 0;
	z_y = 0;
	mandel->position_c.x = x * (2.00 + 1.99) * mandel->zoom / WIDTH - (1.99
			* mandel->zoom) + (mandel->shift.x * mandel->zoom);
	mandel->position_c.y = y * (-2.00 - 1.99) * mandel->zoom / HEIGHT + (1.99
			* mandel->zoom) + (mandel->shift.y * mandel->zoom);
	while (i < mandel->iterations && z_x * z_x + z_y * z_y < 4)
	{
		tempz_x = z_x * z_x - z_y * z_y + mandel->position_c.x;
		z_y = 2.0 * z_x * z_y + mandel->position_c.y;
		z_x = tempz_x;
		i++;
	}
	my_put_pixel(mandel, x, y, i);
}
