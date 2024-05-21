/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 00:01:30 by marvin            #+#    #+#             */
/*   Updated: 2024/05/10 00:01:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int mouse_handle(int button, int x, int y, t_data *fractal)
{
	if (button == Button4) //zoom in
	{
		fractal->zoom *= 0.75; 
	}
	else if (button == Button5) //zoom out
		fractal->zoom *= 1.25;
		
	draw_fractal(fractal, fractal->name);
	return(0);
}

// int mouse_move(int x, int y, t_data *fractal) //todo
// {
//   if(!strncmp(fractal->name, "julia", 5))
//   {
// 	//fractal->position_c.x  = x * (2.00 + 1.99) /* * fractal->zoom*/ / WIDTH - 1.99 /* + (fractal->shift.x * fractal->zoom) */;
// 	//fractal->position_c.y = y * (-2.00 - 1.99) /* * fractal->zoom */ / HEIGHT + 1.99 /* + (fractal->shift.y * fractal->zoom) */;
    
//     fractal->track.x = x * (2.00 + 1.99) / WIDTH - 1.99; /* + (fractal->shift.x * fractal->zoom);*/
// 	fractal->track.y = y * (-2.00 - 1.99) / WIDTH + 1.99; /* + (fractal->shift.x * fractal->zoom);*/
      
      
//     draw_fractal(fractal, fractal->name);	
//   }
// 	return(0);
// }

int key_handle(int keycode, t_data *fractal)
{
    if (keycode == XK_Escape) //corregir
		close_handle (fractal);
    else if (keycode == XK_KP_Add)
		fractal->iterations += 25;
    else if (keycode == XK_KP_Subtract)
		fractal->iterations -= 25;
    else if (keycode == XK_Up)
        fractal->shift.y += 0.25;
    else if (keycode == XK_Down) 
		fractal->shift.y -= 0.25;
    else if (keycode == XK_Right)
		fractal->shift.x += 0.25;
    else if (keycode == XK_Left)
		fractal->shift.x -= 0.25;
	else if (keycode == XK_space && !strncmp(fractal->name, "mandelbrot", 10))
        fractal->color += 1000;
	else if (keycode == XK_a && !strncmp(fractal->name, "julia", 5))
	{
        fractal->position_c.x += 0.05;
        fractal->position_c.y -= 0.05;
	}
	else if (keycode == XK_s && !strncmp(fractal->name, "julia", 5))
	{
        fractal->position_c.x -= 0.05;
        fractal->position_c.y += 0.05;
	}

	    
          
			
	draw_fractal(fractal, fractal->name);	
  return (0);
}

int close_handle(t_data *fractal)
{
  //mlx_destroy_image(fractal->mlx, fractal->img);
  mlx_destroy_window (fractal->mlx, fractal->win);
  free(fractal);
  exit(0); //sin el exit me da segfault
  //mlx_destroy_display (fractal->mlx);
}
