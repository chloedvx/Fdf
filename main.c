/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:49:43 by cdaveux           #+#    #+#             */
/*   Updated: 2022/02/08 14:19:22 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_expose_hook(t_data *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->size_x, data->size_y);
	if (!data->img_ptr)
		return (-1);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->addr)
		return (-1);
	vertical_lines(data);
	horiz_lines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	return (0);
}

int	ft_key_hook(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	else if (key == 24)
		data->gap += 2;
	else if (key == 27)
		data->gap -= 2;
	else if (key == 123)
		data->start_x += 20;
	else if (key == 124)
		data->start_x -= 20;
	else if (key == 126)
		data->start_y += 20;
	else if (key == 125)
		data->start_y -= 20;
	ft_expose_hook(data);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x < data->size_x && x > 0) && (y < data->size_y && y > 0))
	{
		dst = data->addr + (y * data->line_length + x
				*(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	fdf(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (-1);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->size_x, data->size_y, "Fdf");
	if (!data->win_ptr)
		return (-1);
	mlx_key_hook(data->win_ptr, ft_key_hook, data);
	mlx_expose_hook(data->win_ptr, ft_expose_hook, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	system("leaks executablename");
	if (ac == 2)
	{
		ft_bzero(&data, sizeof(t_data));
		data_init(&data, av[1]);
		ft_bzero(&data, sizeof(t_data));
	}
	else
	{
		ft_putstr("Format is : ./fdf map/path\n");
		return (0);
	}
	return (0);
}
