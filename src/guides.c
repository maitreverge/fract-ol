/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guides.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:02:21 by flverge           #+#    #+#             */
/*   Updated: 2023/12/05 17:15:19 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	display_guide_1(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 30, 25, BLACK, "--------------------");
	mlx_string_put(vars->mlx, vars->win, 30, 105, BLACK, "--------------------");
	for (int i = 28; i < 105; i+=9)
		mlx_string_put(vars->mlx, vars->win, 25, i, BLACK, "|");
	for (int i = 28; i < 105; i+=9)
		mlx_string_put(vars->mlx, vars->win, 150, i, BLACK, "|");
	mlx_string_put(vars->mlx, vars->win, 40, 35, RED, "Controls Keys");
	mlx_string_put(vars->mlx, vars->win, 40, 65, RED, " + Key : More HD");
	mlx_string_put(vars->mlx, vars->win, 40, 85, RED, " - Key : Less HD");
}

void	display_guide_2(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 450, 25, BLACK, "--------------------");
	mlx_string_put(vars->mlx, vars->win, 450, 130, BLACK, "--------------------");
	for (int i = 28; i < 130; i+=9)
		mlx_string_put(vars->mlx, vars->win, 448, i, BLACK, "|");
	for (int i = 28; i < 130; i+=9)
		mlx_string_put(vars->mlx, vars->win, 573, i, BLACK, "|");
	mlx_string_put(vars->mlx, vars->win, 460, 35, RED, "Arrows Keys :");
	mlx_string_put(vars->mlx, vars->win, 460, 55, RED, "-> : Move Left");
	mlx_string_put(vars->mlx, vars->win, 460, 75, RED, "<- : Move Right");
	mlx_string_put(vars->mlx, vars->win, 460, 95, RED, "^  : Move Up");
	mlx_string_put(vars->mlx, vars->win, 460, 115, RED, "v  : Move Down");
	
}