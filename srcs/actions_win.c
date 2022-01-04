/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:34:10 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/04 16:34:22 by rleseur          ###   ########.fr       */
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

static void	go_up(t_vars **vars)
{
	(*vars)->count += 1;
	ft_putstr_fd("UP\n", 1);
}

static void	go_down(t_vars **vars)
{
	(*vars)->count += 1;
	ft_putstr_fd("DOWN\n", 1);
}

static void	go_left(t_vars **vars)
{
	(*vars)->count += 1;
	ft_putstr_fd("LEFT\n", 1);
}

static void	go_right(t_vars **vars)
{
	(*vars)->count += 1;
	ft_putstr_fd("RIGHT\n", 1);
}

int	key_hook(int keycode, t_vars *vars)
{
	(void) vars;
	if (keycode == ESC)
	{
		close_win(keycode, vars);
		exit(0);
	}
	else if (keycode == W || keycode == UP)
		go_up(&vars);
	else if (keycode == S || keycode == DOWN)
		go_down(&vars);
	else if (keycode == A || keycode == LEFT)
		go_left(&vars);
	else if (keycode == D || keycode == RIGHT)
		go_right(&vars);
	ft_putstr_fd("Count mov.: ", 1);
	ft_putnbr_fd(vars->count, 1);
	ft_putstr_fd("\n", 1);
	return (1);
}
