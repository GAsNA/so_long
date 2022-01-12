/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:05:23 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/12 18:06:01 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	go_up(t_all **all)
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
	if (check_collectible(&(*all)->game, (*all)->game->x_perso,
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

void	go_down(t_all **all)
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
	if (check_collectible(&(*all)->game, (*all)->game->x_perso,
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

void	go_left(t_all **all)
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
	if (check_collectible(&(*all)->game, (*all)->game->x_perso - 1,
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

void	go_right(t_all **all)
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
	if (check_collectible(&(*all)->game, (*all)->game->x_perso + 1,
			(*all)->game->y_perso))
		(*all)->game->got_cards++;
	(*all)->game->mov_count += 1;
	mlx_put_image_to_window((*all)->vars->mlx, (*all)->vars->win,
		(*all)->imgs->ground.img, (*all)->game->x_perso * SIZE,
		(*all)->game->y_perso * SIZE);
	(*all)->game->x_perso += 1;
	mlx_put_image_to_window((*all)->vars->mlx, (*all)->vars->win,
		(*all)->imgs->perso_r.img, (*all)->game->x_perso * SIZE,
		(*all)->game->y_perso * SIZE);
}
