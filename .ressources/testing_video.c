/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_video.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:23:25 by flverge           #+#    #+#             */
/*   Updated: 2023/12/02 11:49:24 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

typedef struct s_complex
{
    double	real; // x
    double	i; // y
}			t_complex;

int main(void)
{
    // formula for mandelbrot = z^2 + c
    t_complex z;
    t_complex c;

    double temp_real;

    z.real = 0;
    z.i = 0;

    c.real = 0.25;
    c.i = 0.4;

    for (int i = 0; i < 42; ++i)
    {
        // general formula : z = z^2 + c
        // for calculating the z square, the formula is : x^2 - y^2 + 2xyi
        temp_real = pow(z.real, 2) - pow(z.i, 2);
        z.i = 2 * z.real * z.i + c.i; // add c.i here

        z.real = temp_real + c.real; // add c.real here

        printf("Iteration n -> %d real %f imaginary %f\n", i, z.real, z.i);
    }
}