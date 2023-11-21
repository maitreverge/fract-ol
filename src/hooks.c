/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:52:35 by flverge           #+#    #+#             */
/*   Updated: 2023/11/21 15:22:55 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// hook for the escape key
int win_close(int keycode, t_var *var)
{
	mlx_destroy_window(var->mlx, var->win);
	return (0);
}