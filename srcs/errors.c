#include "../headers/so_long.h"

static void	ft_put_error()
{
	ft_putstr_fd("Error\n", 1);
}

int	ft_put_error_path()
{
	ft_put_error();
	ft_putstr_fd("Map does not found\n", 1);
	return (0);
}

int	ft_put_error_map()
{
	ft_put_error();
	ft_putstr_fd("Map is not correct\n", 1);
	return (0);
}
