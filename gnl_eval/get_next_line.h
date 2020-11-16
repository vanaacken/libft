/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 14:05:09 by niels         #+#    #+#                 */
/*   Updated: 2020/11/16 13:27:22 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

int		get_next_line(int fd, char **line);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		newline_isset(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif
