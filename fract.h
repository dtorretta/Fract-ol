/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:13:55 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/23 18:13:58 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "./libmlx/mlx.h"
# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_fractal
{
	double		x;
	double		y;
}				t_fractal;

typedef struct l_fractal
{
	char		*name;
	void		*img;
	void		*mlx;
	void		*win;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_fractal	position_c;
	t_fractal	shift;
	double		zoom;
	int			iterations;
	int			color;
}				t_data;

/* MANDELBROT */
void			fractal_mandel(int x, int y, t_data *mandel);

/* JULIA */
void			fractal_julia(double x, double y, t_data *julia);

/* PARAMS */
void			mandelbrot_param(t_data *fractal);
void			julia_param(t_data *fractal);

/* EVENTS */
int				mouse_handle(int button, int x, int y, t_data *fractal);
int				key_handle(int keycode, t_data *fractal);
int				close_handle(t_data *fractal);

/* UTILS */
int				ft_num(char *str, t_data *fractal);
void			error_msg(void);
void			my_put_pixel(t_data *fractal, int x, int y, int iterations);

/* MAIN */
void			draw_fractal(t_data *fractal, char *name);

#endif