/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:14:02 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/23 18:14:04 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

// The draw_fractal function is responsible for rendering the fractal image.
// It clears the window and iterates over each pixel
// within the specified width and height.
// Depending on the fractal name, it calls the corresponding function
// to calculate and set the pixel values in the image.
// Finally, it displays the image in the window.
void	draw_fractal(t_data *fractal, char *name)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_clear_window(fractal->mlx, fractal->win);
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

// init: Initialize the MLX library
// new_window: create a new window with the specified width, height and name
// new_image: create a new image with the specified width and height
// get_data_addr: get the address to the image data buffer.
// it will store in the pointers bits_per_pixel, line_length and endian,
// the corrects values depending of the operative system and the specific image
// format used by the MLX library
// BPP: is the number of bits used to represent a single pixel in the image
// line len: is the number of bytes used to store a single row of pixels
// endian: is the byte order used to represent pixel color values
int	mlx_utils_init(t_data *fractal, char *name)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal);
		exit(EXIT_FAILURE);
	}
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, name);
	if (fractal->win == NULL)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal);
		exit(EXIT_FAILURE);
	}
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (fractal->img == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_display(fractal->mlx);
		free(fractal);
		exit(EXIT_FAILURE);
	}
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	return (0);
}
void	julia(t_data *fractal, char **argv)
{
	ft_num(argv[2], fractal);
	ft_num(argv[3], fractal);
	fractal->position_c.x = ft_atof(argv[2]);
	fractal->position_c.y = ft_atof(argv[3]);
	if (fractal->position_c.x > 2 || fractal->position_c.x < -2
		|| fractal->position_c.y > 2 || fractal->position_c.y < -2)
	{
		free(fractal);
		error_msg();
	}
}

// Check if the number of arguments is correct and if the fractal type is valid
// Allocates memory for a fractal data structure to store the parameters
// Initializes fractal parameters based on user input.
// If 4 arguments are provided, initialize specific parameters for Julia
// Initializes MLX (MiniLibX) utilities.
// Draws the selected fractal on the window.
// Set hooks (event handlers) for key presses, mouse clicks, and window close
// The type of event determines the parameters needed in the event handling fx.
// Enters the MLX event loop to keep the window open and responsive.
// Cleans up by freeing allocated memory before exiting the program.
int	main(int argc, char **argv)
{
	t_data	*fractal;

	if ((argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10)
				|| !ft_strncmp(argv[1], "julia", 5))) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal = (t_data *)malloc(sizeof(t_data));
		if (!fractal)
			exit(EXIT_FAILURE);
		init_params(fractal, argv[1]);
		if (argc == 4)
			julia(fractal, argv);
		mlx_utils_init(fractal, argv[1]);
		draw_fractal(fractal, fractal->name);
		mlx_key_hook(fractal->win, key_handle, fractal);
		mlx_mouse_hook(fractal->win, mouse_handle, fractal);
		mlx_hook(fractal->win, DestroyNotify, 0, close_handle, fractal);
		mlx_loop(fractal->mlx);
		free(fractal->mlx);
		free(fractal);
	}
	else
		error_msg();
	return (0);
}
