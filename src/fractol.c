/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:05:11 by flverge           #+#    #+#             */
/*   Updated: 2023/11/21 12:08:50 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// calculates the offset and assign a color to a specific pixel
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adrr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_form(t_data *data, void *mlx, void *window, char *arg)
{
	int x = 0;
	int y = 0;

	while (x < 200)
	{
		my_mlx_pixel_put(data, x, y, get_color(arg));
		x++;
	}
	while ( y < 200)
	{
		my_mlx_pixel_put(data, x, y, get_color(arg));
		y++;
	}
	mlx_put_image_to_window(mlx, window, data->img, 200, 100);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		void	*mlx;
		void	*window;

		t_data img;

		// test_print();
		
		// init image
		mlx = mlx_init();

		// creates a new windows
		window = mlx_new_window(mlx, 1920, 1080, "Hello, world !");
		
		// creates an image pushed into the window
		img.img = mlx_new_image(mlx, 1920, 1080);

		img.adrr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);

		print_form(&img, mlx, window, av[1]);
		
		// keeps the windows alive
		mlx_loop(mlx);
	}
	else
		ft_printf("mdr nop");
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