/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student-codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 16:21:34 by rcappend      #+#    #+#                 */
/*   Updated: 2020/11/27 15:14:44 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>	// vervangen met stddef?
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

typedef enum
{
	FALSE,
	TRUE
}	t_bool;

int		get_next_line(int fd, char **line);

size_t	ft_strclen(const char *str, int c);

char	*ft_strchr(const char *s, int c);

char	*ft_memccpy(char *dst, const char *src, int c);

void	ft_memmove(char *dst, const char *src);

#endif