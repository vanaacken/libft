# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: niels <niels@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/28 11:25:42 by niels         #+#    #+#                  #
#    Updated: 2020/11/28 11:59:33 by niels         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
SRC_PRINTF	=	ft_printf.c \
				check_fields.c \
				format_arg.c \
				init_struct.c \
				arg_char.c \
				arg_digit.c
SRC_LIBFT	=	libft/ft_atoi.c \
				libft/ft_itoa.c \
				libft/ft_strdup.c \
				libft/ft_strjoin.c \
				libft/ft_strlen.c \
				libft/ft_substr.c \
				libft/ft_itoa_base.c \
				libft/ft_memset.c \
				libft/ft_memmove.c
OBJ_PRINTF	=	$(SRC_PRINTF:.c=.o)
OBJ_LIBFT	=	$(SRC_LIBFT:.c=.o)
OBJ			=	$(OBJ_PRINTF) $(OBJ_LIBFT)
CC			=	gcc
RM			=	rm -f
HEADER		=	ft_printf.h
CFLAGS		=	-Wall -Wextra -Werror
IFLAGS		=	-Iinc
FLAGS		=	$(CFLAGS) $(IFLAGS)
OPTIONS		=	ar rsc

all:		$(NAME)
 
$(NAME):	$(OBJ)
			$(OPTIONS) $(NAME) $(OBJ)

%.o:		%.c $(HEADER)
			$(CC) -c $(FLAGS) -o $@ $<

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re