/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student-codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 16:21:29 by rcappend      #+#    #+#                 */
/*   Updated: 2020/11/28 09:36:25 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> 				// weghalen

int	ret_check(int ret, char **line)
{
	if (ret == -1)
	{
		if (*line)
			free(line);
		return (ret);
	}
	return (ret);
}

int	ft_strjoin(char **line, char *buff)
{
	char	*new;
	char	*index;
	int		newl;
	int		len;
	
	if (ft_strclen(buff, 0) == 0)
		return (0);
	len = ft_strclen(buff, '\n') + 1;
	if (*line)
		len += ft_strclen(*line, 0);
	new = (char *)malloc(len);
	if (!new)
		return (-1);
	index = ft_memccpy(new, *line, 0);
	index = ft_memccpy(index, buff, '\n');
	*line = new;
	newl = ft_strchr(buff, '\n') == NULL ? 0 : 1;
	ft_memmove(buff, index);
	return (newl);
}

int	get_next_line(int fd, char **line)
{
	static char		buff[BUFFER_SIZE + 1];
	int				bytes;
	int				ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (ret_check(-1, line));
	*line = 0;
	ret = ft_strjoin(line, buff);
	if (ret)
		return (ret_check(ret, line));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (-1);
		ret = ft_strjoin(line, buff);
		if (ret)
			return (ret);
	}
	return (0);
}
