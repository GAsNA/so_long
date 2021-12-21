#ifndef SO_LONG_H
# define SO_LONG_H

# include "../librairies/libft/libft.h"
# include "../librairies/minilibx/mlx.h"

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/* valid_map.c */
int	ft_is_valid_map(char **map);

/* map.c */
char	**ft_get_map(char *path);

/* errors.c */
int	ft_put_error_path();
int	ft_put_error_map();
int	ft_put_error_extension();
int	ft_put_error_nb_args();

#endif
