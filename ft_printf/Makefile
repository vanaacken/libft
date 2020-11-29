# put both header files in a folder called 'inc' (not includes)
NAME        =   libftprintf.a
LIBFT_PATH  =   ./libft/
LIBFT_SRC   =   ft_atoi.c \
                ft_isdigit.c \
                ft_itoa.c \
                ft_putchar_fd.c \
                ft_putnbr_fd.c \
                ft_putstr_fd.c \
                ft_strdup.c \
                ft_strjoin.c \
                ft_strlen.c \
                ft_substr.c \
                ft_tolower.c \
                ft_toupper.c \
                ft_itoa_base.c \
				ft_memset.c \
				ft_memmove.c
LIBFT_OBJ   =   $(LIBFT_SRC:%.c=%.o)
PRINTF_PATH =   ./
PRINTF_SRC  =   ft_printf.c \
                check_fields.c \
                format_arg.c \
                init_struct.c \
                is_char.c \
                is_digit.c
PRINTF_OBJ  =   $(PRINTF_SRC:%.c=%.o)
PRINTF_OP   = $(PRINTF_OBJ:%=$(PRINTF_PATH)%)
LIBFT_OP    = $(LIBFT_OBJ:%=$(LIBFT_PATH)%)
O_FILES     = $(PRINTF_OP) $(LIBFT_OP)
CC          =   gcc
RM          =   rm -f
HEADER      =   libftprintf.h
CFLAGS      =   -Wall -Werror -Wextra
IFLAGS      =   -Iinc
FLAGS       =   $(CFLAGS) $(IFLAGS)

all:        $(NAME)
$(NAME):    $(O_FILES)
		ar rs $(NAME) $(O_FILES)
%.o: %.c    $(HEADER)
		$(CC) -c $(FLAGS) -o $@ $<
clean:
		$(RM) $(O_FILES)
fclean: clean
		$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re bonu