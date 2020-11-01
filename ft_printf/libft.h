/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:58:56 by niels         #+#    #+#                 */
/*   Updated: 2020/10/30 12:25:04 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int					ft_printf(char const *format, ...);

void				*ft_memset(void *b, int c, size_t len);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t				ft_strlen(char *str);

char				*ft_strdup(char *src);

char				*ft_strcat(char *dest, char *src);

size_t				ft_strlcat(char *dest, char *src, size_t size);

char				*ft_strstr(char *str, char *to_find);

int					ft_strncmp(char *s1, char *s2, unsigned int n);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char(*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_substr(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s1, char const *set);

char				*ft_strrchr(const char *s, int c);

char				*ft_strchr(const char *s, int c);

char				*ft_strnstr(const char *hay, const char *n, size_t len);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_isset(char c, char *set);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(const char *c, int fd);

void				ft_putnbr_fd(int n, int fd);

void				ft_putendl_fd(char const *c, int fd);

void				ft_bzero(void *s, size_t n);

void				*ft_calloc(size_t count, size_t size);

int					ft_atoi(char *str);

int					ft_toupper(int c);

int					ft_tolower(int c);

char				**ft_split(char const *s, char c);

char				*ft_itoa(int n);

#endif
