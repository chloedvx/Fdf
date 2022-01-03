/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:18:06 by cdaveux           #+#    #+#             */
/*   Updated: 2021/12/09 13:48:06 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_is_nl(char *temp)
{
	int	i;

	i = 0;
	if (!temp)
		return (-1);
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line2(char **temp, int fd)
{
	int		ret;
	char	*buff;

	ret = 1;
	while (ret && ft_is_nl(temp[fd]) < 0)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[ret] = 0;
		temp[fd] = ft_strjoin(temp[fd], buff);
		free(buff);
	}
	return (temp[fd]);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	char		*tmp;
	static char	*temp[1024];

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp[fd] = get_next_line2(temp, fd);
	if (!temp[fd])
		return (NULL);
	if (ft_is_nl(temp[fd]) < 0)
		next_line = ft_substr(temp[fd], 0, ft_strlen(temp[fd]));
	else
		next_line = ft_substr(temp[fd], 0, ft_is_nl(temp[fd]) + 1);
	tmp = ft_strdup(ft_strchr(temp[fd], '\n'));
	free(temp[fd]);
	temp[fd] = ft_strdup(tmp);
	free(tmp);
	if (next_line[0] == 0)
	{
		free(temp[fd]);
		free(next_line);
		next_line = NULL;
	}
	return (next_line);
}
