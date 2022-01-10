/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:16:09 by rleseur           #+#    #+#             */
/*   Updated: 2022/01/07 14:33:17 by rleseur          ###   ########.fr       */
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

# include <stdio.h>

# define SIZE 32

/* Keycode */
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

/* X11 events */
# define KEYPRESS 2
# ifdef __APPLE__
#  define DESTROYNOTIFY 17
# elif __linux__
#  define DESTROYNOTIFY 33
# endif

/* X11 masks */
# define STRUCTURENOTIFYMASK 1L<<17
# define KEYPRESSMASK 1L<<0

/* Images paths */
# define CARDPATH "./assets/img/Card/card.xpm"
# define EXITOPPATH "./assets/img/Exit/exit_op.xpm"
# define EXITCLPATH "./assets/img/Exit/exit_cl.xpm"
# define GROUNDPATH "./assets/img/Ground/ground.xpm"
# define WALLPATH "./assets/img/Wall/wall.xpm"
# define PERSOBPATH "./assets/img/Perso/perso_back.xpm"
# define PERSOFPATH "./assets/img/Perso/perso_front.xpm"
# define PERSOLPATH "./assets/img/Perso/perso_left.xpm"
# define PERSORPATH "./assets/img/Perso/perso_right.xpm"

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
	int		img_width;
	int		img_height;
}	t_data;

typedef struct s_imgs
{
	t_data	card;
	t_data	exit_op;
	t_data	exit_cl;
	t_data	ground;
	t_data	wall;
	t_data	perso_b;
	t_data	perso_f;
	t_data	perso_l;
	t_data	perso_r;
}	t_imgs;

typedef struct s_game
{
	char	**map;
	int		x_win;
	int		y_win;
	int		mov_count;
	int		x_perso;
	int		y_perso;
	int		got_cards;
	int		total_cards;
	int		activated_exit;
	int		perso_exited;
}	t_game;

typedef struct s_all
{
	t_vars	*vars;
	t_imgs	*imgs;
	t_game	*game;
}	t_all;

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
void	ft_open_window(t_game game);

/* draw_map.c */
void	draw_map(t_all *all);

/* actions_win.c */
int		close_win(t_all *all);
int		key_hook(int keycode, t_all *all);

/* check_if_is.c */
int	check_collision(char **map, int x, int y);
int	check_collectible(t_game **game, int x, int y);
int	check_exit(char **map, int x, int y);

/* moving.c */
void	go_up(t_all **all);
void	go_down(t_all **all);
void	go_left(t_all **all);
void	go_right(t_all **all);

#endif
