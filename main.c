/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:03:33 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/21 18:42:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"


//REMEMBER TO CHANGE THE MINILIBX 

//color_info es un puntero calculado que apunta a una ubicación específica en el buffer de datos. Cuando escribes en *(unsigned int *)color_info, estás escribiendo directamente en la memoria en esa ubicación.
//estás calculando la dirección exacta dentro del buffer de la imagen donde se encuentra el píxel en la posición (x, y).
//estás escribiendo un valor de tipo unsigned int en la dirección de memoria apuntada por color_info. Este valor sobrescribe cualquier dato que ya estaba en esa posición de memoria.
void    my_put_pixel(t_data *fractal, int x, int y, int iterations)
{
	char    *color_info;
 
    color_info = fractal->addr + (y * fractal->line_length) + (x * (fractal->bits_per_pixel / 8));
    
    if (iterations == fractal->iterations) //dentro
        *(unsigned int *)color_info = 0x000000;
	else //fuera 
		*(unsigned int *)color_info = fractal->color * iterations;
}

void error_msg (void)
{
	ft_putendl_fd("Please specify a valid fractol name", 2);
	ft_putendl_fd("\n***Available fractals***", 2);
	ft_putendl_fd("mandelbrot", 2);
	ft_putendl_fd("julia <x value> <y value>\n", 2);
	ft_putendl_fd("Here some ideas for Julia set!!", 2);
	ft_putendl_fd("julia  0.285  0.01", 2);
	ft_putendl_fd("julia  -0.4  0.6", 2);
	
	exit(EXIT_FAILURE);
}

int ft_num(char *str)
{
	int i;

	i = 0;	
	if (str[0] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		error_msg();
	else
		i++;
	if ((str[i]) == '.')
		i++;
		
	while(str[i])
	{
		if (!ft_isdigit(str[i]))
		{	
			//printf("pre error %c\n", str[i]);
			error_msg();
		}
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
	
	mlx_clear_window(fractal->mlx, fractal->win); //??

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
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0); //porqu 0 0?
}
void	init_params(t_data *fractal, char *name)
{
	if (ft_strncmp(name, "mandelbrot", 10) == 0) //hay problema si fuciona con otro nombre??
		mandelbrot_param(fractal);
	else if (ft_strncmp(name, "julia", 5) == 0)
		julia_param(fractal);
}
int main(int argc, char **argv)
{
	t_data	*fractal;

	if (argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10) || !ft_strncmp(argv[1], "julia", 5)) || (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal = (t_data *)malloc(sizeof(t_data));
		if(!fractal)
			EXIT_FAILURE;
		
		init_params(fractal, argv[1]);
		
		if (argc == 4)
		{
			ft_num(argv[2]);
			ft_num(argv[3]);
			fractal->position_c.x = ft_atof(argv[2]);
			fractal->position_c.y = ft_atof(argv[3]);
			if(fractal->position_c.x> 2 || fractal->position_c.x < -2 || fractal->position_c.y > 2 || fractal->position_c.y < -2)
				error_msg();
		}

		fractal->mlx = mlx_init(); // Inicializar la conexión MLX //security si falla 48:50
		fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, argv[1]); //crea la ventana //security si falla 50:50
		if(fractal->win == NULL)
		{
			mlx_destroy_display(fractal->mlx);
			free(fractal->mlx);
			EXIT_FAILURE;
			//malloc error???
		}
		
		//PROBAR SIN ESTO
		fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT); //security si falla 52
		if(fractal->img == NULL)
		{
			mlx_destroy_window(fractal->mlx, fractal->win);
			mlx_destroy_display(fractal->mlx);
			free(fractal->mlx);
			EXIT_FAILURE;
			//malloc error???
		}
		fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel, &fractal->line_length, &fractal->endian); //fractal->bits_per_pixel, fractal->line_length, fractal->endian??
		

		draw_fractal(fractal, fractal->name);

		//HOOKS//
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
