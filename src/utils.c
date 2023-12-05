/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:33:20 by flverge           #+#    #+#             */
/*   Updated: 2023/12/05 16:11:26 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

// ! not so useful ft, see if args are implemented later
// double atodbl(char *str)
// {
// 	double result;
// 	double pow;

// 	result = 1;
// 	pow = 1;
// 	while (*str)
// 	{
// 		pow /= (10 + (*str - 48));
// 		result = result + (*str - 48) * pow;
// 		*str++;
// 	}
// 	return (result);
// }
