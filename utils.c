/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:13:16 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/23 18:13:16 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	error_msg(void)
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

int	ft_num(char *str, t_data *fractal)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	if (!ft_isdigit(str[i]))
	{
		free(fractal);
		error_msg();
	}
	else
		i++;
	if ((str[i]) == '.')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			free(fractal);
			error_msg();
		}
		else
			i++;
	}
	return (0);
}

// It sets the color of a pixel at coordinates (x, y) on the screen.
// It calculates the exact memory address of the pixel in the image buffer 
//to be colored, by using the fractal address, line length, and bpp.
// If the number of iteration is equal to the maximum --> the point is inside
//and the pixel color is set to black (0x000000).
// Otherwise, the pixel color is determined by multiplying the fractal color
//by the number of iterations. This creates a gradient effect, with the color
//intensity increasing as the number of iterations increases.
void	my_put_pixel(t_data *fractal, int x, int y, int iterations)
{
	char	*color_info;

	color_info = fractal->addr + (y * fractal->line_length) + (x
			* (fractal->bits_per_pixel / 8));
	if (iterations == fractal->iterations) // dentro
		*(unsigned int *)color_info = 0x000000;
	else // fuera
		*(unsigned int *)color_info = fractal->color * iterations;
}
