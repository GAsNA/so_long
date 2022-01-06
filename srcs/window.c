/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:53:10 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/05 17:27:08 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	get_window(t_vars *vars, int x, int y)
{
	vars->count = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, x, y, "So_long");
}

static t_data	get_image(char *path, t_vars *vars)
{
	t_data	img;

	img.img = mlx_xpm_file_to_image(vars->mlx, path, &img.img_width, &img.img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}

void	ft_open_window(int x, int y, char **map)
{
	t_vars	vars;
	t_imgs	imgs;

	(void) map;
	get_window(&vars, x, y);
	imgs.card = get_image(CARDPATH, &vars);
	imgs.exit_op = get_image(EXITOPPATH, &vars);
	imgs.exit_cl = get_image(EXITCLPATH, &vars);
	imgs.ground = get_image(GROUNDPATH, &vars);
	imgs.wall = get_image(WALLPATH, &vars);
	draw_map(&imgs, &vars, map);
	//mlx_put_image_to_window(vars.mlx, vars.win, imgs.wall.img, 0, 0);
	//mlx_put_image_to_window(vars.mlx, vars.win, imgs.ground.img, 32, 0);
	//mlx_put_image_to_window(vars.mlx, vars.win, imgs.card.img, 32, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_win, &vars);
	mlx_loop(vars.mlx);
}
