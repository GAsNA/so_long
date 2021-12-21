/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:07:47 by rleseur           #+#    #+#             */
/*   Updated: 2021/12/21 16:08:02 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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

	if (!check_extension(path))
	{
		ft_put_error_extension();
		return (0);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_put_error_path();
		return (0);
	}
	map = malloc(length_map(path) * sizeof(char));
	if (!map)
		return (0);
	i = -1;
	while (read(fd, &bf, 1))
		map[++i] = bf;
	map[i++] = '\0';
	close(fd);
	return (ft_split(map, '\n'));
}
