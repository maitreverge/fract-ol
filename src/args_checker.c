/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:37:12 by flverge           #+#    #+#             */
/*   Updated: 2023/12/06 10:42:34 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	display_options(int num_err) 
{
	if (!num_err)
	{
		ft_printf("🚀 Fractol Usage 🚀\n------------\n");
		ft_printf("1️⃣ st argument : <Select a Fractal : J for Julia");
		ft_printf(", M for Mandelbrot, X for bonus>");
		ft_printf("\n\n2️⃣ nd argument : If Julia set selected,");
		ft_printf(" please choose which set <1 or 2 or 3>");
		ft_printf("\n\n3️⃣ rd argument(Optional) : select ONE ");
		ft_printf("global color theme between\n<R for 🟥");
		ft_printf(", G for 🟩 , B for 🟦 , W for beautiful ");
		ft_printf("colors🌈, L for psychedelics 😵‍💫 >");
	}
	else if (num_err == 1)
		ft_printf("⛔ Wrong Fractal choosen\nPlease choose <M or J or X>");
	else if (num_err == 2)
		ft_printf("\n⛔ Wrong Julia set:\nPlease choose set <1 or 2 or 3>");
	else if (num_err == 3)
	{
		ft_printf("\n⛔ Wrong Color set :\nPlease choose a global color");
		ft_printf("<R, G, B, W, L>");
	}
	ft_printf("\n-------\nExamples :\n./a.out J 2 WOW\n");
	ft_printf("./fractol M\n./fractol X L\n./fractol J 1\n");
}

int	first_arg(char *av1)
{
	if (ft_strcmp(av1, "J") && ft_strcmp(av1, "M") && ft_strcmp(av1, "X"))
		return (1);
	return (0);
}

int	second_arg_j(char **av)
{
	if (!ft_strcmp(av[1], "J"))
	{
		if (!av[2])
			return (1);
		if (ft_strcmp(av[2], "1")
			&& ft_strcmp(av[2], "2") && ft_strcmp(av[2], "3"))
			return (1);
	}
	return (0);
}

int	third_arg(int ac, char **av)
{
	if (ft_strcmp(av[1], "J") && ac == 3)
	{
		if (ft_strcmp(av[2], "R") && ft_strcmp(av[2], "G")
			&& ft_strcmp(av[2], "B") && ft_strcmp(av[2], "W")
			&& ft_strcmp(av[2], "L"))
			return (1);
	}
	if (!ft_strcmp(av[1], "J") && ac == 4)
	{
		if (ft_strcmp(av[3], "R") && ft_strcmp(av[3], "G")
			&& ft_strcmp(av[3], "B") && ft_strcmp(av[3], "W")
			&& ft_strcmp(av[3], "L"))
			return (1);
	}
	return (0);
}

int	arg_checker(int ac, char **av)
{
	if (ac > 4)
	{
		ft_printf("⛔ Too much arguments\n");
		display_options(0);
		return (1);
	}
	if (ac == 1)
	{
		display_options(0);
		return (1);
	}
	if (first_arg(av[1]))
		display_options(1);
	if (second_arg_j(av))
		display_options(2);
	if (third_arg(ac, av))
		display_options(3);
	if (first_arg(av[1]) || second_arg_j(av) || third_arg(ac, av))
		return (1);
	return (0);
}
