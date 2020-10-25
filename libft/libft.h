#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void			*ft_memset(void *b, int c, size_t len);

void			ft_bzero(void *s, size_t n);

void			*ft_memcpy(void *dst, const void *src, size_t n);

void			*ft_memmove(void *dst, const void *src, size_t len);

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

size_t			ft_strlen(char *str);

char			*ft_strdup(char *src);

char			*ft_strcat(char *dest, char *src);

size_t			ft_strlcat(char *dest, char *src, size_t size);

char			*ft_strstr(char *str, char *to_find);

int				ft_strcmp(char *s1, char *s2);

int				ft_strncmp(char *s1, char *s2, unsigned int n);

int				ft_atoi(char *str);

int				ft_isalpha(int c);

int				ft_isdigit(int c);

int				ft_isalnum(int c);

int				ft_isascii(int c);

int				ft_isprint(int c);

int				ft_toupper(int c);

int				ft_tolower(int c);

void			ft_putchar(char c);

void			ft_putstr(const char *c);

void			ft_putnbr(int n);

void			ft_putchar_fd(char c, int fd);

void			ft_putstr_fd(const char *c, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putendl(char const *c);

void			ft_putendl_fd(char const *c, int fd);

void			*ft_memalloc(size_t size);

void			ft_memdel(void **ap);

char			*ft_strnew(size_t size);

void			ft_strdel(char **as);

void			ft_strclr(char *s);

void			ft_striter(char *s, void (*f)(char *));

void			ft_striteri(char *s, void (*f)(unsigned int, char *));

char 			*ft_strmap(char const *s, char(*f)(char));

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int				ft_strequ(char const *s1, char const *s2);

int				ft_strnequ(char const *s1, char const *s2, size_t n);

#endif