/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:23:47 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/07 14:34:41 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"
/*
static void	my_mlx_pixel_put(t_data ***data, int x, int y, int color)
{
	char	*dst;

	dst = (*(*data))->addr
		+ (y * (*(*data))->line_length + x * ((*(*data))->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	draw_square(t_data **data, int j, int i, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 32)
	{
		my_mlx_pixel_put(&data, j + x, i + y, color);
		x++;
		if (x == 32)
		{
			y++;
			x = 0;
		}
	}
}

void	draw_map(t_data *img, char **map)
{
	int	i;
	int	j;
	int	color;

	color = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				color = 0x00000000;
			else if (map[i][j] == '0')
				color = 0x00FFFFFF;
			else if (map[i][j] == 'C')
				color = 0x00FFD700;
			else if (map[i][j] == 'E')
				color = 0x00C0C0C0;
			else if (map[i][j] == 'P')
				color = 0x00FF0000;
			draw_square(&img, j * 32, i * 32, color);
		}
	}
}*/

void	draw_map(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (all->game->map[++i])
	{
		j = -1;
		while (all->game->map[i][++j])
		{
			if (all->game->map[i][j] == '1')
				mlx_put_image_to_window(all->vars->mlx, all->vars->win,
					all->imgs->wall.img, j * SIZE, i * SIZE);
			else if (all->game->map[i][j] == '0')
				mlx_put_image_to_window(all->vars->mlx, all->vars->win,
					all->imgs->ground.img, j * SIZE, i * SIZE);
			else if (all->game->map[i][j] == 'C')
				mlx_put_image_to_window(all->vars->mlx, all->vars->win,
					all->imgs->card.img, j * SIZE, i * SIZE);
			else if (all->game->map[i][j] == 'E')
				mlx_put_image_to_window(all->vars->mlx, all->vars->win,
					all->imgs->exit_cl.img, j * SIZE, i * SIZE);
			else if (all->game->map[i][j] == 'P')
				mlx_put_image_to_window(all->vars->mlx, all->vars->win,
					all->imgs->perso_f.img, j * SIZE, i * SIZE);
		}
	}
}
