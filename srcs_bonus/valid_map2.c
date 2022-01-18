/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:15:01 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/18 22:50:18 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_good_size_map(t_all all)
{
	int	x;
	int	y;

	mlx_get_screen_size(all.vars->mlx, &x, &y);
	if (x < all.game->x_win * SIZE || y < all.game->y_win * SIZE)
	{
		free_map(all.game->map);
		mlx_destroy_display(all.vars->mlx);
		free(all.vars->mlx);
		ft_put_error_map();
	}
}
