#include "fdf.h"

int	deal_key(int key, t_data *data) // fonctionne 
{	
	if (key == 53)
	{
		mlx_destroy_window (data->mlx_ptr, data->win_ptr);
		return (-1);
	}
	ft_putnbr(key);
	return (0);
}

void drawline(t_data *data, int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
 
	dx = x1 - x0;
	dy = y1 - y0;
	x = x0;
	y = y0;
 
	p =	2 * dy - dx;
	while (x < x1)
	{
	if (p >= 0)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0255255000);
		y = y + 1;
		p = p + 2 * dy - 2 * dx;
	}
	else
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0255255000);
		p = p + 2 * dy;
	}
	x = x + 1;
	}
}

void	horiz_lines(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nbr_lines)// horiz (lft>rght)
	{
		j = 0;
		while (j < 15) // arbitrary 15
		{
			
			drawline(data, 25 * j, 25 * i, 25 * j + 50, 25 * i);
			j++;
		}
		i++;
	}
}

void	vertic_lines(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)//vertical line (top>down)
		{
			drawline(data, 25 * j, 25 * i, 25 * j, 25 * i + 50);
			i++;
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
//	t_coord	*coord;
	int		**line;

	(void)ac;
	line = ft_parse(av[1]);
//	ft_coord_init(coord);
	data = data_init(av[1]);
	mlx_key_hook(data->win_ptr, deal_key, data);
	horiz_lines(data);
//	vertic_lines(data);
	mlx_loop(data->mlx_ptr);
	//free line
	free(&data);
//	free(coord);
	return (0);
}
