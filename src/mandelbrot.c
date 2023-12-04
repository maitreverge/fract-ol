/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:49:57 by flverge           #+#    #+#             */
/*   Updated: 2023/12/04 15:39:48 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
handeling pixels allows us to efficiently handle a "little" set of Mandelbrot, because
it is located within a range of -2 / +2 on both reals numbers and imaginary numbers
*/

/*
We aslo need to rescale the window according to the window size, otherwise, only a fraction
of the Mandelbrot set wioll be visible (as the majority of the points leaves within the negative part)



*/

// ! Linear interpolation
double map(double i, double new_min, double new_max, double old_max)
{
    return ((new_max - new_min) * (i / old_max) + new_min); 
}

// sumcomplex, because c use current Z from the first itteration

t_complex sum_complex(t_complex z1, t_complex z2)
{
    t_complex res;
    
    res.x = z1.x + z2.x;
    res.y = z1.y + z2.y;

    return (res);
}

// (x_real + y_imaginary)^2
// ==> x^2 + 2xyi - y^2
t_complex   sqrt_complex(t_complex z)
{
    // help :(
    t_complex res;

    res.x = pow(z.x, 2) - pow(z.y, 2);
    res.y = (2 * z.x * z.y); 

    return (res);
    
}

void    handle_pixels(int x, int y, t_vars *vars)
{
    t_complex z;
    t_complex c;
    size_t    i; // iterations
    int color;

    i = 0;
    // first iteration
    z.x = 0;
    z.y = 0;

    // those are the actual pixel coordinates modified to fit Mandelbrot set
    c.x = (map(x, -2, +2, WIN_WIDTH) * vars->zoom) + vars->shift_x; // + vars shift on the x axis
    c.y = (map(y, -2, +2, WIN_HEIGHT) * vars->zoom) + vars->shift_y; // shift on the y axis, up and down
    

    // how many times times I need to check if the point escaped
    // somes points are gonna need more calculations to escape or not the matrix
    // the more iterations, the more definition
   while (i < vars->definition)
   {
    z = sum_complex(sqrt_complex(z), c);

    // if the value escaped
    // if hypothenuse > 2, let's assume I has escaped
    if ((pow(z.x, 2) + pow(z.y, 2)) > vars->pyth_escaped)
    {
        color = map(i, MIN_GREEN, MAX_GREEN, vars->definition);
        my_mlx_pixel_put(vars, x, y, color); // orange
        return;
    }
    ++i;
    my_mlx_pixel_put(vars, x, y, PSY_COL_9); // spring green
   }
} 

void    print_mandelbrot(t_vars *vars)
{
	// av[2] = COLOR R / G / B / WOW / LSD
    // ft_printf("MANDELBROT PRINTING");
    int x;
    int y;
    
    y = -1;
    while (++y < WIN_HEIGHT)
    {
        x = -1;
        while (++x < WIN_WIDTH)
            handle_pixels(x, y, vars);
    }
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	
}

/*

initialize MiniLibX library
create a new window

for each pixel in the window:
    map the pixel to a corresponding point in the complex plane
    set z = 0
    set c = the point in the complex plane
    set iteration = 0

    while the absolute value of z is less than or equal to 2 and iteration is less than max_iteration:
        set z = z^2 + c
        increment iteration

    set the color of the pixel based on the number of iterations

redraw the image
update the window


*/