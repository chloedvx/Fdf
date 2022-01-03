#include "fdf.h"

int	line_size(char *str)
{
	int	size;
	int	i;
	
	i = 0;
	size = 0;
	while(str[i] != '\n')
	{
		if ((str[i] > 47 && str[i] < 58) && str[i + 1] == 32)
			size++;
		i++;
	}
	return (size + 1);
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
		printf("%d  ", tab[i]);
		j += size_int(tab[i]);
		i++;
		nbr_int--;
	}
	printf("\n");
	return (tab);
}

int	**ft_parse(char *path)
{
	int		i;
	int		fd;
	char	*str;
	int		nb_lignes;
	int		**tmp;

	fd = 0;
	i = 0;
	nb_lignes = 30;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Cannot read file.", 17);
		return (0);
	}
	tmp = malloc(sizeof(int *) * nb_lignes);
	while ((str = get_next_line(fd)) != NULL)
	{
		tmp[i] = ft_to_int(str, line_size(str));
		i++;
		free(str);
		str = NULL;
	}
	close(fd);
	return (tmp);
}

void	ft_display(int	**line) // temporaire 
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while(j < 18)
		{
			printf("%d, ", line[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	isometric(float *x,float *y)
{

	float	pre_x;
	float	pre_y;

	*x = pre_x - pre_y;
	*y = (pre_x + pre_y) / 2;
}
/*
void	ft_matrice(int **line, void *data)
{
	int	i;
	int	j;
	int	x;
	int	y;
	
	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i + 10, j + 10, 0x8b008b);
			j++;
		}
		i++;
	}
}*/
