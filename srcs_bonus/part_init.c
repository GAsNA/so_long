/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:04:37 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/12 18:04:38 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

t_data	get_image(char *path, t_vars **vars)
{
	t_data	img;

	img.img = mlx_xpm_file_to_image((*vars)->mlx, path,
			&img.img_width, &img.img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}

void	get_pos_perso(t_game **game)
{
	int	i;
	int	j;
	int	find;

	find = 0;
	i = -1;
	while ((*game)->map[++i])
	{
		j = -1;
		while ((*game)->map[i][++j])
		{
			if ((*game)->map[i][j] == 'P')
			{
				if (!find)
				{
					(*game)->x_perso = j;
					(*game)->y_perso = i;
					find = 1;
				}
				else
					(*game)->map[i][j] = '0';
			}
		}
	}
}

void	get_total_cards(t_game **game)
{
	int	i;
	int	j;

	(*game)->total_cards = 0;
	i = -1;
	while ((*game)->map[++i])
	{
		j = -1;
		while ((*game)->map[i][++j])
		{
			if ((*game)->map[i][j] == 'C')
				(*game)->total_cards++;
		}
	}
}
