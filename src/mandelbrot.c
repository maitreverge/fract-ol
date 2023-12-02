/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:49:57 by flverge           #+#    #+#             */
/*   Updated: 2023/12/02 12:53:05 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_mandelbrot(t_vars *vars, char **av)
{
	// av[2] = COLOR R / G / B / WOW / LSD
    ft_printf("MANDELBROT PRINTING");
	
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