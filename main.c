/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:03:33 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/22 00:33:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

//color_info es un puntero calculado que apunta a una ubicación específica en el buffer de datos. Cuando escribes en *(unsigned int *)color_info, estás escribiendo directamente en la memoria en esa ubicación.
//estás calculando la dirección exacta dentro del buffer de la imagen donde se encuentra el píxel en la posición (x, y).
//estás escribiendo un valor de tipo unsigned int en la dirección de memoria apuntada por color_info. Este valor sobrescribe cualquier dato que ya estaba en esa posición de memoria.
void	draw_fractal(t_data *fractal, char *name)
{
	int x;
	int y;
	
	x = 0;
	y = 0;	
	mlx_clear_window(fractal->mlx, fractal->win);//??
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
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
void	init_params(t_data *fractal, char *name)
{
	if (ft_strncmp(name, "mandelbrot", 10) == 0)
		mandelbrot_param(fractal);
	else if (ft_strncmp(name, "julia", 5) == 0)
		julia_param(fractal);
}
int mlx_utils_init(t_data *fractal, char *name)
{
	fractal->mlx = mlx_init();
	if(fractal->mlx == NULL)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal);
		exit (EXIT_FAILURE);
	}
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, name);
	if(fractal->win == NULL)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal);
		exit (EXIT_FAILURE);
	}
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if(fractal->img == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_display(fractal->mlx);
		free(fractal);
		exit (EXIT_FAILURE);
	}
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel, &fractal->line_length, &fractal->endian);
	return(0);
}
void julia(t_data *fractal, char **argv)
{
	ft_num(argv[2], fractal);
	ft_num(argv[3], fractal);
	fractal->position_c.x = ft_atof(argv[2]);
	fractal->position_c.y = ft_atof(argv[3]);
	if(fractal->position_c.x > 2 || fractal->position_c.x < -2 || fractal->position_c.y > 2 || fractal->position_c.y < -2)
	{
		free(fractal);
		error_msg();
	}
}

int main(int argc, char **argv)
{
	t_data	*fractal;

	if ((argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10) || !ft_strncmp(argv[1], "julia", 5))) || (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal = (t_data *)malloc(sizeof(t_data));
		if(!fractal)
			exit (EXIT_FAILURE);
		init_params(fractal, argv[1]);
		if (argc == 4)
			julia(fractal, argv);
		mlx_utils_init(fractal, argv[1]);
		draw_fractal(fractal, fractal->name);
		mlx_hook(fractal->win, KeyPress, KeyPressMask, key_handle, fractal);
		mlx_hook(fractal->win, ButtonPress, ButtonPressMask, mouse_handle, fractal);
		mlx_hook(fractal->win, DestroyNotify, StructureNotifyMask, close_handle, fractal); //El tipo específico de evento que estás manejando determina los parámetros que necesitarás en la función de manejo de eventos.
		mlx_loop(fractal->mlx);
		free(fractal->mlx);
		free(fractal);
	}
	else
		error_msg();
	return (0);
}
