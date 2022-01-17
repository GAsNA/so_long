/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:26:31 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/17 17:05:37 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_put_error_nb_args();
	game.map = ft_get_map(av[1]);
	ft_is_valid_map(game.map);
	game.x_win = ft_strlen(game.map[0]);
	game.y_win = 0;
	while (game.map[game.y_win])
		game.y_win++;
	ft_open_window(game);
	return (0);
}
