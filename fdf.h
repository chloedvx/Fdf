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
	int	x;
	int	y;
	int	pxl_x;
	int	pxl_y;
	int	space_x;
	int	space_y;
	int	iso_x;//float ??
	int	iso_y;
} t_coord;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		nbr_lines;
} t_data;

t_coord	*ft_coord_init(void);
t_data	*data_init(char *av1);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		nb_lines(int fd);
int		ft_atoi(const char *str);
int     *ft_to_int(char *str, int nbr_int);
int		**ft_parse(char *path);
char	*get_next_line(int fd);
char	*get_next_line2(char **temp, int fd);
int		ft_is_nl(char *temp);
int		ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);

# endif
