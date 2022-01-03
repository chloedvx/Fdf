#	ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct s_list
{
	int				x;
	int				y;
	struct s_list	*next;
} t_list;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
} t_data;

int		ft_atoi(const char *str);
void	ft_matrice(int **line, void *data);
int     *ft_to_int(char *str, int nbr_int);
void	ft_display(int **line);
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
