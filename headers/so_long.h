/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:16:09 by rleseur           #+#    #+#             */
/*   Updated: 2021/12/21 16:16:59 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../librairies/libft/libft.h"
# include "../librairies/minilibx/mlx.h"

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/* valid_map.c */
int		ft_is_valid_map(char **map);

/* map.c */
char	**ft_get_map(char *path);

/* errors.c */
int		ft_put_error_path(void);
int		ft_put_error_map(void);
int		ft_put_error_extension(void);
int		ft_put_error_nb_args(void);

#endif
