/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:53:10 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/07 14:30:26 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	get_window(t_vars *vars, int x, int y)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, x, y, "So_long");
}

static t_data	get_image(char *path, t_vars **vars)
{
	t_data	img;

	img.img = mlx_xpm_file_to_image((*vars)->mlx, path,
			&img.img_width, &img.img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
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

static void	get_pos_perso(t_game **game)
{
	int	i;
	int	j;
	int	find;

	find = 0;
        i = -1;
        while ((*game)->map[++i])
        {
                j = -1;
                while ((*game)->map[i][++j])
                {
                        if ((*game)->map[i][j] == 'P')
                        {
				if (!find)
				{
                                	(*game)->x_perso = j;
                                	(*game)->y_perso = i;
                                	find = 1;
				}
				else
					(*game)->map[i][j] = '0';
                        }
                }
        }
}

static void	get_total_cards(t_game **game)
{
	int	i;
	int	j;

	(*game)->total_cards = 0;
	i = -1;
	while ((*game)->map[++i])
	{
		j = -1;
		while ((*game)->map[i][++j])
		{
			if ((*game)->map[i][j] == 'C')
				(*game)->total_cards++;
		}
	}
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

static void	get_ennemy_pos(t_data ennemy, char **map, t_vars *vars)
{
	int	i;
	int	j;
	
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'K')
				mlx_put_image_to_window(vars->mlx, vars->win, ennemy.img, j * SIZE, i * SIZE);
		}
	}
}

static int	ennemy_animation(t_all *all)
{
	if (all->game->loop < 10000)
	{
		all->game->loop += 1;
		return (0);
	}
	all->game->loop = 0;
	if (all->game->ennemy_pos == 1)
	{
		get_ennemy_pos(all->imgs->ennemy2, all->game->map, all->vars);
		all->game->ennemy_pos = 2;
	}
	else if (all->game->ennemy_pos == 2)
	{
		get_ennemy_pos(all->imgs->ennemy3, all->game->map, all->vars);
		all->game->ennemy_pos = 3;
	}
	else if (all->game->ennemy_pos == 3)
	{
		get_ennemy_pos(all->imgs->ennemy, all->game->map, all->vars);
		all->game->ennemy_pos = 1;
	}
	return (0);
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
	//mlx_key_hook(vars.win, key_hook, &all);
	mlx_hook(vars.win, KEYPRESS, KEYPRESSMASK, key_hook, &all);
	mlx_hook(vars.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_win, &all);
	mlx_loop_hook(vars.mlx, ennemy_animation, &all);
	mlx_loop(vars.mlx);
}
