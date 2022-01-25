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

void	draw_line_bres_low(t_data *data, t_coord *coord)
{
	int	dx;
	int	dy;
	int	yi;
	int	p;

	dx = coord->x1 - coord->x0;
	dy = coord->y1 - coord->y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	p = 2 * dy - dx;
	while (coord->x0 <= coord->x1)
	{
		my_mlx_pixel_put(data, coord->x0, coord->y0, data->rgb);
		if (p > 0)
		{
			coord->y0 += yi;
			p = p - 2 * dx;
		}
		p = p + 2 * dy;
		coord->x0++;
	}
}

void	draw_line_bres_hi(t_data *data, t_coord *coord)
{
	int	dx;
	int	dy;
	int	xi;
	int	p;

	dx = coord->x1 - coord->x0;
	dy = coord->y1 - coord->y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	p = 2 * dx - dy;
	while (coord->y0 <= coord->y1)
	{
		my_mlx_pixel_put(data, coord->x0, coord->y0, data->rgb);
		if (p > 0)
		{
			coord->x0 += xi;
			p = p - 2 * dy;
		}
		p = p + 2 * dx;
		coord->y0++;
	}
}

void	draw(t_data *data, t_coord *coord)
{
	int	dx;
	int	dy;

	dx = ft_diff(coord->x0, coord->x1);
	dy = ft_diff(coord->y0, coord->y1);
	if (dy < dx)
	{
		if (coord->x0 > coord->x1)
		{
			ft_swap(coord);
			draw_line_bres_low(data, coord);
		}
		else
			draw_line_bres_low(data, coord);
	}
	else
	{
		if (coord->y0 > coord->y1)
		{
			ft_swap(coord);
			draw_line_bres_hi(data, coord);
		}
		else
			draw_line_bres_hi(data, coord);
	}
}

void	horiz_lines(t_data *data)
{
	int		i;
	int		j;
	t_coord	*coord;

	i = 0;
	coord = malloc(sizeof(t_coord));
	if (!coord)
		exit(0);
	while (i < data->nbr_lines)
	{
		j = -1;
		while (++j < data->nbr_col - 1)
		{
			coord->x0 = j * data->gap;
			coord->y0 = i * data->gap;
			isometric(&coord->x0, &coord->y0, data->line[i][j]);
			coord->x1 = (j + 1) * data->gap;
			coord->y1 = i * data->gap;
			isometric(&coord->x1, &coord->y1, data->line[i][j + 1]);
			ft_append(coord, data);
			draw(data, coord);
		}
		i++;
	}
	free(coord);
}

void	vertical_lines(t_data *data)
{
	int		i;
	int		j;
	t_coord	*coord;

	j = 0;
	coord = malloc(sizeof(t_coord));
	if (!coord)
		exit(0);
	while (j < data->nbr_col)
	{
		i = -1;
		while (++i < data->nbr_lines - 1)
		{
			coord->x0 = j * data->gap;
			coord->y0 = i * data->gap;
			isometric(&coord->x0, &coord->y0, data->line[i][j]);
			coord->x1 = j * data->gap;
			coord->y1 = (i + 1) * data->gap;
			isometric(&coord->x1, &coord->y1, data->line[i + 1][j]);
			ft_append(coord, data);
			draw(data, coord);
		}
		j++;
	}
	free(coord);
}
