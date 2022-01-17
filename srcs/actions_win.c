/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:34:10 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/17 17:28:52 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	close_win(t_all *all)
{
	int	i;

	ft_putstr_fd("Good Bye!\n", 1);
	i = -1;
	free_map(all->game->map);
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
	if (all->game->got_cards == all->game->total_cards)
		activate_exit(&all);
	put_count_mov(all);
	put_count_cards(all);
	return (1);
}
