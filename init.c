#include "fdf.h"

void	isometric(float *x,float *y)
{

	float	pre_x;
	float	pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = pre_x - pre_y;
	*y = (pre_x + pre_y) / 2;
}

t_coord	*ft_coord_init(void)
{
	t_coord *coord;

	coord = malloc(sizeof(t_coord));
	coord->pxl_x = 500;
	coord->pxl_y = 500;
	coord->space_x = 20;
	coord->space_y = 20;	
	return (coord);
}

t_data	*data_init(char *av1)
{
	t_data	*data;
	int		fd;

	fd = open(av1, O_RDONLY);
	data = malloc(sizeof(t_data));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 500, 500, "titre");
	data->nbr_lines = nb_lines(fd);
	close (fd);
	return (data);
}
