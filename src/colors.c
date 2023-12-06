/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:19:13 by flverge           #+#    #+#             */
/*   Updated: 2023/12/06 11:30:34 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	atoi_color(char *str, int comas)
{
	int	result;
	int	polarity;
	int	j;

	result = 0;
	polarity = 1;
	j = 0;
	while (j < comas)
	{
		if (*str == ',')
			j++;
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			polarity = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (result * polarity);
}

int	fusion_4ints(int *c)
{
	return (c[0] << 24 | c[1] << 16 | c[2] << 8 | c[3]);
}

int	get_color(char *str)
{
	int	result;
	int	*colors;
	int	i;

	i = 0;
	colors = malloc(sizeof(int) * 4);
	if (!colors)
		return (-1);
	while (i < 4)
	{
		colors[i] = atoi_color(str, i);
		if (colors[i] < 0 || colors[i] > 255)
			return (-1);
		i++;
	}
	result = fusion_4ints(colors);
	free(colors);
	return (result);
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
	else if (vars->color_arg == 'B')
	{
		vars->colors.col_min = PSY_COL_6;
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

void	fractal_colorswap(int keycode, t_vars *vars)
{
	if (keycode == 49) // 0
		vars->color_arg = '0';
	else if (keycode == 50) // R
		vars->color_arg = 'R';
	else if (keycode == 51) // G
		vars->color_arg = 'G';
	else if (keycode == 52) // B
		vars->color_arg = 'B';
	else if (keycode == 53) // W
		vars->color_arg = 'W';
	else if (keycode == 54) // L
		vars->color_arg = 'L';
	ft_init_color(vars);
}

void	fractal_colorshift_mouse(t_vars *vars)
{
	if (vars->colors.col_min == WHITE) // min
		vars->colors.col_min -= 42;
	else
		vars->colors.col_min += 42;
	if (vars->colors.col_max == WHITE) // max
		vars->colors.col_max -= 42;
	else
		vars->colors.col_max += 42;
	if (vars->colors.col_fract == WHITE) // fract
		vars->colors.col_fract -= 42;
	else
		vars->colors.col_fract += 42;
}

void	fractal_colorshift_space(t_vars *vars)
{
	if (vars->colors.col_min == WHITE) // min
		vars->colors.col_min -= 21;
	else
		vars->colors.col_min += 21;
	if (vars->colors.col_max == WHITE) // max
		vars->colors.col_max -= 21;
	else
		vars->colors.col_max += 21;
	if (vars->colors.col_fract == WHITE) // fract
		vars->colors.col_fract -= 21;
	else
		vars->colors.col_fract += 21;
}




