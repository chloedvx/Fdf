/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:50:13 by cdaveux           #+#    #+#             */
/*   Updated: 2022/01/19 15:01:21 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(int *x,int *y, int z)
{

	int pre_x;
	int pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = (pre_x - pre_y) * cos(0.8);
	*y = (pre_x + pre_y) * sin (0.8) - z;
}

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
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
	data->size_x = 1044;
	data->size_y = 700;
	printf("col : %d, line : %d\n", data->nbr_col, data->nbr_lines);
	data->gap = 5;//25
	data->start_x = data->size_x / 2;
	data->start_y = data->size_y / 10;
	data->line = ft_parse(av1, data);
	return (data);
}

void	ft_free(int **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}

t_img	*img_init(t_data *data)
{
	t_img	*img;
	img = malloc(sizeof(t_img));
	if (!img)
		return (0);
	img->x = data->size_x;
	img->y = data->size_y;
	img->img_ptr = mlx_new_image(data->mlx_ptr, img->x, img->y);
	if (!img->img_ptr)
		exit(EXIT_FAILURE);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
	if (!img->addr)
		exit(EXIT_FAILURE);
	img->r = 0;
	img->g = 255;
	img->b = 0;
	img->rgb = create_trgb(img->r, img->g, img->b);
	return (img);
}
