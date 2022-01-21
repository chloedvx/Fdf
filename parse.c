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

int	line_size(char *str)
{
	int	size;
	int	i;
	
	i = 0;
	size = 0;
	if (!str)
		return (0);
	while(str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] == 32)	
			size++;
		i++;
	}
	return (size);
}

int	size_int(int nb)
{
	int	size;

	size = 0;
	if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}

int	*ft_to_int(char *str, int nbr_int)
{
	int	i;
	int	j;
	int	*tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(int) * nbr_int);
	while (nbr_int > 0 && str[j])
	{
		while (str[j] == 32)
			j++;
		tab[i] = ft_atoi((const char *)&str[j]);
	//	printf("%d, ", tab[i]);
		j += size_int(tab[i]);
		i++;
		nbr_int--;
	}
	//printf("\n");
	return (tab);
}

int	**ft_parse(char *path, t_data *data)
{
	int		i;
	int		fd;
	char	*str;
	int		**tmp;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Cannot read file.", 17);
		return (0);
	}
	tmp = malloc(sizeof(int *) * data->nbr_lines);
	while ((str = get_next_line(fd)) != NULL)
	{
		tmp[i] = ft_to_int(str, data->nbr_col);
		i++;
		free(str);
		str = NULL;
	}
	close(fd);
	return (tmp);
}
