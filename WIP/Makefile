SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memccpy.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c
OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c
BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)
 
$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus


# other





MAKE := $(MAKE) --no-print-directory
NAME := libft.a
CC ?= gcc

CFLAGS := -Wall -Werror -Wextra -Ofast

include config/config.mk

OBJDIR := build
SRCDIR := src
HEADIR := includes

SRCS := $(shell find $(SRCDIR) -type f -name "*.c" $(DISABLED))
OBJS := $(SRCS:%=$(OBJDIR)/%.o)
DEPS := $(SRCS:%=$(OBJDIR)/%.d)

HEAD := $(shell find $(SRCDIR) -name "*.h" -and ! -name "*_priv.h")
HEAD := $(subst $(SRCDIR),$(HEADIR),$(HEAD))
HEAD := $(HEAD) $(HEADIR)/ft_version.h

LIBS :=
LIBINCS := $(foreach lib,$(LIBS),-I$(dir $(lib))includes)

.PHONY: all re clean fclean debug $(LIBS) _$(NAME)

all: _$(NAME) Makefile

_$(NAME): $(LIBS) Makefile
	@$(MAKE) $(NAME)

$(NAME): $(HEAD) $(OBJS) Makefile
	@ar rc $@ $(OBJS) $(LIBS)
	@ranlib $@
	@echo "Compiled $(@) version $(VERSION)"

$(OBJDIR) $(HEADIR):
	@mkdir -p $@

-include $(DEPS)

$(OBJDIR)/%.c.o: %.c Makefile $(HEADIR)/ft_version.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(HEADIR) -MMD -MP -c $< -o $@ $(LIBINCS)

$(HEADIR)/%.h: Makefile
	@mkdir -p $(dir $@)
	cp $(subst $(HEADIR),$(SRCDIR),$@) $@

$(HEADIR)/ft_version.h: Makefile $(SRCDIR)/ft_version.h.in
	@echo Configuring $@
	@mkdir -p $(dir $@)
	@cp $(SRCDIR)/ft_version.h.in $@
	@sed -i 's/@VERSION@/$(VERSION)/g' $@
	@sed -i 's/@VERSION_MAJOR@/$(VERSION_MAJOR)/g' $@
	@sed -i 's/@VERSION_MINOR@/$(VERSION_MINOR)/g' $@
	@sed -i 's/@VERSION_PATCH@/$(VERSION_PATCH)/g' $@

$(LIBS): Makefile
	@$(MAKE) -C $(dir $@) $(MAKECMDGOALS)

clean:
	@$(foreach dep, $(LIBS), $(MAKE) -C $(dir $(dep)) clean;)
	rm -f $(OBJS)
	rm -f $(DEPS)
	rm -rf $(OBJDIR)

fclean: clean
	@$(foreach dep, $(LIBS), $(MAKE) -C $(dir $(dep)) fclean;)
	rm -f $(NAME)
	rm -rf $(HEADIR)

re: fclean
	@$(MAKE) all

debug:
	@$(MAKE) all CFLAGS="$(filter-out -Ofast,$(CFLAGS)) -g -O0"

ci:
	@$(MAKE) -C tests ci
