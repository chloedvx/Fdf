/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:49:51 by cdaveux           #+#    #+#             */
/*   Updated: 2022/01/19 14:42:55 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct s_coord
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}	t_coord;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		**line;
	int		nbr_lines;
	int		nbr_col;
	int		size_x;
	int		size_y;
	int		gap;
	int		start_x;
	int		start_y;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	int		r;
	int		g;
	int		b;
	int		rgb;
}	t_data;

/*typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	void	*mlx_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	int		r;
	int		g;
	int		b;
	int		rgb;
}	t_img;*/

t_coord	*coord_init(t_data *data);
void	data_init(t_data *data, char *av1);
void	ft_free(int **line);
int		create_trgb(int r, int g, int b);
void	ft_swap(t_coord *coord);
int		ft_diff(int x0, int x1);
void	ft_error(char *str);
void	ft_append(t_coord *coord, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	vertical_lines(t_data *data);
void	horiz_lines(t_data *data);
void	isometric(int *x, int *y, int z);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(const char *str);
void	ft_parse(char *path, t_data *data);
char	*get_next_line(int fd);
char	*get_next_line2(char **temp, int fd);
int		ft_is_nl(char *temp);
int		ft_strlen(char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);

#endif
