#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


/*t_data *ft_struct_init(void)
{

	&img.bits_per_pixel = ;
	&img.line_length = ;
	&img.endian = ;
	
}*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_key_hook(int key, t_data data)
{
	if (key == 53)
	{
		mlx_destroy_image(&data.mlx, &data.img);
		mlx_destroy_window(&data.mlx, &data.mlx_win);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_data	img;

	img.mlx = mlx_init();
	//ft_struct_init();
	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	mlx_key_hook(img.mlx_win, ft_key_hook, &img);
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	printf("line length: %d\n", img.line_length);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}

