#include "../headers/so_long.h"

/*static int	has_one_spwan(char **map)
{
	int	i;
	int	line;
	int	spawn;

	spawn = 0;
	line = -1;
	while (map[++line])
	{
		i = -1;
		while (map[line][++i])
		{
			if (map[line][i] == 'P' && !spawn)
				spawn++;
			else if (map[line][i] == 'P' && spawn)
				return (0);
		}
	}
	if (!spawn)
		return (0);
	return (1);
}*/

static int	is_closed(char **map)
{
	int	i;
	int	line;
	
	line = -1;
	while (map[++line])
	{
		i = -1;
		while(map[line][++i])
		{
			if ((line == 0 && map[line][i] != '1')
				|| (!map[line + 1] && map[line][i] != '1'))
				return (0);
			if ((i == 0 && map[line][i] != '1')
				|| (!map[line][i + 1] && map[line][i] != '1'))
				return (0);
		}
	}
	return (1);
}

static int	is_rectangular(char **map)
{
	int	line;
	int	len;

	len = ft_strlen(map[0]);
	line = 0;
	while (map[++line])
	{
		if ((int)ft_strlen(map[line]) != len)
			return (0);
	}
	return (1);
}

static int	has_good_elems(char **map)
{
	int	i;
	int	line;

	line = -1;
	while (map[++line])
	{
		i = -1;
		while (map[line][++i])
		{
			if (map[line][i] != 'E' && map[line][i] != 'C'
				&& map[line][i] != 'P' && map[line][i] != '0'
				&& map[line][i] != '1')
				return (0);
		}
	}
	return (1);
}

/*static int	has_exit(char **map)
{
	int	i;
	int	line;

	line = -1;
	while (map[++line])
	{
		i = -1;
		while (map[line][++i])
		{
			if (map[line][i] == 'E')
				return (1);
		}
	}
	return (0);
}

static int	has_collectible(char **map)
{
	int	i;
	int	line;

	line = -1;
	while (map[++line])
	{
		i = -1;
		while (map[line][++i])
		{
			if (map[line][i] == 'C')
				return (1);
		}
	}
	return (0);
}

static int	has_spawn(char **map)
{
	int	i;
	int	line;

	line = -1;
	while (map[++line])
	{
		i = -1;
		while (map[line][++i])
		{
			if (map[line][i] == 'P')
				return (1);
		}
	}
	return (0);
}*/

static int	has_elem(char **map, char c)
{
	int	i;
	int	line;

	line = -1;
	while (map[++line])
	{
		i = -1;
		while (map[line][++i])
		{
			if (map[line][i] == c)
				return (1);
		}
	}
	return (0);
}

int	ft_is_valid_map(char **map)
{
	if (!map)
		return (0);
	if (!is_closed(map) || !is_rectangular(map)
		|| !has_good_elems(map) || !has_elem(map, 'E')
		|| !has_elem(map, 'C') || !has_elem(map, 'P'))
		return(ft_put_error_map());
	return (1);

}
