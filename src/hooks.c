/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:52:35 by flverge           #+#    #+#             */
/*   Updated: 2023/11/23 17:40:21 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int win_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	return (exit(0), 0);
}

int	key_listener(int keycode, t_vars *vars)
{
	if (keycode == ECHAP_KEY)
		win_close(vars);
	if (keycode == PLUS_KEY) // middle zoom in
		ft_printf("Keycode : %i\n", keycode); // checks what key
	if (keycode == MINUS_KEY) // middle zoom out
		ft_printf("Keycode : %i\n", keycode); // checks what key
	if (keycode == UP_KEY)
		ft_printf("Keycode : %i\n", keycode); // checks what key
	if (keycode == DOWN_KEY)
		ft_printf("Keycode : %i\n", keycode); // checks what key
	if (keycode == LEFT_KEY)
		ft_printf("Keycode : %i\n", keycode); // checks what key
	if (keycode == RIGHT_KEY)
		ft_printf("Keycode : %i\n", keycode); // checks what key
	// else
		// ft_printf("Keycode : %i\n", keycode); // chekcs what key
}

int	mouse_listener(int mouseclick, t_vars *vars)
{
	// if (mouseclick == LEFT_CLICK)
	ft_printf("Mousecode : %i\n", mouseclick); // checks what key
}


// hook for the escape key



/*

Make hookups for 1 2 3 4 for presets colors

+ / - ==> Hookups for changing the actual color theme

Arrow up / Down = scrool into, scroll back

Arrow left / right => slightly modyfing the fractal, kinda make it mute



 
 
*/