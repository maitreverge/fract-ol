/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:49:57 by flverge           #+#    #+#             */
/*   Updated: 2023/12/02 16:21:22 by flverge          ###   ########.fr       */
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

void    handle_pixel(int x, int y, t_vars *vars)
{
    t_complex z;
    t_complex c;

    double temp_real;

    // first iteration
    z.x = 0;
    z.y = 0;

    // those are the actual pixel coordinates modified to fit Mandelbrot set
    c.x = map(x, -2, +2, WIN_WIDTH);
    c.y = map(y, -2, +2, WIN_HEIGHT);

    // how many times times I need to check if the point escaped
   while (???)
   {
    z = sum_complex(sqrt_complex(z), c); // ! TO DO

    // if the value escaped
    if (???)
    {
        my_pixel_put()
    }
   }
}

void	print_mandelbrot(t_vars *vars, char **av)
{
	// av[2] = COLOR R / G / B / WOW / LSD
    // ft_printf("MANDELBROT PRINTING");
    int y;
    int x;
    
    y = -1;
    while (++y < WIN_HEIGHT)
    {
        x = -1;
        while (++x < WIN_WIDTH)
        {
            handle_pixels(x, y, vars);
        }
    }
	
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