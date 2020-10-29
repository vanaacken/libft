NAME	:=	libft.a
BNAME	:=	libft.a
SRCS	=	ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
			ft_memccpy.c ft_strlcpy.c ft_strlen.c ft_strdup.c ft_strlcat.c\
			ft_strncmp.c ft_strmapi.c ft_substr.c ft_strjoin.c ft_strtrim.c\
			ft_strrchr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
			ft_isprint.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c\
			ft_putendl_fd.c ft_bzero.c ft_calloc.c ft_atoi.c ft_strchr.c\
			ft_toupper.c ft_tolower.c ft_split.c ft_itoa.c ft_strnstr.c
OBJS	=	$(SRCS:.c=.o)
BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_isset_bonus.c\
			ft_memalloc_bonus.c ft_memdel_bonus.c ft_strnew_bonus.c
BOBJS	=	$(BONUS:.c=.o)
HEADER	=	libft.h

CC 		=	clang
CFLAGS	=	-Wall -Werror -Wextra -c
OPTIONS = 	ar rc
RM		=	rm -f

all:		$(NAME)

$(NAME):
			$(CC) $(CFLAGS) $(SRCS)
			$(OPTIONS) $(NAME) $(OBJS)

bonus:
			$(CC) $(CFLAGS) $(SRCS) $(BONUS)
			$(OPTIONS) $(BNAME) $(OBJS) $(BOBJS) 
			touch bonus
clean:
			$(RM) $(OBJS) ${BOBJS} bonus

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
