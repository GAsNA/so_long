/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:34:10 by rleseur           #+#    #+#             */
/*   Updated: 2021/12/21 17:43:37 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	close_win(int keycode, t_vars *vars)
{
	(void) keycode;
	ft_putstr_fd("Good Bye!\n", 1);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	(void) vars;
	if (keycode == ESC)
	{
		close_win(keycode, vars);
		exit(0);
	}
	return (1);
}
