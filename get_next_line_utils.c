/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:19:38 by cdaveux           #+#    #+#             */
/*   Updated: 2021/12/09 13:45:07 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (dest = ft_strdup(s2));
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	free(s1);
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned long	i;
	char			*dest;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < (int)len)
		len = ft_strlen(s);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	if ((int)start < ft_strlen(s))
	{
		while (i < len && s[start + i])
		{
			dest[i] = s[start + i];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	while (j < i)
	{
		dest[j] = s1[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strchr(char *s, int c)
{
	int	j;

	j = 0;
	while (s[j] || s[j] == (char)c)
	{
		if (s[j] == (char)c)
			return ((char *)&s[j + 1]);
		j++;
	}
	return (0);
}
