/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:06:26 by flverge           #+#    #+#             */
/*   Updated: 2023/12/01 11:43:49 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	win_checker(void) // checks windows size
{
	if (WIN_HEIGHT <= 0 || WIN_WIDTH <= 0)
		return 1;
	return 0;
}
