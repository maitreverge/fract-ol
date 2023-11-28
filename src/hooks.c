/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:52:35 by flverge           #+#    #+#             */
/*   Updated: 2023/11/28 09:48:44 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int win_close(t_vars *vars)
{
	// destroy images AND display AND windows, in this order
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_display(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	return (exit(0), 0);
}

int	key_listener(int keycode, t_vars *vars)
{
	if (keycode == ECHAP_KEY)
		win_close(vars);
	if (keycode == PLUS_KEY) // middle zoom in
		ft_printf("Keycode : Plus Key\n");
	if (keycode == MINUS_KEY) // middle zoom out
		ft_printf("Keycode : Minus Key\n");
	if (keycode == UP_KEY)
		ft_printf("Keycode : Up Key\n");
	if (keycode == DOWN_KEY)
		ft_printf("Keycode : Down Key\n");
	if (keycode == LEFT_KEY)
		ft_printf("Keycode : Left Key\n");
	if (keycode == RIGHT_KEY)
		ft_printf("Keycode : Right Key\n");
}

int	mouse_listener(int mouseclick, t_vars *vars)
{
	// mouse clicks listenner
	if (mouseclick == 1) // left
		ft_printf("Mousecode : Left Click\n");
	if (mouseclick == 2) // middle
		ft_printf("Mousecode : Middle Click\n");
	if (mouseclick == 3) // right
		ft_printf("Mousecode : Right Click\n");
	if (mouseclick == 4) // up scroll
		ft_printf("Mousecode : Up Scroll\n");
	if (mouseclick == 5) // down scroll
		ft_printf("Mousecode : Down Scroll\n");
	// ! mouse pos function makes the programs crash
	return (0);
}




// hook for the escape key



/*

Make hookups for 1 2 3 4 for presets colors

+ / - ==> Hookups for changing the actual color theme

Arrow up / Down = scrool into, scroll back

Arrow left / right => slightly modyfing the fractal, kinda make it mute



 
 
*/