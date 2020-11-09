/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 17:23:44 by niels         #+#    #+#                 */
/*   Updated: 2020/11/09 15:47:33 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
BUFFER_SIZE = 32;
#endif

int					get_next_line(int fd, char **line);
int					newline_isset(char *s);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(const char *s1, const char *s2);

#endif
