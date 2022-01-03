#include "fdf.h"
#include <math.h>

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

int	deal_key(int key, void *data) // fonctionne 
{	
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, 10, 10, 255);
	ft_putnbr(key);
	return (0);
}

int	main(void)
{
	t_data	*data;
	int		**line;

	int		i;

	i = 50;
	line = ft_parse("test_maps/10-2.fdf");
//	printf("%d\n", line[2][2]);
//	ft_display(line);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "titre");
	mlx_key_hook(data.win_ptr, deal_key, &data);
//	ft_matrice(line, data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
