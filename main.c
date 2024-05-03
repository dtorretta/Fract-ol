/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:03:33 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/03 19:57:16 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

/*void	ft_zoom(int x, int y, t_fractal2 *data)
{
	data->minreal = (x / data->zoom + data->minreal) - (x / (data->zoom * 1.2));
	data->min_i = (y / data->zoom + data->min_i) - (y / (data->zoom * 1.2));
	data->zoom *= 1.2;
	data->i
}

void	ft_dezoom(int x, int y, t_fractal2 *data)
{
	data->minreal = (x / data->zoom + data->minreal) - (x /
		(data->zoom / 1.2));
	data->min_i = (y / data->zoom + data->min_i) - (y / (data->zoom / 1.2));
	data->zoom /= 1.2;
	data->max_n--;
}

int	keys(int key, t_fractal2 *data)
{
	if (key == 53)
		exit(1);
	else if (key == 18)
		data->color = 0x00ff00;
	else if (key == 19)
		data->color = 0xff69b4;
	else if (key == 20)
		data->color = 0xffdab9;
	mlx_clear_window(data->mlx, data->win);
		mandelbrot(data);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_fractal2 *data)
{
	int	x;
	int	y;

	if (mousecode == 5 || mousecode == 2)
		ft_zoom(x, y, data);
	else if (mousecode == 4 || mousecode == 1)
		ft_dezoom(x, y, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mandelbrot(data);
	put_text(data);
	return (0);
}*/
void	draw_fractal(t_data *fractal, char *name)
{
	// funciona pra julia?
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (x < fractal->width)
	{
		while (y < fractal->height)
		{
			if (ft_strncmp(name, "mandel", 6) == 0)
				fractal_mandel(x, y, fractal);
			y++;
		}
		y = 0;
		x++;
	}
}

void	initiate_params(t_data *fractal, char *name)
{
	if (ft_strncmp(name, "mandel", 6) == 0) //hay problema si fuciona con otro nombre??
	{
		fractal->win = mlx_new_window(fractal->mlx, 1000, 1100,
				"Mandelbrot Set");
		mandelbrot_param(fractal);
	}
	else if (ft_strncmp(name, "julia", 6) == 0)
	{
		fractal->win = mlx_new_window(fractal->mlx, 1000, 1100, "Julia Set");
		julia_param(fractal);
	}
	else
	{
		ft_putendl_fd("Please specify a valid name of the fractol \"mandel\", \"julia\" or \"XXX\"", 1);
	}
	draw_fractal(fractal, name);
}
int	main(int argc, char **argv)
{
	t_data	*fractal;

	if (argc == 2)
	{
		fractal = (t_data *)malloc(sizeof(t_data));
		fractal->mlx = mlx_init(); // Inicializar la conexión MLX
		initiate_params(fractal, argv[1]);
		// mlx_key_hook(fractal.win, key_hook, &fractal);
		// mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
		// mlx_hook(fractal.win, 17, 1L << 17, close_game, &fractal);
		mlx_loop(fractal->mlx);
		free(fractal);
	}
	else if (argc > 2)
		ft_putendl_fd("Too many arguments", 1);
	else
		ft_putendl_fd("Please specify the name of the fractol", 1);
	return (0);
}
