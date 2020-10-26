NAME	=	libft.a
SRCS	=	*.c
OBJS	=	${SRCS:.c=.o}
HEADER	=	libft.h

CC 		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -c
OPTIONS = 	ar rc
RM		=	rm -f

${SRCS} = ${filter-out test.c, ${SRCS}}

.PHONY: all clean fclean re bonus

all:		${NAME}

${NAME}:
			${CC} ${CFLAGS} ${SRCS} 
			${OPTIONS} ${NAME} ${OBJS} 

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

bonus:


run: 

