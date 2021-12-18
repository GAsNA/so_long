#include "../headers/so_long.h"

int	ft_put_error_path()
{
	ft_putstr_fd("Map does not found\n", 1);
	return (0);
}

int	ft_put_error_map()
{
	ft_putstr_fd("Map is not correct\n", 1);
	return (0);
}
