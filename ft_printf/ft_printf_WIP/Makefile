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
				ft_isset.c \
				ft_calloc.c \
				ft_memmove.c 
LIBFT_OBJ   =   $(LIBFT_SRC:%.c=%.o)
PRINTF_PATH =   ./
PRINTF_SRC  =   ft_printf.c \
				init_struct.c
PRINTF_OBJ  =   $(PRINTF_SRC:%.c=%.o)
PRINTF_OP   = $(PRINTF_OBJ:%=$(PRINTF_PATH)%)
LIBFT_OP    = $(LIBFT_OBJ:%=$(LIBFT_PATH)%)
O_FILES     = $(PRINTF_OP) $(LIBFT_OP)
CC          =   gcc
RM          =   rm -f
HEADER      =   libftprintf.h
WFLAGS      =   -Wall -Werror -Wextra
IFLAGS      =   -Iinc
FLAGS       =   $(WFLAGS) $(IFLAGS)
#COLOR CODES
#red
R   = \x1b[38;5;196m
#orange
O   = \x1b[38;5;208m
#yellow
Y   = \x1b[38;5;3m
#green
G   = \x1b[38;5;83m
#blue
B   = \x1b[38;5;21m
#purple
P   = \x1b[38;5;129m
#pink
PI  = \x1b[38;5;205m
#light pink
PL  = \x1b[38;5;219m
#grey
GR  = \x1b[38;5;244m
#dark grey
V   = \x1b[38;5;239m
#reset to white
RES = \x1b[0m
#random variables for make test
FIRST   = "\"\x1b[38;5;205m|\x1b[38;5;219m%4d\x1b[38;5;205m|\n\""
REAL    = \x1b[38;5;205m|\x1b[38;5;219mREAL\x1b[38;5;205m|\x1b[38;5;219m
MINE    = \x1b[38;5;205m|\x1b[38;5;219mMINE\x1b[38;5;205m|\x1b[38;5;219m
STRING  = $(R)Your forgot %s! %s...
ARG     = \"input, dumbass\", \"Give input with STRING and ARG\"
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
test:
	@clear
	@echo "$(V)Creating a.out...\n$(RES)"
	@gcc $(PRINTF_OP) $(LIBFT_OP) main.c $(FLAGS) \
		-D REAL="\"$(REAL)$(STRING)\", $(ARG)" \
		-D MINE="\"$(MINE)$(STRING)\", $(ARG)" \
		-D FIRST=$(FIRST) -fsanitize=address
	@echo "$(PL)Comparing output of $(P)\"$(STRING)\", $(ARG)"
	@echo "$(PI).---#|=============|#---.$(RES)"
	@./a.out
	@echo "$(PI)'---#|=============|#---'$(RES)"
	@rm a.out
.PHONY: all clean fclean re bonu