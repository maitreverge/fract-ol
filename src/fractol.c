/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:05:11 by flverge           #+#    #+#             */
/*   Updated: 2023/11/20 16:31:22 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


typedef struct s_data
{
	void	*img;
	char	*adrr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}			t_data;

// calculates the offset and assign a color to a specific pixel
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adrr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_form(t_data *data, void *mlx, void *window)
{
	int x = 0;
	int y = 0;

	while (x < 200)
	{
		my_mlx_pixel_put(&data->img, x, y, 0x000FFF00);
		// usleep(5000);
		
		x++;
	}
	// mlx_put_image_to_window(mlx, window, data->img, 200, 100);

	while ( y < 200)
	{
		my_mlx_pixel_put(&data->img, x, y, 0x000FFF00);
		// usleep(5000);
		
		y++;
	}
	mlx_put_image_to_window(mlx, window, data->img, 200, 100);
}

int	main(void)
{
	void	*mlx;
	void	*window;

	t_data img;
	
	// init image
	mlx = mlx_init();

	// creates a new windows
	window = mlx_new_window(mlx, 1920, 1080, "Hello, world !");
	
	// creates an image pushed into the window
	img.img = mlx_new_image(mlx, 1920, 1080);

	img.adrr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);

	print_form(&img, mlx, window);

	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

	// mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	
	// keeps the windows alive
	mlx_loop(mlx);
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