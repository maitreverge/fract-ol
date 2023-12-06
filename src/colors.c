/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:19:13 by flverge           #+#    #+#             */
/*   Updated: 2023/12/06 12:43:32 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_color_2(t_vars *vars)
{
	if (vars->color_arg == 'B')
	{
		vars->colors.col_min = PSY_COL_10;
		vars->colors.col_max = BLUE;
		vars->colors.col_fract = CYAN;
	}
	else if (vars->color_arg == 'W')
	{
		vars->colors.col_min = BLACK;
		vars->colors.col_max = WHITE;
		vars->colors.col_fract = MAGENTA;
	}
	else if (vars->color_arg == 'L')
	{
		vars->colors.col_min = PSY_COL_3;
		vars->colors.col_max = PSY_COL_5;
		vars->colors.col_fract = PSY_COL_10;
	}
}

void	ft_init_color(t_vars *vars)
{
	if (vars->color_arg == '0')
	{
		vars->colors.col_min = BLACK;
		vars->colors.col_max = BLACK;
		vars->colors.col_fract = WHITE;
	}
	else if (vars->color_arg == 'R')
	{
		vars->colors.col_min = PSY_COL_8;
		vars->colors.col_max = RED;
		vars->colors.col_fract = ORANGE;
	}
	else if (vars->color_arg == 'G')
	{
		vars->colors.col_min = MIN_GREEN;
		vars->colors.col_max = MAX_GREEN;
		vars->colors.col_fract = PSY_COL_9;
	}
	ft_init_color_2(vars);
}

void	fractal_colorswap(int keycode, t_vars *vars)
{
	if (keycode == 49)
		vars->color_arg = '0';
	else if (keycode == 50)
		vars->color_arg = 'R';
	else if (keycode == 51)
		vars->color_arg = 'G';
	else if (keycode == 52)
		vars->color_arg = 'B';
	else if (keycode == 53)
		vars->color_arg = 'W';
	else if (keycode == 54)
		vars->color_arg = 'L';
	ft_init_color(vars);
}

void	fractal_colorshift_mouse(t_vars *vars)
{
	if (vars->colors.col_min == WHITE)
		vars->colors.col_min -= 42;
	else
		vars->colors.col_min += 42;
	if (vars->colors.col_max == WHITE)
		vars->colors.col_max -= 42;
	else
		vars->colors.col_max += 42;
	if (vars->colors.col_fract == WHITE)
		vars->colors.col_fract -= 42;
	else
		vars->colors.col_fract += 42;
}
