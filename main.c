/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:49:43 by cdaveux           #+#    #+#             */
/*   Updated: 2022/01/19 14:49:48 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key_hook(int key, t_data *data)
{	
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	return (0);
}

/*int	ft_expose_hook(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	return (0);
}*/

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if ((x < img->x && x > 0) && (y < img->y && y > 0))
	{
		dst = img->addr + (y * img->line_length + x
				*(img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	fdf(t_data *data)
{
	t_img	*img;

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->size_x, data->size_y, "Fdf");
	if (!data->win_ptr)
		exit(EXIT_FAILURE);
	img = img_init(data);
	mlx_key_hook(data->win_ptr, ft_key_hook, data);
//	mlx_expose_hook(data->win_ptr, ft_expose_hook, data);
	vertical_lines(data, img);
	horiz_lines(data, img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img_ptr, 0, 0);
	mlx_loop(data->mlx_ptr);
	free(img);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		*data;

	(void)ac;
	data = data_init(av[1]);
	fdf(data);
	ft_free(data->line);
	free(data);
	return (0);
}
