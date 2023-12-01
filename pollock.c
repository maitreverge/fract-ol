/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pollock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:39:47 by flverge           #+#    #+#             */
/*   Updated: 2023/12/01 13:38:13 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ! gcc pollock.c minilibx-linux/libmlx.a -lXext -lX11 -lm -lz -o pollock 

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#define WIDTH 1200
#define HEIGHT 800

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		color;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		x; // position for tracking the mouse
	int		y; // position for tracking the mouse
	int		temp_x; // ? really useful
	int		temp_y; // ? really useful
}		t_vars;


void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_lenght + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	t_vars vars;
	
	vars.mlx = mlx_init(); // starts the connexion 
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "my first window"); // start a window

	vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_lenght, &vars.endian);

	for (int x = WIDTH * 0.2; x < WIDTH * 0.8; x++)
	{
		for (int y = HEIGHT * 0.2; y < HEIGHT * 0.8; y++)
		{
			// mlx_pixel_put(mlx, mlx_window, x, y, rand()); // prints a red pixel
			my_mlx_pixel_put(&vars, x, y, rand());
		}
	}
	// mlx_put_image_to_window(vars.mlx, vars.win, vars.img, WIDTH * 0.5, HEIGHT * 0.5);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);

	mlx_string_put(vars.mlx, vars.win, WIDTH * 0.6, HEIGHT * 0.9, 0xff0000, "MLX la bonne librarie cancer");
	
	mlx_loop(vars.mlx);
}