/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:05:11 by flverge           #+#    #+#             */
/*   Updated: 2023/12/05 15:58:51 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// calculates the offset and assign a color to a specific pixel
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->adrr + (y * vars->line_lenght + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_fractal(t_vars *vars)
{
	// if (vars->fractal_name == 'M')
	print_mandelbrot(vars);
	// if (vars->fractal_name == 'J')
	// if (vars->fractal_name == 'X')
	// ! make full usage function within the print fractal
	mlx_string_put(vars->mlx, vars->win, 41, 35, RED, "Controls Keys");
}

void	ft_init_mlx(t_vars *vars)
{
	if (!win_checker)
	{
		ft_printf("Incorrect window size\n");
		exit(1);
	}
	vars->pyth_escaped = 4; // checks for escaped values
	vars->definition = 1; // ! needs double checks both in key listenner and here
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

void assign_julia(t_vars *vars)
{
    if (vars->julia_set == '1')
    {
        vars->julia_x = -0.8;
        vars->julia_y = 0.156;
    }
    else if (vars->julia_set == '2')
    {
        vars->julia_x = 0.285;
        vars->julia_y = 0.01;
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
		vars->julia_set = '0'; // nul setting variable
	if (vars->fractal_name != 'J' && av[2])
		vars->color_arg = av[2][0];
	else if (vars->fractal_name == 'J' && av[3])
		vars->color_arg = av[3][0];
	vars->shift_x = 0.0;
	vars->shift_y = 0.0;
	vars->original_zoom = 1.0;
	
}


int	main(int ac, char **av)
{
	t_vars	vars;

	if (!arg_checker(ac, av))
	{
		ft_init_mlx(&vars);
		ft_init_args(&vars, av); // goal : bring everything inside one master struct
		print_fractal(&vars);
		// mlx_string_put(vars.mlx, vars.win, 41, 35, RED, "Controls Keys");
		mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &win_close, &vars); // close button
		mlx_hook(vars.win, ButtonPress, ButtonPressMask, mouse_listener, &vars); // souris
		mlx_key_hook(vars.win, key_listener, &vars); // keyboard listeners
		mlx_loop(vars.mlx);
	}
	else
		return (1);
}

/*

Before we can do anything with the MiniLibX library we must include the <mlx.h> header to access all the functions and we should execute the mlx_init function.
This will establish a connection to the correct graphical system and will return a void * which holds the location of our current MLX instance.

----------------

When you run the code, you can’t help but notice that nothing pops up and that nothing is being rendered.
Well, this obviously has something to do with the fact that you are not creating a window yet, so let’s try initializing a tiny window which will stay open forever.
You can close it by pressing CTRL + C in your terminal. To achieve this, we will simply call the mlx_new_window function,
which will return a pointer to the window we have just created. We can give the window height, width and a title. We then will have to call mlx_loop to initiate the window rendering.

*/