/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:34:10 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/07 11:13:38 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	close_win(t_vars *vars)
{
	ft_putstr_fd("Good Bye!\n", 1);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (EXIT_SUCCESS);
}

static void	go_up(t_all **all)
{
	(*all)->game->mov_count += 1;
	ft_putstr_fd("UP\n", 1);
	mlx_put_image_to_window((*all)->vars->mlx, (*all)->vars->win,
		(*all)->imgs->ground.img, (*all)->game->x_perso * SIZE,
		(*all)->game->y_perso * SIZE);
	(*all)->game->y_perso -= 1;
	mlx_put_image_to_window((*all)->vars->mlx, (*all)->vars->win,
		(*all)->imgs->perso_b.img, (*all)->game->x_perso * SIZE,
		(*all)->game->y_perso * SIZE);
}

static void	go_down(t_all **all)
{
	(*all)->game->mov_count += 1;
	ft_putstr_fd("DOWN\n", 1);
	mlx_put_image_to_window((*all)->vars->mlx, (*all)->vars->win,
		(*all)->imgs->ground.img, (*all)->game->x_perso * SIZE,
		(*all)->game->y_perso * SIZE);
	(*all)->game->y_perso += 1;
	mlx_put_image_to_window((*all)->vars->mlx, (*all)->vars->win,
		(*all)->imgs->perso_f.img, (*all)->game->x_perso * SIZE,
		(*all)->game->y_perso * SIZE);
}

static void	go_left(t_all **all)
{
	(*all)->game->mov_count += 1;
	ft_putstr_fd("LEFT\n", 1);
	mlx_put_image_to_window((*all)->vars->mlx, (*all)->vars->win,
		(*all)->imgs->ground.img, (*all)->game->x_perso * SIZE,
		(*all)->game->y_perso * SIZE);
	(*all)->game->x_perso -= 1;
	mlx_put_image_to_window((*all)->vars->mlx, (*all)->vars->win,
		(*all)->imgs->perso_l.img, (*all)->game->x_perso * SIZE,
		(*all)->game->y_perso * SIZE);
}

static void	go_right(t_all **all)
{
	(*all)->game->mov_count += 1;
	ft_putstr_fd("RIGHT\n", 1);
	mlx_put_image_to_window((*all)->vars->mlx, (*all)->vars->win,
		(*all)->imgs->ground.img, (*all)->game->x_perso * SIZE,
		(*all)->game->y_perso * SIZE);
	(*all)->game->x_perso += 1;
	mlx_put_image_to_window((*all)->vars->mlx, (*all)->vars->win,
		(*all)->imgs->perso_r.img, (*all)->game->x_perso * SIZE,
		(*all)->game->y_perso * SIZE);
}

int	key_hook(int keycode, t_all *all)
{
	if (keycode == ESC)
	{
		close_win(all->vars);
		exit(0);
	}
	else if (keycode == W || keycode == UP)
		go_up(&all);
	else if (keycode == S || keycode == DOWN)
		go_down(&all);
	else if (keycode == A || keycode == LEFT)
		go_left(&all);
	else if (keycode == D || keycode == RIGHT)
		go_right(&all);
	ft_putstr_fd("Count mov.: ", 1);
	ft_putnbr_fd(all->game->mov_count, 1);
	ft_putstr_fd("\n", 1);
	return (1);
}
