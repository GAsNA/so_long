/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:04:07 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/13 23:26:20 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	clear_string(t_all **all, char *str, int x, int y)
{
	mlx_string_put((*all)->vars->mlx, (*all)->vars->win, x, y, 0x00000000, str);
	free(str);
}

void	put_count_mov(t_all *all)
{
	int	y;
	char	*nb;

	y = (all->game->y_win * SIZE) + 20;
	clear_string(&all, ft_itoa(all->game->mov_count - 1), 70, y);
	mlx_string_put(all->vars->mlx, all->vars->win, 25, y, 0x00FFFFFF,
		"MOVES: ");
	nb = ft_itoa(all->game->mov_count);
	mlx_string_put(all->vars->mlx, all->vars->win, 70, y, 0x00FFFFFF, nb);
	free(nb);
}

void	put_count_cards(t_all *all)
{
	int	y;
	char	*nb;

	y = (all->game->y_win * SIZE) + 20;
	clear_string(&all, ft_itoa(all->game->got_cards - 1), 145, y);
	mlx_string_put(all->vars->mlx, all->vars->win, 100, y, 0x00FFFFFF,
		"CARDS: ");
	nb = ft_itoa(all->game->got_cards);
	mlx_string_put(all->vars->mlx, all->vars->win, 145, y, 0x00FFFFFF, nb);
	free(nb);
	mlx_string_put(all->vars->mlx, all->vars->win, 165, y, 0x00FFFFFF, "\\");
	nb = ft_itoa(all->game->total_cards);
	mlx_string_put(all->vars->mlx, all->vars->win, 185, y, 0x00FFFFFF, nb);
	free(nb);
}
