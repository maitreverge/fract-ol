/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:37:12 by flverge           #+#    #+#             */
/*   Updated: 2023/11/28 12:23:09 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	display_options(int num_err)
{
	if (!num_err)
	{
		ft_printf("🚀 Fractol Usage 🚀\n------------\n");
		ft_printf("1️⃣ st argument : <Select a Fractal : J for Julia, M for Mandelbrot, X for bonus>");
		ft_printf("\n\n2️⃣ nd argument : If Julia set selected, please choose which set <1 or 2 or 3>");
		ft_printf("\n\n3️⃣ rd argument(Optional) : select ONE global color theme between\n<R for 🟥");
		ft_printf(", G for 🟩 , B for 🟦 , ""Rainbow"" for beautiful colors🌈, LSD for psychedelics 😵‍💫 >");
		// ft_printf("Examples : ./a.out J 2 Rainbow\n./a.out M\n./a.out X LSD\n./a.out J 1\n")
	}
	else if (num_err == 1)
		ft_printf("Wrong fractal choosen : <Select a Fractal : J for Julia, M for Mandelbrot, X for bonus>");
	else if (num_err == 2)
		ft_printf("\nWrong Julia set :\nIf Julia set selected, please choose which set <1 or 2 or 3>");
	else if (num_err == 3)
	{
		ft_printf("\n3(Optional) : select ONE global color theme between\n<R for 🟥");
		ft_printf(", G for 🟩 , B for 🟦 , ""Rainbow"" for beautiful colors🌈, LSD for psychedelics 😵‍💫 >");
	}
	ft_printf("\n-------\nExamples :\n./a.out J 2 Rainbow\n./a.out M\n./a.out X LSD\n./a.out J 1\n");
}

int	first_arg(char *av1) // working
{
	// ? m/M - j/J - x/X full uppercase or check double possibilities
	if (ft_strncmp(av1, "J", 1) && ft_strncmp(av1, "M", 1) && ft_strncmp(av1, "X", 1) )
		return 1;
	return 0;
}

int		second_arg_j(char **av)
{
	if (av[1] == "J")
	{
		if (av[2] != "1" || av[2] != "2" || av[2] != "3")
		// ! WORKING HERE
		if (ft_strncmp(av[2], "1", 1))
			return 1;
	}
	return (0);
}

int third_arg(int ac, char **av)
{
	// if pas de J et des couleurs
	if (av[1] != "J" && ac == 3)
	{
		if (av[2] != "R" && av[2] != "G" && av[2] != "B" && ft_strncmp(av[2], "Rainbow", 7) && ft_strncmp(av[2], "LSD", 3))
			return 1;
	}
	// if J et des couleurs
	if (av[1] == "J" && ac == 4)
	{
		if (av[3] != "R" && av[3] != "G" && av[3] != "B" && ft_strncmp(av[3], "Rainbow", 7) && ft_strncmp(av[3], "LSD", 3))
			return 1;
	}
	return (0);
}

int arg_checker(int ac, char **av)
{
	if (ac == 1 || ac > 4)
	{
		display_options(0);
		return (1);
	}
	if (first_arg(av[1]))
	{
		display_options(1);
		return (1);
	}
	if (second_arg_j(av))
	{
		display_options(2);
		return (1);
	}
	if (third_arg(ac, av))
	{
		display_options(3);
		return (1);
	}
	return (0);
}
