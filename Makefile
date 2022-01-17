SRCS = ft_split.c get_next_line.c get_next_line_utils.c init.c main.c parse.c utils.c

NAME = fdf

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIB_DIR =  /usr/local/lib

OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${CC} -L ${LIB_DIR} -lmlx -framework OpenGL -framework AppKit ${OBJS} -o ${NAME} -g3 -fsanitize=address -D BUFFER_SIZE=20

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all
