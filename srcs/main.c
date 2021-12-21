/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:26:31 by rleseur           #+#    #+#             */
/*   Updated: 2021/12/21 14:29:35 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

#include <stdio.h>

int	main(int ac, char **av)
{
	char	**map;

	if (ac != 2)
		return(ft_put_error_nb_args());
	map = ft_get_map(av[1]);
	printf("%i\n", ft_is_valid_map(map));
	return (0);
}
