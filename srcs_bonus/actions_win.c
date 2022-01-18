/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:34:10 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/18 22:54:59 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	close_win(t_all *all)
{
	ft_putstr_fd("Good Bye!\n", 1);
	all_free(all);
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

int	key_hook(int keycode, t_all *all)
{
	if (keycode == ESC)
	{
		close_win(all);
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
	if (check_collectible(&all->game, all->game->x_perso,
			all->game->y_perso))
	{
		all->game->got_cards++;
		put_count_cards(all);
	}
	if (all->game->got_cards == all->game->total_cards)
		activate_exit(&all);
	return (1);
}
