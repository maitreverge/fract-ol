/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:06:26 by flverge           #+#    #+#             */
/*   Updated: 2023/12/02 16:28:57 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	win_checker(void)
{
	if (WIN_HEIGHT <= 0 || WIN_WIDTH <= 0)
		return (1);
	return (0);
}

int	win_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_display(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	return (exit(0), 0);
}

void	failed_window(t_vars *vars)
{
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	malloc_error();
}

void	failed_image(t_vars *vars)
{
	mlx_destroy_display(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	malloc_error();
}

void	malloc_error(void)
{
	perror("Error From malloc");
	exit(1);
}
