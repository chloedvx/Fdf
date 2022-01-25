/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:13:21 by cdaveux           #+#    #+#             */
/*   Updated: 2022/01/25 12:13:26 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	nb1;

	nb1 = nb;
	if (nb1 == -2147483647)
		write(1, "-2147483647", 11);
	else
	{
		if (nb1 < 0)
		{
			nb1 *= -1;
			write (1, "-", 1);
		}
		if (nb1 > 9)
			ft_putnbr((nb1 / 10));
		ft_putchar(nb1 % 10 + 48);
	}
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

int	ft_diff(int x0, int x1)
{
	int	dx;

	dx = x1 - x0;
	if (dx < 0)
		dx *= -1;
	return (dx);
}
