/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:49:59 by flverge           #+#    #+#             */
/*   Updated: 2023/12/06 17:23:23 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_zoom_in(int x, int y, t_vars *v)
{
	long double	zoom_factor;
	long double	move_x;
	long double	move_y;

	move_x = (long double)x * (long double)((v->max_x - v->min_x)
			/ (long double)WIN_WIDTH) + (long double)v->min_x;
	move_y = (long double)y * (long double)((v->max_y - v->min_y)
			/ (long double)WIN_HEIGHT) + (long double)v->min_y;
	zoom_factor = 0.9f;
	v->original_zoom *= zoom_factor;
	v->max_x = v->max_x * zoom_factor + move_x * (1 - zoom_factor);
	v->min_x = v->min_x * zoom_factor + move_x * (1 - zoom_factor);
	v->max_y = v->max_y * zoom_factor + move_y * (1 - zoom_factor);
	v->min_y = v->min_y * zoom_factor + move_y * (1 - zoom_factor);
	return (0);
}

int	mouse_zoom_out(int x, int y, t_vars *v)
{
	long double	zoom_factor;
	long double	move_x;
	long double	move_y;

	if (v->original_zoom <= 2)
	{
		move_x = (long double)x * (long double)((v->max_x - v->min_x)
				/ (long double)WIN_WIDTH) + v->min_x;
		move_y = (long double)y * ((long double)(v->max_y - v->min_y)
				/ (long double)WIN_HEIGHT) + v->min_y;
		zoom_factor = 1.1f;
		v->original_zoom *= zoom_factor;
		v->max_x = v->max_x * zoom_factor + move_x * (1 - zoom_factor);
		v->min_x = v->min_x * zoom_factor + move_x * (1 - zoom_factor);
		v->max_y = v->max_y * zoom_factor + move_y * (1 - zoom_factor);
		v->min_y = v->min_y * zoom_factor + move_y * (1 - zoom_factor);
	}
	return (0);
}
