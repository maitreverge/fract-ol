/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:52:35 by flverge           #+#    #+#             */
/*   Updated: 2023/12/02 16:27:30 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_listener(int keycode, t_vars *vars)
{
	if (keycode == ECHAP_KEY)
		win_close(vars);
	if (keycode == PLUS_KEY)
		ft_printf("Keycode : Plus Key\n");
	if (keycode == MINUS_KEY)
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
	if (mouseclick == 1)
		ft_printf("Mousecode : Left Click\n");
	if (mouseclick == 2)
		ft_printf("Mousecode : Middle Click\n");
	if (mouseclick == 3)
		ft_printf("Mousecode : Right Click\n");
	if (mouseclick == 4)
		ft_printf("Mousecode : Up Scroll\n");
	if (mouseclick == 5)
		ft_printf("Mousecode : Down Scroll\n");
	return (0);
}




// hook for the escape key



/*

Make hookups for 1 2 3 4 for presets colors

+ / - ==> Hookups for changing the actual color theme

Arrow up / Down = scrool into, scroll back

Arrow left / right => slightly modyfing the fractal, kinda make it mute



 
 
*/