/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:00:32 by flverge           #+#    #+#             */
/*   Updated: 2023/12/02 15:22:59 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line_bonus.h"
# include <fcntl.h> // open and options
# include <unistd.h> // write, close, access, dup, dup2, execve
# include <stdlib.h> // malloc and free
# include <stdio.h> // perror
# include <errno.h> // makes errno a global variable usable with strerror(errno)
# include <math.h>  // Authorized functions
# include <string.h> // strerror
# include <X11/X.h>
# include <X11/keysym.h>

# define MALLOC_ERROR 1


// enum of mlk hooks events
typedef enum e_event
{
	WIN_WIDTH = 1500,
	WIN_HEIGHT = 1500,
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	X_CROSS = 17
}			t_event;

typedef enum e_keys
{
	ECHAP_KEY = 65307,
	PLUS_KEY = 65451,
	MINUS_KEY = 65453,
	UP_KEY = 65362,
	DOWN_KEY = 65364,
	LEFT_KEY = 65361,
	RIGHT_KEY = 65363
	// add keys de numeros
}			t_keys;

typedef enum e_mouse
{
	LEFT_CLICK = 1,
	MIDDLE_CLICK,
	RIGHT_CLICK,
	SCROLL_UP,
	SCROLL_DOWN
}			t_mouse;

 

typedef struct s_vars
{
	char	fractal_name;
	void	*mlx;
	void	*win;
	int		color; // ! to do : split into another struct
	void	*img; // split into another struct
	char	*adrr; // split into another struct
	int		bits_per_pixel; // split into another struct
	int		line_lenght; // split into another struct
	int		endian; // split into another struct
	int		x; // position for tracking the mouse
	int		y; // position for tracking the mouse
	int		temp_x; // ? really useful
	int		temp_y; // ? really useful
}		t_vars;

typedef struct s_complex
{
	// real number
    double	x;
	// imaginary number
    double	y;
}			t_complex;


// fractol.c
void	print_form(t_vars *vars, void *mlx, void *window, int color);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void	ft_init_mlx(t_vars *vars);


// color.c
int		atoi_color(char *str, int comas);
int		fusion_4ints(int *c);
int		get_color(char *str);

// hooks.c
int		key_listener(int keycode, t_vars *vars);
int		mouse_listener(int mouseclick, t_vars *vars);
int		mouse_on_off(t_vars *vars);

// security.c
int		win_checker(void);
int		win_close(t_vars *var);
void	failed_window(t_vars *vars);
void	failed_image(t_vars *vars);
void	malloc_error(void);


// args_checker.c
void	display_options(int num_err);
int		first_arg(char *av1);
int		second_arg_j(char **av);
int		third_arg(int ac, char **av);
int		arg_checker(int ac, char **av);

// utils.c
int		ft_strcmp(char *s1, char *s2);

// mandelbrot.c
void	print_mandelbrot(t_vars *vars, char **av);
double map(double i, double new_min, double new_max, double old_max);


#endif 