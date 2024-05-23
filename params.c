/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:13:01 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/23 18:13:03 by dtorrett         ###   ########.fr       */
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
	fractal->name = "mandelbrot";
	fractal->color = 0xff9966;
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
	fractal->color = 0xff9966;
	fractal->shift.x = 0;
	fractal->shift.y = 0;
	fractal->name = "julia";
	fractal->bits_per_pixel = 0;
	fractal->line_length = 0;
	fractal->endian = 0;
}
