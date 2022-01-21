/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:18:17 by cdaveux           #+#    #+#             */
/*   Updated: 2022/01/19 14:44:47 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_bres_low(t_img *img, int x_0, int y_0, int x_1, int y_1)
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
		my_mlx_pixel_put(img, x_0, y_0, img->rgb);
		if (p > 0)
		{
			y_0 = y_0 + yi;
			p = p - 2*dx;
		}
		p = p + 2*dy;
		x_0++;
	}
}

void	draw_line_bres_hi(t_img *img, int x_0, int y_0, int x_1, int y_1)
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
		my_mlx_pixel_put(img, x_0, y_0, img->rgb);
		if (p > 0)
		{
			x_0 = x_0 + xi;
			p = p - 2*dy;
		}
		p = p + 2*dx;
		y_0++;
	}
}

void	drawline_bres(t_img *img, int x_0, int y_0, int x_1, int y_1)
{
	int dx;
	int dy;

	dx = ((x_1 - x_0) > 0) ? (x_1 - x_0) : -(x_1 - x_0);
	dy = ((y_1 - y_0) > 0) ? (y_1 - y_0) : -(y_1 - y_0);

	if (dy < dx)
	{
		if (x_0 > x_1)
			draw_line_bres_low(img, x_1, y_1, x_0, y_0);
		else
			draw_line_bres_low(img, x_0, y_0, x_1, y_1);
	}
	else
	{
		if (y_0 > y_1)
			draw_line_bres_hi(img, x_1, y_1, x_0, y_0);
		else
			draw_line_bres_hi(img, x_0, y_0, x_1, y_1);
	}
}

void	horiz_lines(t_data *data, t_img *img)
{
	int	i;
	int	j;
	t_coord	*coord;

	i = 0;
	coord = malloc(sizeof(t_coord));
	if (!coord)
		exit(0);
	while (i < data->nbr_lines)
	{
		j = 0;
		while (j < data->nbr_col - 1)
		{
			coord->x0 = j * data->gap;
			coord->y0 = i * data->gap;
			isometric(&coord->x0, &coord->y0, data->line[i][j]);
			coord->x1 = (j + 1) * data->gap;
			coord->y1 = i * data->gap;
			isometric(&coord->x1, &coord->y1, data->line[i][j + 1]);
			drawline_bres(img, coord->x0 + data->start_x, coord->y0 + data->start_y, coord->x1 + data->start_x, coord->y1 + data->start_y);
			j++;
		}
		i++;
	}
	free(coord);
}

void	vertical_lines(t_data *data, t_img *img)
{
	int	i;
	int	j;
	t_coord	*coord;

	j = 0;
	coord = malloc(sizeof(t_coord));
	if (!coord)
		exit(0);
	while (j < data->nbr_col)
	{
		i = 0;
		while (i < data->nbr_lines - 1)
		{
			coord->x0 = j * data->gap;
			coord->y0 = i * data->gap;
			isometric(&coord->x0, &coord->y0, data->line[i][j]);
			coord->x1 = j * data->gap;
			coord->y1 = (i + 1) * data->gap;
			isometric(&coord->x1, &coord->y1, data->line[i + 1][j]);
			drawline_bres(img, coord->x0 + data->start_x, coord->y0 + data->start_y, coord->x1 + data->start_x, coord->y1 + data->start_y);
			i++;
		}
		j++;
	}
	free(coord);
}
