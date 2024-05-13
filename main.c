/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:03:33 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/13 21:19:39 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"


//REMEMBER TO CHANGE THE MINILIBX 

void error_msg (void)
{
	ft_putendl_fd("Please specify a valid fractol name", 2);
	ft_putendl_fd("***Available fractals***", 2);
	ft_putendl_fd("mandelbrot", 2);
	ft_putendl_fd("julia <x value> <y value>\n", 2);
	ft_putendl_fd("Here some ideas for Julia set!!", 2);
	ft_putendl_fd("julia -0.8 0.156", 2);
	ft_putendl_fd("julia -0.4 0.6", 2);
	
	exit(EXIT_FAILURE);
}

int ft_alpha(char *str)
{
	int i;

	i = 0;

	while(str[i])
	{
		if (!ft_isalpha(str[i]))
			return(1);
		else
			i++;
	}
	return(0);
}



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
	//mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, x, y); //probar sin esto //creo que solo sirve si haces tu propio put pixel
}


void	init_params(t_data *fractal, char *name)
{
	if (ft_strncmp(name, "mandelbrot", 10) == 0) //hay problema si fuciona con otro nombre??
		mandelbrot_param(fractal);
	else if (ft_strncmp(name, "julia", 5) == 0)
		julia_param(fractal);
	//draw_fractal(fractal, name);
}
int main(int argc, char **argv)
{
	t_data	*fractal;

	if (argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10) || !ft_strncmp(argv[1], "julia", 5)) || (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal = (t_data *)malloc(sizeof(t_data));
		if(!fractal)
			EXIT_FAILURE;
		
		
		//PROBAR SIN ESTO
		//fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT); //security si falla 52
		//fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel, &fractal->line_length, &fractal->endian); //fractal->bits_per_pixel, fractal->line_length, fractal->endian??
		
		init_params(fractal, argv[1]);
		
		if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
		{
			if(ft_alpha(argv[2]) == 1 || ft_alpha(argv[3]) == 1)
			{
				printf("%d\n", ft_alpha(argv[2])); //borrar
				printf("%d\n", ft_alpha(argv[3])); //borar
				error_msg();
			}
			fractal->position_c.x = ft_atof(argv[2]);
			fractal->position_c.y = ft_atof(argv[3]);
		}

		fractal->mlx = mlx_init(); // Inicializar la conexión MLX //security si falla 48:50
		fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, argv[1]); //crea la ventana //security si falla 50:50

		draw_fractal(fractal, fractal->name);

		mlx_hook(fractal->win, KeyPress, KeyPressMask, key_handle, fractal);
		mlx_hook(fractal->win, ButtonPress, ButtonPressMask, mouse_handle, fractal);
		mlx_hook(fractal->win, DestroyNotify, StructureNotifyMask, close_handle, fractal); //El tipo específico de evento que estás manejando determina los parámetros que necesitarás en la función de manejo de eventos.
		//mlx_hook(fractal->win, MotionNotify, PointerMotionMask, mouse_move, fractal); //reconoce el movimiento del mouse

		mlx_loop(fractal->mlx);
		free(fractal);
	}
	else
		error_msg();
	return (0);
}
