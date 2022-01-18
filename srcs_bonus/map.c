/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:07:47 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/18 09:20:07 by rleseur          ###   ########.fr       */
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

static void check_error(char *path)
{
	if (!check_extension(path))
		ft_put_error_extension();
	if (open(path, O_DIRECTORY) >= 0)
		ft_put_error_path();
}

static void check_empty_map(char *map)
{
    if (!map[0])
    {
        free(map);
        ft_put_error_map();
    }
}

char	**ft_get_map(char *path)
{
	char	*map;
	int		i;
	int		fd;
	char	bf;
	char	**d_map;

	check_error(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_put_error_path();
	map = malloc(length_map(path) * sizeof(char));
	if (!map)
		exit (0);
	i = -1;
	while (read(fd, &bf, 1))
		map[++i] = bf;
	if (i > 0)
		map[i++] = '\0';
	else
		map[0] = '\0';
	close(fd);
	check_empty_map(map);
	d_map = ft_split(map, '\n');
	free(map);
	return (d_map);
}
