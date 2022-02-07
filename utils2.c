/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:13:08 by cdaveux           #+#    #+#             */
/*   Updated: 2022/01/25 12:13:10 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(int *x, int *y, int z)
{
	int	pre_x;
	int	pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = (pre_x - pre_y) * cos(0.8);
	*y = (pre_x + pre_y) * sin (0.8) - z;
}

int	create_trgb(int z)
{
	if (z < -10)
		return (0 << 16 | 0 << 8 | 120);
	if (z < -5)
		return (0 << 16 | 0 << 8 | 130);
	else if (z < 0)
		return (0 << 16 | 0 << 8 | 153);
	else if (z < 5)
		return (0 << 16 | 0 << 8 | 204);
	else if (z < 10)
		return (0 << 16 | 0 << 8 | 255);
	else if (z < 20)
		return (51 << 16 | 51 << 8 | 255);
	else if (z < 30)
		return (102 << 16 | 102 << 8 | 255);
	else if (z < 40)
		return (110 << 16 | 110 << 8 | 255);
	else if (z < 50)
		return (120 << 16 | 120 << 8 | 255);
	else if (z > 50)
		return (130 << 16 | 130 << 8 | 200);
	return (153 << 16 | 153 << 8 | 255);
}

void	ft_append(t_coord *coord, t_data *data)
{
	coord->x0 += data->start_x;
	coord->y0 += data->start_y;
	coord->x1 += data->start_x;
	coord->y1 += data->start_y;
}

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
