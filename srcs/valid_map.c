/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:08:17 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/18 22:09:05 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	is_closed(char **map)
{
	int	i;
	int	line;

	line = -1;
	while (map[++line])
	{
		i = -1;
		while (map[line][++i])
		{
			if ((line == 0 && map[line][i] != '1')
				|| (!map[line + 1] && map[line][i] != '1'))
				return (0);
			if ((i == 0 && map[line][i] != '1')
				|| (!map[line][i + 1] && map[line][i] != '1'))
				return (0);
		}
	}
	return (1);
}

static int	is_rectangular(char **map)
{
	int	line;
	int	len;

	len = ft_strlen(map[0]);
	line = 0;
	while (map[++line])
	{
		if ((int)ft_strlen(map[line]) != len)
			return (0);
	}
	return (1);
}

static int	has_good_elems(char **map)
{
	int	i;
	int	line;

	line = -1;
	while (map[++line])
	{
		i = -1;
		while (map[line][++i])
		{
			if (map[line][i] != 'E' && map[line][i] != 'C'
				&& map[line][i] != 'P' && map[line][i] != '0'
				&& map[line][i] != '1')
				return (0);
		}
	}
	return (1);
}

static int	has_elem(char **map, char c)
{
	int	i;
	int	line;

	line = -1;
	while (map[++line])
	{
		i = -1;
		while (map[line][++i])
		{
			if (map[line][i] == c)
				return (1);
		}
	}
	return (0);
}

int	ft_is_valid_map(char **map)
{
	if (!map)
		return (0);
	if (!is_closed(map) || !is_rectangular(map)
		|| !has_good_elems(map) || !has_elem(map, 'E')
		|| !has_elem(map, 'C') || !has_elem(map, 'P'))
	{
		free_map(map);
		ft_put_error_map();
	}
	return (1);
}
