/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:16:09 by rleseur           #+#    #+#             */
/*   Updated: 2021/12/21 17:51:02 by rleseur          ###   ########.fr       */
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

/* Keycode */
# define ESC 65307

/* X11 events */
# define DESTROYNOTIFY 17

/* X11 masks */
# define STRUCTURENOTIFYMASK (1L<<17)

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

/* window.c */
void	ft_open_window(int x, int y, char **map);

/* draw_map.c */
void	draw_map(t_data *img, char **map);

/* actions_win.c */
int		close_win(int keycode, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);

#endif
