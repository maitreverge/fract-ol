/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:52:35 by flverge           #+#    #+#             */
/*   Updated: 2023/11/23 14:11:03 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int win_close(int keycode, t_vars *vars)
{
	//image / window / display /
	// printf les keys pour les connaitres
	mlx_destroy_window(vars->mlx, vars->win);
	// mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	return (exit(0), 0);
}
// hook for the escape key



/*

Make hookups for 1 2 3 4 for presets colors

+ / - ==> Hookups for changing the actual color theme

Arrow up / Down = scrool into, scroll back

Arrow left / right => slightly modyfing the fractal, kinda make it mute



 
 
*/