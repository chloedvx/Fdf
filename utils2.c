/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:13:08 by cdaveux           #+#    #+#             */
/*   Updated: 2022/02/08 14:19:36 by cdaveux          ###   ########.fr       */
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
		return (128 << 16 | 0 << 8 | 0);
	else if (z < -5)
		return (139 << 16 | 0 << 8 | 0);
	else if (z < -3)
		return (165 << 16 | 42 << 8 | 42);
	else if (z < 0)
		return (178 << 16 | 34 << 8 | 34);
	else if (z < 5)
		return (220 << 16 | 20 << 8 | 60);
	else if (z < 10)
		return (255 << 16 | 0 << 8 | 0);
	else if (z < 20)
		return (255 << 16 | 99 << 8 | 71);
	else if (z < 30)
		return (255 << 16 | 127 << 8 | 80);
	else if (z < 40)
		return (205 << 16 | 92 << 8 | 92);
	else if (z < 50)
		return (240 << 16 | 128 << 8 | 128);
	else if (z > 50)
		return (233 << 16 | 150 << 8 | 122);
	return (0);
}

void	ft_append(t_coord *coord, t_data *data)
{
	coord->x0 += data->start_x;
	coord->y0 += data->start_y;
	coord->x1 += data->start_x;
	coord->y1 += data->start_y;
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
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
