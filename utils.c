/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:13:21 by cdaveux           #+#    #+#             */
/*   Updated: 2022/02/08 14:11:16 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_free(t_data *data)
{
	int	i;

	i = -1;
	while (data->line[++i])
		free(data->line[i]);
	free(data->line);
}

void	free_dest(char **dest)
{
	int	i;

	i = -1;
	while (dest[++i])
		free(dest[i]);
	free(dest);
}

int	ft_atoi(const char *str)
{
	int long	nb;
	int			sign;
	int			i;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb *= sign;
	return (nb);
}

void	ft_swap(t_coord *coord)
{
	int	x;
	int	y;

	x = coord->x0;
	coord->x0 = coord->x1;
	coord->x1 = x;
	y = coord->y0;
	coord->y0 = coord->y1;
	coord->y1 = y;
}
