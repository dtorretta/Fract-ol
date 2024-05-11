/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:18:31 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/11 15:46:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	mandelbrot_param(t_data *fractal)
{
	fractal->iterations = 50;
	fractal->zoom = 1;	
    fractal->position_c.x = 0;
    fractal->position_c.y = 0;
	fractal->base_color_1 = 0x0d0d0d;
	fractal->base_color_2 = 0xffffff;
	fractal->shift.x = 0;
	fractal->shift.y = 0;
	fractal->track.x = 0;
	fractal->track.y = 0;
	fractal->name = "mandelbrot";
	fractal->color = 0x660033;

	//draw_mandelbrot(fractal);
}
void	julia_param(t_data *fractal)
{
	fractal->iterations = 100;
	fractal->zoom = 1;
    fractal->position_c.x = -0.8;
    fractal->position_c.y = 0.156;
    //fractal->position_c.x = -2.0;
    //fractal->position_c.y = 2.0;
	//fractal->color = 0x660066;
	fractal->shift.x = 0;
	fractal->shift.y = 0;
	fractal->track.x = 0;
	fractal->track.y = 0;
	fractal->name = "julia";

	//draw_julia(fractal);
}
