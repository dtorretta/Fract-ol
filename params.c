/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:18:31 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/21 20:28:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	mandelbrot_param(t_data *fractal)
{
	fractal->iterations = 50;
	fractal->zoom = 1;	
    fractal->position_c.x = 0;
    fractal->position_c.y = 0;
	fractal->shift.x = 0;
	fractal->shift.y = 0;
	// fractal->track.x = 0; //borrar??
	// fractal->track.y = 0;
	fractal->name = "mandelbrot";
	fractal->color = 0xff9966; //0xfcbe11; //0x660033;
	
	fractal->bits_per_pixel = 0;
	fractal->line_length = 0;
	fractal->endian = 0;
}
void	julia_param(t_data *fractal)
{
	fractal->iterations = 100;
	fractal->zoom = 1;
    fractal->position_c.x = -0.8;
    fractal->position_c.y = 0.156;
	fractal->color = 0x660066 / 100;
	fractal->shift.x = 0;
	fractal->shift.y = 0;
	// fractal->track.x = 0; //probar ccon 1
	// fractal->track.y = 0; //probar con 1
	fractal->name = "julia";	
	fractal->bits_per_pixel = 0;
	fractal->line_length = 0;
	fractal->endian = 0;
}
