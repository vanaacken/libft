/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 17:53:29 by niels         #+#    #+#                 */
/*   Updated: 2020/11/10 18:00:20 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  32
# endif

int					get_next_line(int fd, char **line);
int					newline_isset(char *s);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(const char *s1, const char *s2);

#endif
