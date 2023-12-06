/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:05:11 by flverge           #+#    #+#             */
/*   Updated: 2023/12/06 12:21:13 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_fractal(t_vars *vars)
{
	print_mandelbrot(vars);
	display_guide_1(vars);
	display_guide_2(vars);
}

void	ft_init_mlx(t_vars *vars)
{
	if (!win_checker())
	{
		ft_printf("Incorrect window size\n");
		exit(1);
	}
	vars->pyth_escaped = 4;
	vars->definition = 4;
	if (vars->definition <= 0)
		vars->definition = 1;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		malloc_error();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	if (!vars->win)
		failed_window(vars);
	vars->img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!vars->img)
		failed_image(vars);
	vars->adrr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_lenght, &vars->endian);
}

void	assign_julia(t_vars *vars)
{
	if (vars->julia_set == '1')
	{
		vars->julia_x = -0.8;
		vars->julia_y = 0.156;
	}
	else if (vars->julia_set == '2')
	{
		vars->julia_x = -0.4;
		vars->julia_y = 0.65;
	}
	else if (vars->julia_set == '3')
	{
		vars->julia_x = 0.37;
		vars->julia_y = 0.1;
	}
}

void	ft_init_args(t_vars *vars, char **av)
{
	vars->fractal_name = av[1][0];
	if (vars->fractal_name == 'J')
	{
		vars->julia_set = av[2][0];
		assign_julia(vars);
	}
	else
		vars->julia_set = '0';
	if (vars->fractal_name != 'J' && av[2])
		vars->color_arg = av[2][0];
	else if (vars->fractal_name == 'J' && av[3])
		vars->color_arg = av[3][0];
	else
		vars->color_arg = '0';
	vars->shift_x = 0.0;
	vars->shift_y = 0.0;
	vars->original_zoom = 1.0;
	ft_init_color(vars);
}


int	main(int ac, char **av)
{
	t_vars	vars;

	if (!arg_checker(ac, av))
	{
		ft_init_mlx(&vars);
		ft_init_args(&vars, av);
		print_fractal(&vars);
		mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &win_close, &vars); // remplace keywords
		mlx_hook(vars.win, ButtonPress, ButtonPressMask, mouse_listener, &vars);
		mlx_key_hook(vars.win, key_listener, &vars);
		mlx_loop(vars.mlx);
	}
	else
		return (1);
}
