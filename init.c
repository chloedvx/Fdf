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

void	data_init2(t_data *data)
{
	data->size_x = 1044;
	data->size_y = 700;
	if (data->nbr_lines <= 10 || data->nbr_col <= 10)
		data->gap = 25;
	if (data->nbr_lines >= 20 || data->nbr_col >= 20)
		data->gap = 10;
	if (data->nbr_lines >= 100 || data->nbr_col >= 100)
		data->gap = 5;
	if (data->nbr_lines >= 200 || data->nbr_col >= 200)
		data->gap = 3;
	if (data->nbr_lines >= 400 || data->nbr_col >= 400)
		data->gap = 1;
	data->start_x = data->size_x / 2;
	data->start_y = 0;
}

t_data	*data_init(char *av1)
{
	t_data	*data;
	int		fd;
	int		i;
	char	*str;

	i = -1;
	fd = open(av1, O_RDONLY);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->nbr_lines = 0;
	while (++i == data->nbr_lines)
	{
		str = get_next_line(fd);
		if (str != NULL)
		{
			data->nbr_lines++;
			data->nbr_col = line_size(str);
		}
		free(str);
	}
	close (fd);
	data->line = ft_parse(av1, data);
	data_init2(data);
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
	img->mlx_ptr = data->mlx_ptr;
	img->img_ptr = mlx_new_image(data->mlx_ptr, img->x, img->y);
	if (!img->img_ptr)
		exit(EXIT_FAILURE);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		exit(EXIT_FAILURE);
	img->r = 0;
	img->g = 255;
	img->b = 0;
	img->rgb = create_trgb(img->r, img->g, img->b);
	return (img);
}
