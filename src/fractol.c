/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:05:11 by flverge           #+#    #+#             */
/*   Updated: 2023/12/04 07:56:53 by flverge          ###   ########.fr       */
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

static void	print_fractal(t_vars *vars, char **av)
{
	if (vars->fractal_name == 'M')
		print_mandelbrot(vars, av);
	// if (vars->fractal_name == 'J')
	// if (vars->fractal_name == 'X')
}

void	ft_init_mlx(t_vars *vars)
{
	if (!win_checker)
	{
		ft_printf("Incorrect window size\n");
		exit(1);
	}
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
	vars->pyth_escaped = 4; // checks for escaped values
}


int	main(int ac, char **av)
{
	t_vars	vars;

	if (!arg_checker(ac, av))
	{
		vars.fractal_name = av[1][0];

		ft_init_mlx(&vars);
		print_fractal(&vars, av);
		mlx_hook(vars.win, X_CROSS, 1L << 0, &win_close, &vars); // close button
		mlx_mouse_hook(vars.win, mouse_listener, &vars); // mouse listeners
		mlx_mouse_get_pos(vars.mlx, vars.win, &vars.x, &vars.y); // mouse position
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