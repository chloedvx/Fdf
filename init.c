/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:50:13 by cdaveux           #+#    #+#             */
/*   Updated: 2022/02/08 14:21:14 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	data_init2(t_data *data)
{
	data->size_x = 1044;
	data->size_y = 700;
	if (data->nbr_lines >= 400 || data->nbr_col >= 400)
	{
		data->size_x = 1350;
		data->size_y = 900;
	}	
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
	data->start_y = data->size_y / 10;
}

void	data_init(t_data *data, char *av1)
{
	int		fd;
	int		i;
	char	*str;

	i = -1;
	fd = open(av1, O_RDONLY);
	if (fd == -1)
		return ;
	data->nbr_lines = 0;
	while (++i == data->nbr_lines)
	{
		str = get_next_line(fd);
		if (str != NULL)
			data->nbr_lines++;
		free(str);
	}
	close (fd);
	data->nbr_col = 0;
	data->line = (int **)malloc(sizeof(int *) * data->nbr_lines);
	if (!data->line)
		return ;
	ft_parse(av1, data);
	data_init2(data);
	fdf(data);
	ft_free(data->line);
}
