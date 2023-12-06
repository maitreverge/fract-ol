/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:00:32 by flverge           #+#    #+#             */
/*   Updated: 2023/12/06 14:00:56 by flverge          ###   ########.fr       */
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
	PSY_COL_2 = 0x800080,
	PSY_COL_3 = 0x00FF7F,
	PSY_COL_5 = 0xFF1493,
	PSY_COL_6 = 0x8A2BE2,
	PSY_COL_7 = 0x00CED1,
	PSY_COL_8 = 0xFF6347,
	PSY_COL_9 = 0x7CFC00,
	PSY_COL_10 = 0x4682B4
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
	RIGHT_KEY = 65363,
	SPACE_KEY = 32,
	MANDELBROT = 109,
	JULIA = 106,
	TRICORN = 120
}			t_keys;

typedef enum e_mouse
{
	LEFT_CLICK = 1,
	MIDDLE_CLICK,
	RIGHT_CLICK,
	SCROLL_UP,
	SCROLL_DOWN
}			t_mouse;

typedef struct s_colors
{
	int	col_min;
	int	col_max;
	int	col_fract;
}			t_colors;

typedef struct s_vars
{
	t_colors	colors;
	double		julia_x;
	double		julia_y;
	double		pyth_escaped;
	double		shift_x;
	double		shift_y;
	double		original_zoom;
	void		*mlx;
	void		*win;
	void		*img;
	char		fractal_name;
	char		julia_set;
	char		color_arg;
	char		*adrr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
	int			x; // ? useful
	int			y; // ? useful
	int			temp_x; // ? really useful
	int			temp_y; // ? really useful
	int			definition;
}		t_vars;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;


// fractol.c
void	print_form(t_vars *vars, void *mlx, void *window, int color);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void	ft_init_mlx(t_vars *vars);
void	print_fractal(t_vars *vars);


// color.c
void	ft_init_color_2(t_vars *vars);
void	ft_init_color(t_vars *vars);
void	fractal_colorswap(int keycode, t_vars *vars);
void	fractal_colorshift_mouse(t_vars *vars);
void	fractal_colorshift_space(t_vars *vars);




// hooks.c
int		key_listener(int keycode, t_vars *vars);
int		mouse_listener(int mouseclick, int x, int y, t_vars *vars);
int		mouse_on_off(t_vars *vars);
void	assign_julia(t_vars *vars);
void	fractal_hotswap(int keycode, t_vars *vars);
void	fractal_move(int keycode, t_vars *vars);
void	fractal_definition(int keycode, t_vars *vars);





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
double	atodbl(char *str);


// mandelbrot.c
double	map(double i, double new_min, double new_max, double old_max);
void	handle_pixels(int x, int y, t_vars *v);
void	print_mandelbrot(t_vars *vars);
void	which_fractal(t_complex *z, t_complex *c, t_vars *vars);
t_complex	sqrt_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);

// guides.c
void	display_guide_1(t_vars *vars);
void	display_guide_2(t_vars *vars);

#endif 