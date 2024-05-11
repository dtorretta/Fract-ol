/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:03:33 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/11 15:49:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
//REMEMBER TO CHANGE THE MINILIBX 

void	draw_fractal(t_data *fractal, char *name)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			if (!ft_strncmp(name, "mandelbrot", 10))
				fractal_mandel(x, y, fractal);
			else if (!ft_strncmp(name, "julia", 5))
				fractal_julia(x, y, fractal);
			y++;
		}
		y = 0;
		x++;
	}
	//ft_printf("x= %d, y= %d\n", fractal->position_c.x, fractal->position_c.y);
	//mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, x, y); //probar sin esto //creo que solo sirve si haces tu propio put pixel
}


void	init_params(t_data *fractal, char *name)
{
	if (ft_strncmp(name, "mandelbrot", 10) == 0) //hay problema si fuciona con otro nombre??
		mandelbrot_param(fractal);
	else if (ft_strncmp(name, "julia", 5) == 0)
		julia_param(fractal);
	draw_fractal(fractal, name);
}
int main(int argc, char **argv)
{
	t_data	*fractal;

	if (argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10) || !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal = (t_data *)malloc(sizeof(t_data));
		if(!fractal)
			EXIT_FAILURE;
		fractal->mlx = mlx_init(); // Inicializar la conexión MLX //security si falla 48:50
		fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, argv[1]); //crea la ventana //security si falla 50:50
		
		//PROBAR SIN ESTO
		//fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT); //security si falla 52
		//fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel, &fractal->line_length, &fractal->endian); //fractal->bits_per_pixel, fractal->line_length, fractal->endian??
		
		init_params(fractal, argv[1]);
		
		
		//cada interaccion del mouse o teclado son eventos 1:28
		mlx_hook(fractal->win, KeyPress, KeyPressMask, key_handle, fractal); //donde se define que variables va a tener la funcion key_handler?
		mlx_hook(fractal->win, ButtonPress, ButtonPressMask, mouse_handle, fractal);
		//mlx_hook(fractal->win, MotionNotify, PointerMotionMask, mouse_move, fractal); //reconoce el movimiento del mouse
		mlx_hook(fractal->win, DestroyNotify, StructureNotifyMask, close_handle, fractal); //El tipo específico de evento que estás manejando determina los parámetros que necesitarás en la función de manejo de eventos.

		mlx_loop(fractal->mlx);
		free(fractal);
	}
	else
		ft_putendl_fd("Please specify a valid name of the fractol \"mandelbrot\", \"julia\"", 1);
	return (0);
}
