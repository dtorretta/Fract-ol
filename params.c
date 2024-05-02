#include "fractol.h"

void	mandelbrot_param(t_fractal *fractal, char *name)
{
    fractal->width = 1280;
	fractal->height = 720;
	//fractal->iterations = 150;
	fractal->zoom = 1;
	fractal->c.x = 0;
	fractal->c.y = 0;
	fractal->z.x = 0;
	fractal->z.y = 0;
	fractal->xarrow = 0; //no entiendo
	fractal->yarrow = 270; //no entiendo
	fractal->color = 0xccf1ff;
	fractal->name = name;
}