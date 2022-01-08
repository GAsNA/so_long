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

static int	check_collectible(char **map, int x, int y)
{
	if (map[y][x] == 'C')
		return (1);
	return (0);
}

static int	check_exit(char **map, int x, int y)
{
	if (map[y][x] == 'E')
		return (1);
	return (0);
}

static void	activate_exit(t_all **all)
{
	int	i;
	int	j;

	i = -1;
	while ((*all)->game->map[++i])
	{
		j = -1;
		while ((*all)->game->map[i][++j])
		{
			if ((*all)->game->map[i][j] == 'E')
				mlx_put_image_to_window((*all)->vars->mlx,
					(*all)->vars->win, (*all)->imgs->exit_op.img,
					j * SIZE, i * SIZE);
		}
	}
	(*all)->game->activated_exit = 1;
}

static void	go_up(t_all **all)
{
	if ((*all)->game->activated_exit
			&& check_exit((*all)->game->map, (*all)->game->x_perso,
				(*all)->game->y_perso - 1))
	{
		(*all)->game->mov_count += 1;
		mlx_put_image_to_window((*all)->vars->mlx, (*all)->vars->win,
			(*all)->imgs->ground.img, (*all)->game->x_perso * SIZE,
			(*all)->game->y_perso * SIZE);
		(*all)->game->perso_exited = 1;
	}
	if (check_collision((*all)->game->map, (*all)->game->x_perso,
			(*all)->game->y_perso - 1))
		return ;
	if (check_collectible((*all)->game->map, (*all)->game->x_perso,
			(*all)->game->y_perso - 1))
		(*all)->game->got_cards++;
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
	if ((*all)->game->activated_exit
			&& check_exit((*all)->game->map, (*all)->game->x_perso,
				(*all)->game->y_perso + 1))
	{
		(*all)->game->mov_count += 1;
		mlx_put_image_to_window((*all)->vars->mlx, (*all)->vars->win,
			(*all)->imgs->ground.img, (*all)->game->x_perso * SIZE,
			(*all)->game->y_perso * SIZE);
		(*all)->game->perso_exited = 1;
	}
	if (check_collision((*all)->game->map, (*all)->game->x_perso,
			(*all)->game->y_perso + 1))
		return ;
	if (check_collectible((*all)->game->map, (*all)->game->x_perso,
			(*all)->game->y_perso + 1))
		(*all)->game->got_cards++;
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
	if ((*all)->game->activated_exit
			&& check_exit((*all)->game->map, (*all)->game->x_perso - 1,
				(*all)->game->y_perso))
	{
		(*all)->game->mov_count += 1;
		mlx_put_image_to_window((*all)->vars->mlx, (*all)->vars->win,
			(*all)->imgs->ground.img, (*all)->game->x_perso * SIZE,
			(*all)->game->y_perso * SIZE);
		(*all)->game->perso_exited = 1;
	}
	if (check_collision((*all)->game->map, (*all)->game->x_perso - 1,
			(*all)->game->y_perso))
		return ;
	if (check_collectible((*all)->game->map, (*all)->game->x_perso - 1,
			(*all)->game->y_perso))
		(*all)->game->got_cards++;
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
	if ((*all)->game->activated_exit
			&& check_exit((*all)->game->map, (*all)->game->x_perso + 1,
				(*all)->game->y_perso))
	{
		(*all)->game->mov_count += 1;
		mlx_put_image_to_window((*all)->vars->mlx, (*all)->vars->win,
			(*all)->imgs->ground.img, (*all)->game->x_perso * SIZE,
			(*all)->game->y_perso * SIZE);
		(*all)->game->perso_exited = 1;
	}
	if (check_collision((*all)->game->map, (*all)->game->x_perso + 1,
			(*all)->game->y_perso))
		return ;
	if (check_collectible((*all)->game->map, (*all)->game->x_perso + 1,
			(*all)->game->y_perso))
		(*all)->game->got_cards++;
	(*all)->game->mov_count += 1;
	if ((*all)->game->activated_exit
			&& check_exit((*all)->game->map, (*all)->game->x_perso + 1,
				(*all)->game->y_perso))
	{
		mlx_put_image_to_window((*all)->vars->mlx, (*all)->vars->win,
			(*all)->imgs->ground.img, (*all)->game->x_perso * SIZE,
			(*all)->game->y_perso * SIZE);
		(*all)->game->perso_exited = 1;
	}
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
	if (all->game->perso_exited)
		return (1);
	if (keycode == W || keycode == UP)
		go_up(&all);
	else if (keycode == S || keycode == DOWN)
		go_down(&all);
	else if (keycode == A || keycode == LEFT)
		go_left(&all);
	else if (keycode == D || keycode == RIGHT)
		go_right(&all);
	if (all->game->got_cards == all->game->total_cards)
		activate_exit(&all);
	ft_putstr_fd("Count mov.: ", 1);
	ft_putnbr_fd(all->game->mov_count, 1);
	ft_putstr_fd("\n", 1);
	return (1);
}
