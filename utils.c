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
