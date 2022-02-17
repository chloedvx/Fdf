SRCS = ft_split.c get_next_line.c get_next_line_utils.c init.c main.c parse.c utils.c lines.c utils2.c

NAME = fdf

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx

RM = rm -f

OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${CC} ${OBJS} -lmlx -framework OpenGL -framework AppKit -o ${NAME} 

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all
