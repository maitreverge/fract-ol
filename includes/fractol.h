/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:00:32 by flverge           #+#    #+#             */
/*   Updated: 2023/11/23 17:54:53 by flverge          ###   ########.fr       */
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
# include <X11/X.h>
# include <X11/keysym.h>


// enum of mlk hooks events
typedef enum e_event
{
	WIN_HEIGHT = 2052,
	WIN_WIDTH = 3648,
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
	void	*mlx;
	void	*win;
	int		color;
	void	*img;
	char	*adrr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}		t_vars;

// fractol.c
void	print_form(t_vars *vars, void *mlx, void *window, int color);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);

// color.c
int		atoi_color(char *str, int comas);
int		fusion_4ints(int *c);
int		get_color(char *str);

// hooks.c
int		win_close(t_vars *var);
int		key_listener(int keycode, t_vars *vars);
int	mouse_listener(int mouseclick, t_vars *vars);






#endif 