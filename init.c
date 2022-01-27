/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:50:13 by cdaveux           #+#    #+#             */
/*   Updated: 2022/01/27 10:01:10 by cdaveux          ###   ########.fr       */
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
	data->start_y = 50;
	data->r = 255;
	data->g = 255;
	data->b = 255;
	data->rgb = create_trgb(data->r, data->g, data->b);
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
