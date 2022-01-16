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
