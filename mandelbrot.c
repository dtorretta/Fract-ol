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

void fractal_mandel(int x, int y, t_data *mandel)
{
    int i;
    double	z_x;
	double	z_y;
	double	tempz_x;
	
	i = 0;
	z_x = 0;
	z_y = 0;
   	
	
	mandel->position_c.x = x * ((1.2 + 2.05) / (mandel->width - 1)) - 2.05;
    mandel->position_c.y = y * (1.2 + 1.3) / (mandel->width - 1) - 1.3;

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