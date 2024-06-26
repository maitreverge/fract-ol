/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:52:35 by flverge           #+#    #+#             */
/*   Updated: 2024/06/26 10:17:06 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractal_hotswap(int keycode, t_vars *vars)
{
	if (keycode == MANDELBROT)
		vars->fractal_name = 'M';
	else if (keycode == JULIA)
	{
		vars->fractal_name = 'J';
		vars->julia_set = '1';
		assign_julia(vars);
	}
	else if (keycode == TRICORN)
		vars->fractal_name = 'X';
}

void	fractal_move(int keycode, t_vars *vars)
{
	if (keycode == UP_KEY)
		vars->shift_y += (0.5 * vars->original_zoom);
	else if (keycode == DOWN_KEY)
		vars->shift_y -= (0.5 * vars->original_zoom);
	else if (keycode == LEFT_KEY)
		vars->shift_x += (0.5 * vars->original_zoom);
	else if (keycode == RIGHT_KEY)
		vars->shift_x -= (0.5 * vars->original_zoom);
}

void	fractal_definition(int keycode, t_vars *vars)
{
	if (keycode == PLUS_KEY)
		vars->definition += 3;
	else if (keycode == MINUS_KEY)
		vars->definition -= 3;
}

void	fractal_rotate(int keycode, t_vars *vars)
{
	if (keycode = XK_r && vars->fractal_name == 'J')
	{
		// rotate the suff
	}
}

int	key_listener(int keycode, t_vars *vars)
{
	if (vars->definition <= 0)
		vars->definition = 1;
	if (keycode == ECHAP_KEY)
		win_close(vars);
	if (keycode == SPACE_KEY)
	{
		vars->max_x = 2;
		vars->min_x = -2;
		vars->max_y = 2;
		vars->min_y = -2;
	}
	fractal_definition(keycode, vars);
	fractal_move(keycode, vars);
	fractal_hotswap(keycode, vars);
	fractal_colorswap(keycode, vars);
	
	// new stuff for rotating fractal julia for a couple of spins
	fractal_rotate(keycode, vars);
	
	if (vars->definition <= 0)
		vars->definition = 1;
	print_fractal(vars);
	return (0);
}

int	mouse_listener(int mouseclick, int x, int y, t_vars *vars)
{
	if (mouseclick == SCROLL_DOWN)
		mouse_zoom_out(x, y, vars);
	else if (mouseclick == SCROLL_UP)
		mouse_zoom_in(x, y, vars);
	else if (mouseclick == RIGHT_CLICK)
	{
		vars->julia_set++;
		if (vars->julia_set > 51)
			vars->julia_set = '1';
		assign_julia(vars);
	}
	else if (mouseclick == LEFT_CLICK)
		fractal_colorshift_mouse(vars);
	print_fractal(vars);
	return (0);
}
