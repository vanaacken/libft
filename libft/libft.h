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

// REQUIRED -> BUILD -> TEST -> DONE
// mem
void			*ft_memset(void *b, int c, size_t len); // REQ DONE

void			*ft_memcpy(void *dst, const void *src, size_t n); // REQ TEST

void			*ft_memmove(void *dst, const void *src, size_t len); // REQ TEST

void			*ft_memchr(const void *s, int c, size_t n); // REQ TEST

int				ft_memcmp(const void *s1, const void *s2, size_t n); // REQ TEST

void			*ft_memalloc(size_t size); // TEST

void			ft_memdel(void **ap); // TEST


// str

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t			ft_strlen(char *str); // REQ TEST

char			*ft_strdup(char *src); // REQ TEST

char			*ft_strcat(char *dest, char *src); // TEST

size_t			ft_strlcat(char *dest, char *src, size_t size); // REQ TEST

char			*ft_strstr(char *str, char *to_find); // REQ TEST

int				ft_strcmp(char *s1, char *s2); // TEST

int				ft_strncmp(char *s1, char *s2, unsigned int n); // REQ TEST

char			*ft_strnew(size_t size); // TEST

void			ft_strdel(char **as); // TEST

void			ft_strclr(char *s); // TEST

void			ft_striter(char *s, void (*f)(char *)); // TEST

void			ft_striteri(char *s, void (*f)(unsigned int, char *)); // REQ TEST

char 			*ft_strmap(char const *s, char(*f)(char)); // TEST

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char)); // REQ TEST

int				ft_strequ(char const *s1, char const *s2); // TEST

int				ft_strnequ(char const *s1, char const *s2, size_t n); // TEST

char			*ft_substr(char const *s, unsigned int start, size_t len); // REQ TEST

char			*ft_strjoin(char const *s1, char const *s2); // REQ BUILD

char			*ft_strtrim(char const *s1, char const *set); // REQ BUILD

// is

int				ft_isalpha(int c); // REQ TEST

int				ft_isdigit(int c); // REQ TEST

int				ft_isalnum(int c); // REQ TEST

int				ft_isascii(int c); // REQ TEST

int				ft_isprint(int c); // REQ TEST

int				ft_isset(char c, char *set); // DONE

// put

void			ft_putchar(char c); // TEST

void			ft_putstr(const char *c); // TEST

void			ft_putnbr(int n); // TEST

void			ft_putchar_fd(char c, int fd); // REQ TEST

void			ft_putstr_fd(const char *c, int fd); // REQ TEST

void			ft_putnbr_fd(int n, int fd); // REQ TEST

void			ft_putendl(char const *c); // TEST

void			ft_putendl_fd(char const *c, int fd); // REQ TEST



// list


// other


void			ft_bzero(void *s, size_t n); // REQ TEST

void			*calloc(size_t count, size_t size); // REQ TEST

int				ft_atoi(char *str); // REQ TEST

int				ft_toupper(int c); // REQ TEST

int				ft_tolower(int c); //REQ TEST

char			**ft_split(char const *s, char c); // REQ BUILD

char			*ft_itoa(int n); // REQ BUILD

#endif