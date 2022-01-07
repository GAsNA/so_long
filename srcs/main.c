/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:26:31 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/07 08:46:45 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	int		x;
	int		y;

	if (ac != 2)
		return (ft_put_error_nb_args());
	map = ft_get_map(av[1]);
	if (!ft_is_valid_map(map))
		return (0);
	x = ft_strlen(map[0]);
	y = 0;
	while (map[y])
		y++;
	ft_open_window(x * SIZE, y * SIZE, map);
	return (0);
}
