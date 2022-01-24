#include "fdf.h"

void	isometric(int *x, int *y, int z)
{
	int	pre_x;
	int	pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = (pre_x - pre_y) * cos(0.8);
	*y = (pre_x + pre_y) * sin (0.8) - z;
}

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_append(t_coord *coord, t_data *data)
{
	coord->x0 += data->start_x;
	coord->y0 += data->start_y;
	coord->x1 += data->start_x;
	coord->y1 += data->start_y;
}

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
