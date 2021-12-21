#include "../headers/so_long.h"
#include <stdio.h>

#define ESC 65307
/*int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	mlx_loop(mlx);
}*/

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_win(int keycode, t_vars *vars)
{
	(void) keycode;
	printf("Good Bye!\n");
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	(void) vars;
	if (keycode == ESC)
	{
		close_win(keycode, vars);
		exit(0);
	}
	return (1);
}

int main()
{
	t_data	img;
	t_vars	vars;
//	int		img_width;
//	int		img_height;
//	char	*relative_path = "./test.png";

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello Wolrd!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
//	img.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	int	x = 0;
	int	y = 0;
	while (y < 50)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x++;
		if (x == 50)
		{
			y++;
			x = 0;
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L<<17, close_win, (void *)0); //SEGFAULT
	mlx_loop(vars.mlx);
}

/*int	main()
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./test.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
}*/
