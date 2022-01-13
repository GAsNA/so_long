/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:34:10 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/13 23:06:22 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	close_win(t_all *all)
{
	int	i;

	ft_putstr_fd("Good Bye!\n", 1);
	i = -1;
	while (all->game->map[++i])
		free(all->game->map[i]);
	free(all->game->map);
	mlx_loop_end(all->vars->mlx);
	mlx_destroy_image(all->vars->mlx, all->imgs->card.img);
	mlx_destroy_image(all->vars->mlx, all->imgs->exit_op.img);
	mlx_destroy_image(all->vars->mlx, all->imgs->exit_cl.img);
	mlx_destroy_image(all->vars->mlx, all->imgs->ground.img);
	mlx_destroy_image(all->vars->mlx, all->imgs->wall.img);
	mlx_destroy_image(all->vars->mlx, all->imgs->perso_b.img);
	mlx_destroy_image(all->vars->mlx, all->imgs->perso_f.img);
	mlx_destroy_image(all->vars->mlx, all->imgs->perso_l.img);
	mlx_destroy_image(all->vars->mlx, all->imgs->perso_r.img);
	mlx_destroy_window(all->vars->mlx, all->vars->win);
	mlx_destroy_display(all->vars->mlx);
	free(all->vars->mlx);
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
