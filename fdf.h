/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:49:51 by cdaveux           #+#    #+#             */
/*   Updated: 2022/01/18 17:24:50 by cdaveux          ###   ########.fr       */
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
} t_coord;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		**line;
	int		nbr_lines;
	int		nbr_col;
	int		size_x;
	int		size_y;
	int		gap_x;
	int		gap_y;
	int		start_x;
	int		start_y;
} t_data;

typedef struct s_colors
{
	int	R;
	int	G;
	int	B;
} t_colors;

t_colors	*colors_init(void);
t_coord		*coord_init(t_data *data);
t_data		*data_init(char *av1);
void	vertical_lines(t_data *data);
void    horiz_lines(t_data *data);
void	isometric(int *x, int *y, int z);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		line_size(char *str);
int		ft_atoi(const char *str);
int     *ft_to_int(char *str, int nbr_int);
int		**ft_parse(char *path, t_data *data);
char	*get_next_line(int fd);
char	*get_next_line2(char **temp, int fd);
int		ft_is_nl(char *temp);
int		ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);

# endif
