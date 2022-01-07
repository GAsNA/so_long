/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:34:10 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/07 14:45:23 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	close_win(t_vars *vars)
{
	ft_putstr_fd("Good Bye!\n", 1);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (EXIT_SUCCESS);
}

static int	check_collision(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'E')
		return (1);
	return (0);
}

static void	go_up(t_all **all)
{
	if (check_collision((*all)->game->map, (*all)->game->x_perso,
			(*all)->game->y_perso - 1))
		return ;
	(*all)->game->mov_count += 1;
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
	if (check_collision((*all)->game->map, (*all)->game->x_perso,
			(*all)->game->y_perso + 1))
		return ;
	(*all)->game->mov_count += 1;
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
	if (check_collision((*all)->game->map, (*all)->game->x_perso - 1,
			(*all)->game->y_perso))
		return ;
	(*all)->game->mov_count += 1;
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
	if (check_collision((*all)->game->map, (*all)->game->x_perso + 1,
			(*all)->game->y_perso))
		return ;
	(*all)->game->mov_count += 1;
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
