/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:56:47 by marvin            #+#    #+#             */
/*   Updated: 2024/05/09 23:56:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

// Función de interpolación de color
int interpolateColor(int color1, int color2, float t)
{
    float threshold = 0.5;

    int r1 = (color1 >> 16) & 0xFF;
    int g1 = (color1 >> 8) & 0xFF;
    int b1 = color1 & 0xFF;
    int r2 = (color2 >> 16) & 0xFF;
    int g2 = (color2 >> 8) & 0xFF;
    int b2 = color2 & 0xFF;

    int r, g, b;

    // Calcula la diferencia entre los componentes de color de cada color
    int dr = abs(r2 - r1);
    int dg = abs(g2 - g1);
    int db = abs(b2 - b1);

    // Interpola linealmente hasta el umbral
    if (t < threshold) {
        // Aplica una variación mayor entre los colores base
        r = r1 + (int)(dr * t / threshold);
        g = g1 + (int)(dg * t / threshold);
        b = b1 + (int)(db * t / threshold);
    } else {
        // Usa el segundo color después del umbral
        r = r2;
        g = g2;
        b = b2;
    }

    return (r << 16) | (g << 8) | b;
}
