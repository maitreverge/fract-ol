/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:19:13 by flverge           #+#    #+#             */
/*   Updated: 2023/11/21 12:03:58 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	atoi_color(char *str, int comas)
{
	int result;
	int polarity;
	int j;

	result = 0;
	polarity = 1;
	j = 0;
	while (j < comas)
	{
		if (*str == ',')
			j++;
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str = '-')
			polarity = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (result * polarity);	
}

int	fusion_4ints(int *c)
{
	return (c[0] << 24 | c[1] << 16 | c[2] << 8 | c[3]);
}

int	get_color(char *str)
{
	int result;
	int *colors;
	int i;
	
	i = 0;
	colors = malloc(sizeof(int) * 4);
	if (!colors)
		return (-1);
	while (i < 4)
	{
		colors[i] = atoi_color(str, i);
		if (colors[i] < 0 || colors[i] > 255)
		{
			ft_printf("Color block [%i] is not in the range [0-255]", i + 1);
			return -1;
		}
		i++;
	}
	result = fusion_4ints(colors);
	free(colors);
	return (result);
}
