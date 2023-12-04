/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:00:32 by flverge           #+#    #+#             */
/*   Updated: 2023/12/04 15:36:11 by flverge          ###   ########.fr       */
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
// # define DEFINITION 42

typedef enum e_basic_colors
{
    BLACK = 0x000000,
    WHITE = 0xFFFFFF,
	RED = 0xFF0000,
    GREEN = 0x00FF00,
    BLUE = 0x0000FF,
    YELLOW = 0xFFFF00,
    MAGENTA = 0xFF00FF,
    CYAN = 0x00FFFF,
	ORANGE = 0xFFA500
}			t_basic_colors;

typedef enum e_psy_colors
{
	MIN_GREEN = 0x006400,
	MAX_GREEN = 0x00FF00,
	PSY_PURPLE = 0xDF00FF,
    PSY_COL_2 = 0x800080, // Purple
    PSY_COL_3 = 0x00FF7F, // Spring Green
    PSY_COL_5 = 0xFF1493, // Deep Pink
    PSY_COL_6 = 0x8A2BE2, // Blue Violet
    PSY_COL_7 = 0x00CED1, // Dark Turquoise
    PSY_COL_8 = 0xFF6347, // Tomato
    PSY_COL_9 = 0x7CFC00, // Lawn Green
    PSY_COL_10 = 0x4682B4, // Steel Blue
}			t_psy_colors;

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
	char	julia_set;
	char	color_arg;
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
	double	pyth_escaped; // checked value for escaped possibilities
	int		definition;// make definition change for plus and minus key
	double shift_x; // valeurs qui bougent les fleches
	double shift_y; // valeurs qui bougent les fleches
	double	zoom;
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
void	print_fractal(t_vars *vars);


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
double map(double i, double new_min, double new_max, double old_max);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex   sqrt_complex(t_complex z);
void    handle_pixels(int x, int y, t_vars *vars);
void	print_mandelbrot(t_vars *vars);

#endif 