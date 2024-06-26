/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:14:15 by dtorrett          #+#    #+#             */
/*   Updated: 2024/05/23 18:21:39 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	fractal_julia(double x, double y, t_data *julia)
{
	int			i;
	t_fractal	z;
	double		tempz_x;

	i = 0;
	z.x = x * (2.00 + 1.99) * julia->zoom / WIDTH + (-1.99 * julia->zoom)
		+ (julia->shift.x * julia->zoom);
	z.y = y * (-2.00 - 1.99) * julia->zoom / HEIGHT + (1.99 * julia->zoom)
		+ (julia->shift.y * julia->zoom);
	while (i < julia->iterations && z.x * z.x + z.y * z.y < 4)
	{
		tempz_x = (z.x * z.x) - (z.y * z.y) + julia->position_c.x;
		z.y = 2 * z.x * z.y + julia->position_c.y;
		z.x = tempz_x;
		i++;
	}
	my_put_pixel(julia, x, y, i);
}
