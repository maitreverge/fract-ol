/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:05:11 by flverge           #+#    #+#             */
/*   Updated: 2023/11/28 11:20:37 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// calculates the offset and assign a color to a specific pixel
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->adrr + (y * vars->line_lenght + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_form(t_vars *vars, void *mlx, void *window, int color)
{
	int x = 0;
	int y = 0;

	while (x < 200 && x < WIN_WIDTH)
	{
		my_mlx_pixel_put(vars, x, y, color);
		x++;
	}
	while ( y < 200 && WIN_HEIGHT)
	{
		my_mlx_pixel_put(vars, x, y, color);
		y++;
	}
	mlx_put_image_to_window(mlx, window, vars->img, 200, 100);
}

int	main(int ac, char **av)
{
	if (!arg_checker(ac, av))
	{
		// temp check
		printf("Args OK");
		exit(0);
		t_vars vars;

		if (win_checker)
		{
			ft_printf("Incorrect window size\n");
			exit(1);
		}
		vars.color = get_color(av[1]);
		if (vars.color < 0)
		{
			ft_printf("Selected color are not in the range [0-255]\n");
			exit(-1);
		}
		vars.mlx = mlx_init();
		if (!vars.mlx)
			perror("Error");

		// creates a new windows
		vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
		if (!vars.win)
			perror("Error");
		
		// creates an image pushed into the window
		vars.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);

		vars.adrr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_lenght, &vars.endian);

		print_form(&vars, vars.mlx, vars.win, vars.color);

		// Makes the cross clean close the program
		mlx_hook(vars.win, X_CROSS, 1L << 0, &win_close, &vars);
		// mouse listenner
		mlx_mouse_hook(vars.win, mouse_listener, &vars);
		// mouse trackers
		mlx_mouse_get_pos(vars.mlx, vars.win, &vars.x, &vars.y);
		// Key listenner
		mlx_key_hook(vars.win, key_listener, &vars);
		// keeps the windows alive
		mlx_loop(vars.mlx);
		win_close(&vars);
		return (0);
	}
	else
		exit(1);
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