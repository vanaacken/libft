/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 14:01:24 by niels         #+#    #+#                 */
/*   Updated: 2020/11/16 13:18:40 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	free_save(char *s)
{
	if (s)
		free(s);
	return (-1);
}

static char	*split_line(char **line, char *saved_line)
{
	char			*new_save;
	unsigned int	i;

	i = 0;
	while (saved_line[i] != '\n' && saved_line[i])
		i++;
	*line = ft_substr(saved_line, 0, i);
	if (!*line)
	{
		free(saved_line);
		return (NULL);
	}
	new_save = ft_substr(saved_line, i + 1, ft_strlen(saved_line + i + 1));
	free(saved_line);
	if (!new_save)
		return (NULL);
	return (new_save);
}

int			get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*saved_line;
	int			bytes_read;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (free_save(saved_line));
	bytes_read = 1;
	while (newline_isset(saved_line) == 0 && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_save(saved_line));
		buffer[bytes_read] = '\0';
		saved_line = ft_strjoin(saved_line, buffer);
		if (!saved_line)
			return (-1);
	}
	saved_line = split_line(line, saved_line);
	if (!saved_line)
		return (-1);
	if (bytes_read == 0)
		return (0);
	return (1);
}
