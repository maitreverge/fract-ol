/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:52:35 by flverge           #+#    #+#             */
/*   Updated: 2023/12/05 11:25:04 by flverge          ###   ########.fr       */
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
		vars->shift_y += (0.5 * vars->original_zoom);	
	else if (keycode == DOWN_KEY)
		vars->shift_y -= (0.5 * vars->original_zoom);	
	else if (keycode == LEFT_KEY)
		vars->shift_x += (0.5 * vars->original_zoom);
	else if (keycode == RIGHT_KEY)
		vars->shift_x -= (0.5 * vars->original_zoom);
    if (vars->definition <= 0)
		vars->definition = 1;
	print_fractal(vars);  
}

// ! classic mouse zooming
// int	mouse_listener(int mouseclick, int x, int y, t_vars *vars)
// {
//     if (mouseclick == 4)
//         vars->original_zoom *= 0.8; // zoom in
//     else if (mouseclick == 5)
//         vars->original_zoom *= 1.2; // zoom out
    
//     print_fractal(vars);
//     return (0);
// }

int	mouse_listener(int mouseclick, int x, int y, t_vars *vars)
{
    double zoom_factor;
    if (mouseclick == 4)
        zoom_factor = 0.8; // zoom in
    else if (mouseclick == 5)
        zoom_factor = 1.2; // zoom out

    // Calculate the new zoom level
    double new_zoom = vars->original_zoom * zoom_factor;

    // Calculate the new shift values based on the mouse position and the new zoom level
    vars->shift_x = (x / new_zoom) - ((x - vars->shift_x) / vars->original_zoom);
    vars->shift_y = (y / new_zoom) - ((y - vars->shift_y) / vars->original_zoom);

    vars->original_zoom = new_zoom;

    print_fractal(vars);
    return (0);
}

/*

int	mouse_listener(int mouseclick, int x, int y, t_vars *vars)
{
    double zoom_factor = 1.0;
    if (mouseclick == 4)
        zoom_factor = 0.8; // zoom in
    else if (mouseclick == 5)
        zoom_factor = 1.2; // zoom out

    // Calculate the new zoom level and the shift needed to keep the mouse position constant
    double new_zoom = vars->zoom * zoom_factor;
    vars->shift_x = x - (x - vars->shift_x) * (new_zoom / vars->zoom);
    vars->shift_y = y - (y - vars->shift_y) * (new_zoom / vars->zoom);
    vars->zoom = new_zoom;

    print_fractal(vars);
    return (0);
}

*/




// hook for the escape key



/*

Make hookups for 1 2 3 4 for presets colors

+ / - ==> Hookups for changing the actual color theme

Arrow up / Down = scrool into, scroll back

Arrow left / right => slightly modyfing the fractal, kinda make it mute



 
 
*/