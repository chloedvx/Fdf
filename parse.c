/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:49:58 by cdaveux           #+#    #+#             */
/*   Updated: 2022/01/19 14:46:04 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*ft_to_int(char *str, t_data *data)
{
	int		i;
	char	**arg;
	int		*tab;

	i = -1;
	arg = ft_split((const char *)str, 32);
	if (!arg)
		return (NULL);
	while (arg[++i])
		data->nbr_col = i;
	tab = malloc(sizeof(int) * data->nbr_col);
	i = -1;
	while (arg[++i])
	{
		tab[i] = ft_atoi((const char *)arg[i]);
		free(arg[i]);
	}
	free(arg);
	return (tab);
}

void	ft_parse(char *path, t_data *data)
{
	int		i;
	int		fd;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error("Cannot access file");
	while (j == i)
	{
		str = get_next_line(fd);
		if (str != NULL)
		{
			data->line[i] = ft_to_int(str, data);
			if (!data->line[i])
				break ;
			i++;
		}
		j++;
		free(str);
	}
	free(str);
	close(fd);
}
