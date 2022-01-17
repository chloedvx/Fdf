/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:49:43 by cdaveux           #+#    #+#             */
/*   Updated: 2022/01/17 16:30:59 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_data *data) // fonctionne 
{	
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
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

void drawline_vertic(t_data *data, int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;

	dx = x1 - x0;
	dy = y1 - y0;
	x = x0;
	y = y0;
	p =	2 * dx - dy;
	while (y < y1)
	{
	if (p >= 0)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0255255000);
		x = x + 1;
		p = p + 2 * dx- 2 * dy;
	}
	else
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0255255000);
		p = p + 2 * dx;
	}
	y = y + 1;
	}
}

void	horiz_lines(t_data *data)
{
	int	i;
	int	j;
	t_coord	*coord;

	i = 0;
	coord = malloc(sizeof(t_coord));
	if (!coord)
		exit(0);
	while (i < data->nbr_lines)// horiz (lft>rght)
	{
		j = 0;
		while (j < data->nbr_col - 1)
		{
			coord->x0 = j * data->gap_x + 100;
			coord->y0 = i * data->gap_y + 100;
	//		isometric(&coord->x0, &coord->y0);	
			coord->x1 = coord->x0 + data->gap_x;
			coord->y1 = coord->y0;
	//		isometric(&coord->x1, &coord->y1);
			drawline(data, coord->x0, coord->y0, coord->x1, coord->y1);
			j++;
		}
		i++;
	}
	free(coord);
}

void	vertical_lines(t_data *data)
{
	int	i;
	int	j;
	t_coord	*coord;

	i = 0;
	coord = malloc(sizeof(t_coord));
	if (!coord)
		exit(0);
	while (j < data->nbr_col)// vertic top > down
	{
		i = 0;
		while (i < data->nbr_lines - 1)
		{
			coord->x0 = j * data->gap_x + 100;
			coord->y0 = i * data->gap_y + 100;
	//		isometric(&coord->x0, &coord->y0);
			coord->x1 = coord->x0;
			coord->y1 = coord->y0 + data->gap_x;
	//		isometric(&coord->x1, &coord->y1);
			drawline_vertic(data, coord->x0, coord->y0, coord->x1, coord->y1);
			i++;
		}
		j++;
	}
	free(coord);
}

int	main(int ac, char **av)
{
	t_data		*data;
	t_colors	*colors;
	//int			**line;

	(void)ac;
	data = data_init(av[1]);
	//line = ft_parse(av[1], data);
	colors = colors_init();
	mlx_key_hook(data->win_ptr, deal_key, data);
	vertical_lines(data);
	horiz_lines(data); 
	mlx_loop(data->mlx_ptr);
	//free line
	free(data);
	free(colors);
	return (0);
}
