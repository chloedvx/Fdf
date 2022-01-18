/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:49:43 by cdaveux           #+#    #+#             */
/*   Updated: 2022/01/18 17:24:44 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key_hook(int key, t_data *data) // fonctionne 
{	
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	ft_putnbr(key);
	return (0);
}

int	ft_expose_hook(t_data *data)
{
	//void *mlx_new_image ( void *mlx_ptr, int width, int height );
	//char *mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );
	//int mlx_put_image_to_window ( void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->size_x - 100, data->size_y - 100);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 100, 100);
	return (0);
}

int	fdf(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->size_x, data->size_y, "titre");
	if (!data->win_ptr)
		exit(0);
	mlx_key_hook(data->win_ptr, ft_key_hook, data);
//	mlx_expose_hook(data->win_ptr, ft_expose_hook, data);
	vertical_lines(data);
	horiz_lines(data); 
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		*data;
	t_colors	*colors;

	(void)ac;
	data = data_init(av[1]);
	colors = colors_init();
	fdf(data);
	//free line
	free(data);
	free(colors);
	return (0);
}
