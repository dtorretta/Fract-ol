/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:39:00 by dtorrett          #+#    #+#             */
/*   Updated: 2024/02/15 18:31:50 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>


typedef struct s_fractal
{
    double x;
    double y;
}           t_fractal;

void	mandelbrot_param(t_fractal *fractal, char *name);

#endif