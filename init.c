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
	*y = (pre_x + pre_y) * sin (0.8) - z;/// 2;
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
	data->size_x = data->nbr_col * 40;//50
	data->size_y = data->nbr_lines * 50;
	printf("col : %d, line : %d\n", data->nbr_col, data->nbr_lines);
	data->gap_x = 25;//25
	data->gap_y = 25;
	data->start_x = data->size_x / 2;
	data->start_y = data->size_y / 10;
	data->line = ft_parse(av1, data);
	return (data);
}

t_img	img_init(t_data *data)
{
	t_img	img;
		
	img.img_ptr = mlx_new_image(data->mlx_ptr, data->size_x, data->size_y);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.r = 255;
	img.g = 255;
	img.b = 255;
	img.rgb = create_trgb(img.r, img.g, img.b);
	return (img);
}
