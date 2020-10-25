NAME	=	libft.a
SRCS	=	*.c
OBJS	=	${SRCS:.c=.o}
HEADER	=	libft.h

CC 		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -c
OPTIONS = 	ar rc
RM		=	rm -f

.PHONY: all clean fclean re

all:		${NAME}

${NAME}:
			${CC} ${CFLAGS} ${SRCS} 
			${OPTIONS} ${NAME} ${OBJS} 

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all
