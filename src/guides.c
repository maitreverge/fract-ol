/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guides.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:02:21 by flverge           #+#    #+#             */
/*   Updated: 2023/12/06 14:13:12 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	display_guide_1(t_vars *vars)
{
	int x;

	mlx_string_put(vars->mlx, vars->win, 40, 35, WHITE, "DEFINITION");
	mlx_string_put(vars->mlx, vars->win, 40, 65, WHITE, " + Key : More HD");
	mlx_string_put(vars->mlx, vars->win, 40, 85, WHITE, " - Key : Less HD");
	x = 360;
	mlx_string_put(vars->mlx, vars->win, x + 10, 35, WHITE, "ARROW KEYS :");
	mlx_string_put(vars->mlx, vars->win, x + 10, 65, WHITE, "-> : Move Left");
	mlx_string_put(vars->mlx, vars->win, x + 10, 85, WHITE, "<- : Move Right");
	mlx_string_put(vars->mlx, vars->win, x + 10, 105, WHITE, "^  : Move Up");
	mlx_string_put(vars->mlx, vars->win, x + 10, 125, WHITE, "v  : Move Down");
	x += 330;
	mlx_string_put(vars->mlx, vars->win, x + 10, 35, WHITE, "COLORS CONTROL :");
	mlx_string_put(vars->mlx, vars->win, x + 10, 65, WHITE, "Right Click: Shift Color");
	mlx_string_put(vars->mlx, vars->win, x + 10, 85, WHITE, "Press 1 for Black and White");
	mlx_string_put(vars->mlx, vars->win, x + 10, 105, WHITE, "Press 2 for Red");
	mlx_string_put(vars->mlx, vars->win, x + 10, 125, WHITE, "Press 3 for Green");
	mlx_string_put(vars->mlx, vars->win, x + 10, 145, WHITE, "Press 4 for Blue");
	mlx_string_put(vars->mlx, vars->win, x + 10, 165, WHITE, "Press 5 for Wow");
	mlx_string_put(vars->mlx, vars->win, x + 10, 185, WHITE, "Press 6 for LSD");
	x += 330;
	mlx_string_put(vars->mlx, vars->win, x + 10, 35, WHITE, "ZOOM CONTROLS");
	mlx_string_put(vars->mlx, vars->win, x + 10, 65, WHITE, "Scroll Up = Zoom +");
	mlx_string_put(vars->mlx, vars->win, x + 10, 85, WHITE, "Scroll Up = Zoom -");
	mlx_string_put(vars->mlx, vars->win, x + 10, 105, WHITE, "SPACE KEY : Reset Zoom");
}

void	display_guide_2(t_vars *vars)
{
	int	x;

	// x = 

	x = 1250;
	mlx_string_put(vars->mlx, vars->win, x + 10, 35, WHITE, "JULIA CONTROLS :");
	mlx_string_put(vars->mlx, vars->win, x + 10, 65, WHITE, "Left Click: Shift Julia Set");
	x = 1300;
	if (vars->fractal_name == 'M')
		mlx_string_put(vars->mlx, vars->win, x + 10, 1400, WHITE, "Fractal : MANDELBROT");
	else if (vars->fractal_name == 'X')
		mlx_string_put(vars->mlx, vars->win, x + 10, 1400, WHITE, "Fractal : TRICORN");
	else if (vars->fractal_name == 'J')
	{
		if (vars->julia_set == '1')
			mlx_string_put(vars->mlx, vars->win, x + 10, 1400, WHITE, "Fractal : Julia Set 1");
		if (vars->julia_set == '2')
			mlx_string_put(vars->mlx, vars->win, x + 10, 1400, WHITE, "Fractal : Julia Set 2");
		if (vars->julia_set == '3')
			mlx_string_put(vars->mlx, vars->win, x + 10, 1400, WHITE, "Fractal : Julia Set 3");
	}
}

