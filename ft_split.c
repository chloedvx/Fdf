/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:42:20 by cdaveux           #+#    #+#             */
/*   Updated: 2021/11/30 16:03:41 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_c(char const s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	nbr_mots(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{	
		if (i > 0 && is_in_c(s[i], c) == 1 && is_in_c(s[i - 1], c) == 0)
			count++;
		i++;
	}
	if (i > 0 && is_in_c(s[i - 1], c) == 0)
		count++;
	return (count);
}

static int	len_mot(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] && is_in_c(s[i], c) == 0)
	{
		len++;
		i++;
	}
	return (len);
}

static char	*ft_sdup(char *dest, char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = len_mot(&s[i], c);
	dest = malloc(sizeof(char) * (len_mot(&s[i], c) + 2));
	if (!dest)
	{
		free(dest);
		return (NULL);
	}
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	int		nb_mots;
	char	**dest;

	i = 0;
	k = 0;
	nb_mots = nbr_mots(s, c);
	dest = malloc(sizeof(char *) * (nb_mots + 1));
	if (!dest)
	{
		free(dest);
		return (NULL);
	}
	while (i < nb_mots)
	{
		while (is_in_c(s[k], c) == 1)
			k++;
		dest[i] = ft_sdup(dest[i], &s[k], c);
		k += len_mot(&s[k], c);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
