/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:07:47 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/12 18:27:36 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static int	length_map(char *path)
{
	int		size;
	int		fd;
	char	bf;

	fd = open(path, O_RDONLY);
	size = 0;
	while (read(fd, &bf, 1))
		size++;
	close(fd);
	return (size + 1);
}

static int	check_extension(char *path)
{
	int	i;

	i = ft_strlen(path) - 4;
	if (ft_strncmp(&path[i], ".ber", 4) == 0)
		return (1);
	return (0);
}

char	**ft_get_map(char *path)
{
	char	*map;
	int		i;
	int		fd;
	char	bf;
	char	**d_map;

	if (!check_extension(path))
		return (ft_put_error_extension());
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_put_error_path());
	map = malloc(length_map(path) * sizeof(char));
	if (!map)
		return (0);
	i = -1;
	while (read(fd, &bf, 1))
		map[++i] = bf;
	map[i++] = '\0';
	close(fd);
	d_map = ft_split(map, '\n');
	free(map);
	return (d_map);
}
