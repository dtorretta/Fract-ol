/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:13:48 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/23 18:13:48 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

// Button4 = zoom in || Button5 = zoom out
int	mouse_handle(int button, int x, int y, t_data *fractal)
{
	(void)x;
	(void)y;
	if (button == Button4)
		fractal->zoom *= 0.75;
	else if (button == Button5)
		fractal->zoom *= 1.25;
	draw_fractal(fractal, fractal->name);
	return (0);
}

static int	key_handle_2(int keycode, t_data *fractal)
{
	if (keycode == XK_a && !strncmp(fractal->name, "julia", 5))
	{
		fractal->position_c.x += 0.05;
		fractal->position_c.y -= 0.05;
	}
	else if (keycode == XK_s && !strncmp(fractal->name, "julia", 5))
	{
		fractal->position_c.x -= 0.05;
		fractal->position_c.y += 0.05;
	}
	return (0);
}

int	key_handle(int keycode, t_data *fractal)
{
	if (keycode == XK_Escape)
		close_handle(fractal);
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
	else if (keycode == XK_space)
		fractal->color += 1000;
	else if ((keycode == XK_s || keycode == XK_a) && !strncmp(fractal->name,
			"julia", 5))
		key_handle_2(keycode, fractal);
	draw_fractal(fractal, fractal->name);
	return (0);
}

int	close_handle(t_data *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	exit(EXIT_SUCCESS);
}
