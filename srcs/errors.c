/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:06:07 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/12 18:26:01 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	ft_put_error(void)
{
	ft_putstr_fd("#####################\n", 1);
	ft_putstr_fd("# Error\n", 1);
}

char	**ft_put_error_path(void)
{
	ft_put_error();
	ft_putstr_fd("# Map does not found\n", 1);
	return (0);
}

int	ft_put_error_map(void)
{
	ft_put_error();
	ft_putstr_fd("# Map is not correct\n", 1);
	return (0);
}

char	**ft_put_error_extension(void)
{
	ft_put_error();
	ft_putstr_fd("# Map does not have the correct extension\n", 1);
	return (0);
}

int	ft_put_error_nb_args(void)
{
	ft_put_error();
	ft_putstr_fd("# The number of arguments is invalid\n", 1);
	ft_putstr_fd("# Use: ./so_long [path of the map]\n", 1);
	return (0);
}
