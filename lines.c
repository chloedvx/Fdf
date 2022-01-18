/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:18:17 by cdaveux           #+#    #+#             */
/*   Updated: 2022/01/18 16:19:40 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_bres_low(t_data *data, int x_0, int y_0, int x_1, int y_1)
{
	int	dx;
	int	dy;
	int	yi;
	int	p;

	dx = x_1 - x_0;
	dy = y_1 - y_0;
    yi = 1;
    if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
    p = 2*dy - dx;
	while (x_0 <= x_1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x_0, y_0,0x00FFFF);
		if (p > 0)
		{
			y_0 = y_0 + yi;
			p = p - 2*dx;
		}
		p = p + 2*dy;
		x_0++;
	}
}

void	draw_line_bres_hi(t_data *data, int x_0, int y_0, int x_1, int y_1)
{
	int	dx;
	int	dy;
	int	xi;
	int	p;

	dx = x_1 - x_0;
	dy = y_1 - y_0;
    xi = 1;
    if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
    p = 2*dx - dy;
	while (y_0 <= y_1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x_0, y_0,0x00FFFF);
		if (p > 0)
		{
			x_0 = x_0 + xi;
			p = p - 2*dy;
		}
		p = p + 2*dx;
		y_0++;
	}
}

void	drawline_bres(t_data *data, int x_0, int y_0, int x_1, int y_1)
{
	int dx;
	int dy;

	dx = ((x_1 - x_0) > 0) ? (x_1 - x_0) : -(x_1 - x_0);
	dy = ((y_1 - y_0) > 0) ? (y_1 - y_0) : -(y_1 - y_0);

	if (dy < dx)
	{
		if (x_0 > x_1)
			draw_line_bres_low(data, x_1, y_1, x_0, y_0);
		else
			draw_line_bres_low(data, x_0, y_0, x_1, y_1);
	}
	else
	{
		if (y_0 > y_1)
			draw_line_bres_hi(data, x_1, y_1, x_0, y_0);
		else
			draw_line_bres_hi(data, x_0, y_0, x_1, y_1);
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
			coord->x0 = j * 25;
			coord->y0 = i * 25;
			isometric(&coord->x0, &coord->y0);
		//	printf("post iso : x0 : %d, y0 : %d\n", coord->x0, coord->y0);
			coord->x1 = (j + 1) * 25;
			coord->y1 = i * 25;
			isometric(&coord->x1, &coord->y1);
		//	printf("post iso : x1 : %d, y1 : %d\n", coord->x1, coord->y1);
			drawline_bres(data, coord->x0 + 250, coord->y0 + 100, coord->x1 + 250, coord->y1 + 100);
			j++;
		}
		i++;
	}
	free(coord);
}

void	vertical_lines(t_data *data) // PBBBBB
{
	int	i;
	int	j;
	t_coord	*coord;

	j = 0;
	coord = malloc(sizeof(t_coord));
	if (!coord)
		exit(0);
	while (j < data->nbr_col)// vertic top > down
	{
		i = 0;
		while (i < data->nbr_lines - 1)
		{
			coord->x0 = j * 25;
			coord->y0 = i * 25;
			isometric(&coord->x0, &coord->y0);
	//		printf("post iso : x0 : %d, y0 : %d\n", coord->x0, coord->y0);
			coord->x1 = j * 25;
			coord->y1 = (i + 1) * 25;
			isometric(&coord->x1, &coord->y1);
	//		printf("post iso : x1 : %d, y1 : %d\n", coord->x1, coord->y1);
			drawline_bres(data, coord->x0 + 250, coord->y0 + 100, coord->x1 + 250, coord->y1 + 100);

			i++;
		}
		j++;
	}
	free(coord);
}
