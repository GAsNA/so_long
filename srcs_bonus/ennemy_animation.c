/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:03:41 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/12 18:03:45 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

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
				mlx_put_image_to_window(vars->mlx, vars->win,
					ennemy.img, j * SIZE, i * SIZE);
		}
	}
}

int	ennemy_animation(t_all *all)
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
