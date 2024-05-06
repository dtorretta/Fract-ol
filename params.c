/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:18:31 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/06 20:49:49 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	mandelbrot_param(t_data *fractal)
{
    fractal->width = 1000;
	fractal->height = 1000;
	fractal->iterations = 100;
	fractal->zoom = 200;	
    fractal->position_c.x = 0;
    fractal->position_c.y = 0;
	//fractal->xarrow = 0; //no entiendo
	//fractal->yarrow = 270; //no entiendo
	fractal->color = 0xfffff;
	fractal->name = "mandel";

	draw_mandelbrot(fractal);
}
void	julia_param(t_data *fractal)
{
    fractal->width = 1000;
	fractal->height = 1000;
	fractal->iterations = 100;
	fractal->zoom = 200;	
    fractal->position_c.x = -0.966;
    fractal->position_c.y = 0.02;
	//fractal->xarrow = 0; //no entiendo
	//fractal->yarrow = 270; //no entiendo
	fractal->color = 0xfffff;
	fractal->name = "julia";

	draw_julia(fractal);
}
