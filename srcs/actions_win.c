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

static void	put_count_mov(t_all *all)
{
	ft_putstr_fd("Count mov.: ", 1);
	ft_putnbr_fd(all->game->mov_count, 1);
	ft_putstr_fd("\n", 1);
}

static void	put_count_cards(t_all *all)
{
	ft_putnbr_fd(all->game->got_cards, 1);
	ft_putchar_fd('\\', 1);
	ft_putnbr_fd(all->game->total_cards, 1);
	ft_putstr_fd(" cards\n", 1);
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
	put_count_mov(all);
	put_count_cards(all);
	return (1);
}
