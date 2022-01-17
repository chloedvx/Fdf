/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:50:13 by cdaveux           #+#    #+#             */
/*   Updated: 2022/01/17 16:54:02 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x,float *y)
{

	float pre_x;
	float pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = (pre_x - pre_y);
	*y = (pre_x + pre_y) / 2;
	//*x = (pre_x - z)/ sqrt(2);
	//*y = (pre_x + 2 * pre_y + z) / sqrt(6);
}

t_colors *colors_init(void)
{
	t_colors	*colors;

	colors = malloc(sizeof(t_colors));
	if (!colors)
		return (0);
	colors->R = 255;
	colors->G = 255;
	colors->B = 255;
	return (colors);
}

t_data	*data_init(char *av1)
{
	t_data	*data;
	int		fd;
	char	*str;

	fd = open(av1, O_RDONLY);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->nbr_lines = 0;
	while ((str = get_next_line(fd)) != NULL)
	{
		data->nbr_lines++;
		data->nbr_col = line_size(str);
		free(str);
	}
	close (fd);
	data->size_x = data->nbr_col * 50;
	data->size_y = data->nbr_lines * 50;
	data->gap_x = 25;
	data->gap_y = 25;
	data->line = ft_parse(av1, data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->size_x, data->size_y, "titre");
	return (data);
}
