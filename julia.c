/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:00:45 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/21 18:25:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void fractal_julia(double x, double y, t_data *julia)
{
    int i;
    t_fractal	z;
	double	tempz_x;
	
	i = 0;
	
	
	z.x = x * (2.00 + 1.99) * julia->zoom / WIDTH - 1.99 + (julia->shift.x * julia->zoom);
	z.y = y * (-2.00 - 1.99) * julia->zoom / HEIGHT + 1.99 + (julia->shift.y * julia->zoom);
	
	while(i < julia->iterations && z.x * z.x + z.y * z.y < 4)
    {
		tempz_x = (z.x * z.x) - (z.y * z.y) + julia->position_c.x;
		z.y = 2 * z.x * z.y + julia->position_c.y;
		z.x = tempz_x;
		i++;
    }
    
    my_put_pixel(julia, x, y, i); 
    
    // if (i == julia->iterations) //dentro
    //     mlx_pixel_put(julia->mlx, julia->win, x, y, 0x000000);
    // else //fuera 
    //     mlx_pixel_put(julia->mlx, julia->win, x, y, 0x660066 * i / 100);
        
    // //ft_printf("x= %d, y= %d\n", julia->position_c.x, julia->position_c.y);
        
}

// void	draw_julia(t_data *fractal)
// {
// 	int x;
// 	int y;
	
// 	x = 0;
// 	y = 0;
	
// 	ft_printf("holaaaaaaa\n");
		
		
// 	while (y < WIDTH)
// 	{
// 		while (x < HEIGHT)
// 		{
// 			fractal_julia(x, y, fractal);
// 			x++;
// 		}
// 		y++;
// 		x = 0;
// 	}
// 	//mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, x, y); //probar sin esto //creo que solo sirve si haces tu propio put pixel
// }

