/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_is.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:04:46 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/12 18:04:47 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	check_collision(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'E' || map[y][x] == 'K')
		return (1);
	return (0);
}

int	check_collectible(t_game **game, int x, int y)
{
	if ((*game)->map[y][x] == 'C')
	{
		(*game)->map[y][x] = '0';
		return (1);
	}
	return (0);
}

int	check_exit(char **map, int x, int y)
{
	if (map[y][x] == 'E')
		return (1);
	return (0);
}

int	check_ennemy(char **map, int x, int y)
{
	if (map[y][x] == 'K')
		return (1);
	return (0);
}
