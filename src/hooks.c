/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:52:35 by flverge           #+#    #+#             */
/*   Updated: 2023/12/04 16:35:21 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_listener(int keycode, t_vars *vars)
{
	if (vars->definition <= 0) // ! double check to avoid program freezing
		vars->definition = 1;
	if (keycode == ECHAP_KEY)
		win_close(vars);
	else if (keycode == PLUS_KEY)
		vars->definition += 3;
	else if (keycode == MINUS_KEY)
		vars->definition -= 3;
	else if (keycode == UP_KEY)
		vars->shift_y += (0.5 * vars->zoom);	
	else if (keycode == DOWN_KEY)
		vars->shift_y -= (0.5 * vars->zoom);	
	else if (keycode == LEFT_KEY)
		vars->shift_x += (0.5 * vars->zoom);
	else if (keycode == RIGHT_KEY)
		vars->shift_x -= (0.5 * vars->zoom);
	print_fractal(vars);
}

int	mouse_listener(int mouseclick, int x, int y, t_vars *vars)
{
	// if (mouseclick == 1)
	// 	ft_printf("Mousecode : Left Click\n");
	// else if (mouseclick == 2)
	// 	ft_printf("Mousecode : Middle Click\n");
	// else if (mouseclick == 3)
	// 	ft_printf("Mousecode : Right Click\n");
	if (mouseclick == 4)
		vars->zoom *= 0.8; // zoom in
	else if (mouseclick == 5)
		vars->zoom *= 1.2; // zoom out
	print_fractal(vars);
	return (0);
}




// hook for the escape key



/*

Make hookups for 1 2 3 4 for presets colors

+ / - ==> Hookups for changing the actual color theme

Arrow up / Down = scrool into, scroll back

Arrow left / right => slightly modyfing the fractal, kinda make it mute



 
 
*/