/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guides.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:02:21 by flverge           #+#    #+#             */
/*   Updated: 2023/12/05 17:05:17 by flverge          ###   ########.fr       */
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
	mlx_string_put(vars->mlx, vars->win, 250, 25, BLACK, "--------------------");
	
}