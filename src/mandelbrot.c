/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:49:57 by flverge           #+#    #+#             */
/*   Updated: 2023/12/06 17:51:07 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex	sqrt_complex(t_complex z)
{
	t_complex	res;

	res.x = pow(z.x, 2) - pow(z.y, 2);
	res.y = (2 * z.x * z.y);
	return (res);
}

void	which_fractal(t_complex *z, t_complex *c, t_vars *vars)
{
	if (vars->fractal_name == 'J')
	{
		c->x = vars->julia_x;
		c->y = vars->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	handle_pixels(int x, int y, t_vars *v)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, v->min_x, v->max_x, WIN_WIDTH)) + v->shift_x;
	z.y = (map(y, v->min_y, v->max_y, WIN_HEIGHT)) + v->shift_y;
	which_fractal(&z, &c, v);
	while (i < v->definition)
	{
		if (v->fractal_name == 'X')
			z = sum_complex(sqrt_complex((t_complex){z.x, -z.y}), c);
		else
			z = sum_complex(sqrt_complex(z), c);
		if ((pow(z.x, 2) + pow(z.y, 2)) > v->pyth_escaped)
		{
			color = map(i, v->colors.col_min, v->colors.col_max, v->definition);
			my_mlx_pixel_put(v, x, y, color);
			return ;
		}
		++i;
		my_mlx_pixel_put(v, x, y, v->colors.col_fract);
	}
}

void	print_mandelbrot(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	mlx_clear_window(vars->mlx, vars->win);
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			handle_pixels(x, y, vars);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
