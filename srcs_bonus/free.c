/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:22:05 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/20 09:00:35 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	all_free(t_all *all)
{
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
	mlx_destroy_image(all->vars->mlx, all->imgs->ennemy.img);
	mlx_destroy_image(all->vars->mlx, all->imgs->ennemy2.img);
	mlx_destroy_image(all->vars->mlx, all->imgs->ennemy3.img);
	mlx_destroy_window(all->vars->mlx, all->vars->win);
	mlx_destroy_display(all->vars->mlx);
	free(all->vars->mlx);
}
