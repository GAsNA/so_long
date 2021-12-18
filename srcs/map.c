#include "../headers/so_long.h"

static int	length_map(char *path)
{
	int	size;
	int	fd;
	char	bf;

	fd = open(path, O_RDONLY);
	size = 0;
	while (read(fd, &bf, 1))
		size++;
	close(fd);
	return (size + 1);
}

char	**ft_get_map(char *path)
{
	char	*map;
	int	i;
	int	fd;
	char	bf;

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
