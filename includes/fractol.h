/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:00:32 by flverge           #+#    #+#             */
/*   Updated: 2023/11/21 15:39:59 by flverge          ###   ########.fr       */
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

# define WIN_WIDTH 3648 // 1920 * 1080 *** 1.9
# define WIN_HEIGHT 2052

// enum of mlk hooks events
typedef enum e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}			t_event;

//struct test
typedef struct s_data
{
	void	*img;
	char	*adrr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}			t_data;

typedef struct s_var
{
	void	*mlx;
	void	*win;
}		t_var;

// fractol.c
void	print_form(t_data *data, void *mlx, void *window, char *arg);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// color.c
int		atoi_color(char *str, int comas);
int		fusion_4ints(int *c);
int		get_color(char *str);

// hooks.c
int win_close(int keycode, t_var *var);






#endif 