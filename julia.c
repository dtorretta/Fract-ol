/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:00:45 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/06 21:18:08 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void fractal_julia(double x, double y, t_data *julia)
{
    int i;
    double	z_x;
	double	z_y;
	double	tempz_x;
	
	i = 0;
	z_x = 0;
	z_y = 0;
   	
	//julia->position_c.x = x * ((1.0 + 2.00) / (julia->width - 1)) - 2.00;
    //julia->position_c.y = y * (1.2 + 1.3) / (julia->height - 1) - 1.3;

	//julia->position_c.x = x * ((1.0 + 2.00) / julia->zoom + ;
    //julia->position_c.y = y * (1.2 + 1.3) / (julia->height - 1) - 1.3;
    
	z_x = 1.5 * (x - julia->width / 2) / (0.3 * julia->zoom *
				julia->width);
    z_y = (y - julia->height / 2) / (0.3 * julia->zoom *
				julia->height);
    
    while(i < julia->iterations && z_x * z_x + z_y * z_y < 4)
    {
        tempz_x = z_x;
        z_x = tempz_x * tempz_x - z_y * z_y + julia->position_c.x;
		z_y = 2.0 * tempz_x * z_y + julia->position_c.y;
		i++;
    }

    if (i < julia->iterations) //fuera
        mlx_pixel_put(julia->mlx, julia->win, x, y, julia->color * i / 100);
    /*if (i == julia->iterations) //dentro
        mlx_pixel_put(julia->mlx, julia->win, x, y, 0x000000);
    else //fuera 
        mlx_pixel_put(julia->mlx, julia->win, x, y, julia->color * i / 100);*/
}

void	draw_julia(t_data *fractal)
{
	double x;
	double y;
    
	x = 0.0; //-0.966;
	y = 0.0; //0.02
    
	while (x < fractal->width)
	{
		while (y < fractal->height)
		{
			fractal_julia(x, y, fractal);
			y++;
		}
		y = 0;
		x++;
	}
}
