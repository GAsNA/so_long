#include "../headers/so_long.h"

#include <stdio.h>

int main(int ac, char **av)
{
	char	**map;

	(void) ac;
	map = ft_get_map(av[1]);
	printf("%i\n", ft_is_valid_map(map));
	return (0);
}
