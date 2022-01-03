/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:53:10 by rleseur           #+#    #+#             */
/*   Updated: 2021/12/21 17:51:34 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static t_vars	get_window(int x, int y)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, x, y, "So_long");
	return (vars);
}

static t_data	get_image(int x, int y, t_vars vars)
{
	t_data	img;

	img.img = mlx_new_image(vars.mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}

void	ft_open_window(int x, int y, char **map)
{
	t_vars	vars;
	t_data	img;

	vars = get_window(x, y);
	img = get_image(x, y, vars);
	draw_map(&img, map);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK,
		close_win, (void *)0); //SEGFAULT
	mlx_loop(vars.mlx);
}
