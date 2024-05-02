//#include "fractol.h"
# include <stdio.h>
# include <math.h>
#include <string.h> //borrar
#include "minilibx_linux/mlx.h"



typedef struct s_fractal
{
    double x;
    double y;
}				t_fractal;

typedef struct l_fractal {
	char		*name;
	void		*img;
	void		*addr; //ver mlx_get_data_addr -  para obtener la dirección del primer byte de la imagen en memoria asignada por la función mlx_new_image
	int			bits_per_pixel; //ver mlx_get_data_addr - puntero a un entero donde se almacenará el número de bits por píxel de la imagen.
	int			line_length; //ver mlx_get_data_addr - puntero a un entero donde se almacenará el tamaño en bytes de una línea de píxeles de la imagen.
	int			endian; //ver mlx_get_data_addr - puntero a un entero donde se almacenará el valor del endian de la arquitectura (0 para big endian, 1 para little endian).
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_fractal	position_c;
	double		zoom;
	double		xarrow;
	double		yarrow;
	double		radius; //ver
	//int			iterations; 
	int			color;
}				t_fractal2;

void	mandelbrot_param(t_fractal2 *fractal, char *name)
{
    fractal->width = 800;
	fractal->height = 600;
	//fractal->iterations = 150;
	fractal->zoom = 1;	
    fractal->position_c.x = 0;
    fractal->position_c.y = 0;
	fractal->xarrow = 0; //no entiendo
	fractal->yarrow = 270; //no entiendo
	fractal->color = 0xccf1ff;
	fractal->name = name;
}

void fractal_mandel(t_fractal2 *mandel)
{
    //printf("%s prueba", mandel->name);
    int max_iterations = 10;
    int i = 0;
    
    //printf("mandel->position_z.x: %f\n", mandel->position_c.x); //ver
    //printf("mandel->position_z.y: %f\n", mandel->position_c.y); //ver

    
    //mandel->position_c.x = (mandel->position_c.x / mandel->zoom) + mandel->xarrow;
    mandel->position_c.x = (mandel->position_c.x + mandel->xarrow) / mandel->zoom * (0.47 + 2.0) / (mandel->width - 1) - 2.0;
	//mandel->position_c.y = (mandel->position_c.y / mandel->zoom) + mandel->yarrow;
    mandel->position_c.y = (mandel->position_c.y + mandel->yarrow) / mandel->zoom * (1.12 + 1.12) / (mandel->width - 1) - 1.12;
	
	//printf("mandel->position_z.x: %f\n", mandel->position_c.x); //ver
    //printf("mandel->position_z.y: %f\n", mandel->position_c.y); //ver
    //printf("mandel->position_z.x: %f\n", mandel->temp.x); //ver
    //printf("mandel->position_z.y: %f\n", mandel->temp.y); //ver

    
    double	z_x;
	double	z_y;
	double	tempz_x;
	
	z_x = mandel->position_c.x;
	z_y = mandel->position_c.y;
   
    //printf("mandel->position_z.x: %f\n", z_x); //ver
    //printf("mandel->position_z.y: %f\n", z_y); //ver
    
    while(i++ < max_iterations)
    {
        tempz_x = pow(z_x, 2) - pow(z_y, 2) + mandel->position_c.x;
		z_y = 2.0 * z_x * z_y + mandel->position_c.y;
		z_x = tempz_x;
        
        //if (pow(z_x, 2) + pow(z_y, 2) >= __DBL_MAX__) //otros le ponen >4
        if ((pow(z_x, 2) + pow(z_y, 2)) > 4)
            break;
           
    }
    printf("mandel->position_z.x: %f\n", z_x); //ver
    printf("mandel->position_z.y: %f\n", z_y); //ver
    if (i == max_iterations) //dentro
        mlx_pixel_put(mandel->img, mandel->win, z_x, z_y, mandel->color * i);
    else //fuera //ACA PASA EL SEGFAULT
        mlx_pixel_put(mandel->img, mandel->win, z_x, z_y, mandel->color);
}

void draw_fractal (t_fractal2 *fractal, char *name)
{
    //fractal->name = name;
    //printf("%s prueba", fractal->name);
    //printf("mandel->position_z.x: %f\n", fractal->position_c.x); //ver
    //printf("mandel->position_z.y: %f\n", fractal->position_c.y); //ver
    
    while(fractal->position_c.x < fractal->width)
    {
        while(fractal->position_c.y < fractal->height)
        {
            //printf("mandel->position_z.x: %f\n", fractal->position_c.x); //ver
            //printf("mandel->position_z.y: %f\n", fractal->position_c.y); //ver
            //break;
            if(strcmp(name, "mandel") == 0) //utilizar la de libft
            {
                //printf("mandel->position_z.x: %f\n", fractal->position_c.x); //ver
                //printf("mandel->position_z.y: %f\n", fractal->position_c.y); //ver
                //break;
                fractal_mandel(fractal); //antes tenia position_c
                //break; //v er
            }
            fractal->position_c.y++;
        }
        //printf("mandel->position_z.x: %f\n", fractal->position_c.x); //ver
        //printf("mandel->position_z.y: %f\n", fractal->position_c.y); //ver
        fractal->position_c.y = 0;
        fractal->position_c.x++;
    }
    
    // Colocar la imagen en la ventana
    //mlx_put_image_to_window(mlx, mlx_win, img, 0 , 0);
    // Borrar la imagen de la memoria
   //mlx_destroy_image(mlx, img);
}

int main (void)
{
    t_fractal2		fractal;

    mandelbrot_param (&fractal, "mandel");  //asigno los parametros propios del mandelbrot

    // Inicializar la conexión MLX
    fractal.mlx = mlx_init();

    // Crear una nueva ventana
    fractal.win = mlx_new_window(fractal.mlx, fractal.width, fractal.height, fractal.name);
	
	// crea la imagen
    fractal.img = mlx_new_image(fractal.mlx, fractal.width, fractal.height);
	
	// //fractalsetup(&fractal); 
	// //mlx_destroy_image(fractal.mlx, fractal.img); Borrar la imagen de la memoria porque???
	// //fractal.img = mlx_new_image(fractal.mlx, fractal.width, fractal.height);
	fractal.addr = mlx_get_data_addr (fractal.img, &fractal.bits_per_pixel, &fractal.line_length, &fractal.endian);
    
    draw_fractal(&fractal, fractal.name);

	// Colocar la imagen en la ventana
	mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.img, 0, 0);		
		
	/*mlx_key_hook(fractal.win, key_hook, &fractal);
	mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
	mlx_hook(fractal.win, 17, 1L << 17, close_game, &fractal);*/
		
	// Mantener la ventana abierta hasta que se cierre
	mlx_loop(fractal.mlx);

    return (0);
}