/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:35:57 by cdaveux           #+#    #+#             */
/*   Updated: 2021/11/29 12:11:46 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
