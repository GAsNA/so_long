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

static t_data	get_image(int x, int y, t_vars *vars)
{
	t_data	img;

	img.img = mlx_new_image(vars->mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}

void	ft_open_window(int x, int y, char **map)
{
	t_vars	vars;
	t_data	img;
//	t_imgs	imgs;

	(void) map;
	get_window(&vars, x, y);
	img = get_image(x, y, &vars);
//	imgs.wall.img_width = 0;
//	imgs.wall.img_height = 0;
//	imgs.wall.img = mlx_xpm_file_to_image(vars.mlx, WALLPATH, &imgs.wall.img_width, &imgs.wall.img_height);
//	printf("wall_width: %i\nwall_height: %i\n", imgs.wall.img_width, imgs.wall.img_height);
//	imgs.wall.addr = mlx_get_data_addr(imgs.wall.img, &imgs.wall.bits_per_pixel, &imgs.wall.line_length,
 //           &imgs.wall.endian);
//	printf("wall_width: %i\nwall_height: %i\n", imgs.wall.img_width, imgs.wall.img_height);
	draw_map(&img, map);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_win, &vars);
	mlx_loop(vars.mlx);
}
