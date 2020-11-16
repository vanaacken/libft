NAME	=	libftprintf.a
SRC_DIR	=	srcs
SRC		=	ft_printf.c

OBJ_DIR	=	
OBJ		=	$(SRC:.c=.o)

HEADER	=	includes
LIBFT	=	libft

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a ./$(NAME)
			@ar -rcs $(NAME) $(OBJ)

%.o: 		%.c
			@$(CC) $(CLFAGS) -I $(HEADER) -o $@ -c $<

clean:		@$(RM) $(OBJS)
			@make clean -C $(LIBFT)

fclean:	clean
		$(RM) $(NAME)
		@make fclean -C $(LIBFT)

re:		fclean all

.PHONY: all clean fclean re


