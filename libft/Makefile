NAME	:=	libft.a
SRCS	=	ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
			ft_memccpy.c ft_strlcpy.c ft_strlen.c ft_strdup.c ft_strlcat.c\
			ft_strncmp.c ft_strmapi.c ft_substr.c ft_strjoin.c ft_strtrim.c\
			ft_strrchr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
			ft_isprint.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c\
			ft_putendl_fd.c ft_bzero.c ft_calloc.c ft_atoi.c ft_strchr.c\
			ft_toupper.c ft_tolower.c ft_split.c ft_itoa.c ft_strnstr.c
OBJS	=	$(SRCS:.c=.o)
BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
			ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_isset_bonus.c\
			ft_memalloc_bonus.c ft_memdel_bonus.c ft_strnew_bonus.c
BOBJS	=	$(BONUS:.c=.o)
HEADER	=	libft.h

CC 		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
OPTIONS = 	ar rcs
RM		=	rm -f

ifdef WITH_BONUS
OBJ_FILES = $(OBJS) ${BOBJS}
else
OBJ_FILES = $(OBJS)
endif

all:		$(NAME)

$(NAME):	$(OBJ_FILES)
			$(OPTIONS) $(NAME) $(OBJ_FILES)

%.o: %.c $(HEADER)
			$(CC) -c $(CFLAGS) -o $@ $<
			
bonus:
		$(MAKE) WITH_BONUS=1 all
			
clean:
			$(RM) $(OBJS) ${BOBJS}

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re bonus %.o
