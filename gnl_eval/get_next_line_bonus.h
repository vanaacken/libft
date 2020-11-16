/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 13:06:40 by nvan-aac      #+#    #+#                 */
/*   Updated: 2020/11/16 13:27:32 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_FD 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

int		get_next_line(int fd, char **line);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		newline_isset(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif
