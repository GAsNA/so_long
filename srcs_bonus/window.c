/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:53:10 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/17 17:40:29 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	get_window(t_vars *vars, int x, int y)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, x, y, "So_long");
}

static void	get_all_imgs(t_imgs *imgs, t_vars *vars)
{
	imgs->card = get_image(CARDPATH, &vars);
	imgs->exit_op = get_image(EXITOPPATH, &vars);
	imgs->exit_cl = get_image(EXITCLPATH, &vars);
	imgs->ground = get_image(GROUNDPATH, &vars);
	imgs->wall = get_image(WALLPATH, &vars);
	imgs->perso_b = get_image(PERSOBPATH, &vars);
	imgs->perso_f = get_image(PERSOFPATH, &vars);
	imgs->perso_l = get_image(PERSOLPATH, &vars);
	imgs->perso_r = get_image(PERSORPATH, &vars);
	imgs->ennemy = get_image(ENNEMYPATH, &vars);
	imgs->ennemy2 = get_image(ENNEMY2PATH, &vars);
	imgs->ennemy3 = get_image(ENNEMY3PATH, &vars);
}

static void	get_game(t_game *game)
{
	game->mov_count = 0;
	game->got_cards = 0;
	game->activated_exit = 0;
	game->perso_exited = 0;
	game->ennemy_pos = 1;
	game->loop = 0;
	get_pos_perso(&game);
	get_total_cards(&game);
}

static void	get_all(t_all *all, t_vars *vars, t_imgs *imgs, t_game *game)
{
	all->vars = vars;
	all->imgs = imgs;
	all->game = game;
}

void	ft_open_window(t_game game)
{
	t_vars	vars;
	t_imgs	imgs;
	t_all	all;

	get_window(&vars, game.x_win * SIZE, (game.y_win * SIZE) + SIZE_PARAMS);
	get_all_imgs(&imgs, &vars);
	get_game(&game);
	get_all(&all, &vars, &imgs, &game);
	put_count_mov(&all);
	put_count_cards(&all);
	draw_map(&all);
	mlx_hook(vars.win, KEYPRESS, KEYPRESSMASK, key_hook, &all);
	mlx_hook(vars.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_win, &all);
	mlx_loop_hook(vars.mlx, ennemy_animation, &all);
	mlx_loop(vars.mlx);
}
